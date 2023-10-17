
#include "../include/Game.hpp"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <vector>

#include "../include/Colision.hpp"
#include "../include/Entity.hpp"
#include "../include/Gamestate.hpp"
#include "../include/Generation.hpp"
#include "../include/Obstacle.hpp"
#include "../include/Physics.hpp"
#include "../include/Player.hpp"

Generation Gen;
Physics phy(0.3);
Collision col;
Gamestate score;

Game::Game(int x_dimension, int y_dimension, const std::string title) {
  Window = new sf::RenderWindow(sf::VideoMode(x_dimension, y_dimension),
                                "Game");  // making game window
  std::cout << "Init Complete";
}

void Game::run() {
  auto startTime = std::chrono::high_resolution_clock::now();

  // object creations and generations here

  Player pl1(100.0f, 250.0f, sf::Vector2f(0.8f, 0.8f));
  sf::View view(sf::FloatRect(0, 0, Window->getSize().x, Window->getSize().y));

  std::vector<Object*> blocks(10, nullptr);
  std::cout << "Vector Created";

  Gen.makeTerrain(blocks, sf::Vector2f(0.0f, 0.0f));
  std::cout << "Vector intialied";

  while (Window->isOpen()) {
    sf::Event event;

    while (Window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) Window->close();
    }

    Window->clear();

    pl1.movement(event);

    phy.addGravity(pl1);

    col.detect_collision(blocks, pl1);

    sf::Vector2f cameraPosition = view.getCenter();
    cameraPosition.x += 0.1f;

    Gen.optimize(blocks, view.getCenter());
    Gen.makeInfinite(blocks, view.getCenter());

    // Update the view's center to follow the player
    view.setCenter(cameraPosition);

    // Apply the view to the window
    Window->setView(view);

    // all rendering logic here

    for (Object*& p : blocks) {
      if (p) {  // Check if the pointer is valid (not null)
        p->render(Window);
      } else {
        std::cout << "Error ";
      }
    }

    pl1.render(Window);

    Window->display();
  }
  auto endTime = std::chrono::high_resolution_clock::now();

  // Calculate the elapsed time in seconds
  std::chrono::duration<double> elapsedSeconds = endTime - startTime;

  // Convert the elapsed time to seconds and display it
  double elapsedSecondsDouble = elapsedSeconds.count();
  score.calculateScore(elapsedSecondsDouble);
}

Game::~Game() { delete Window; }