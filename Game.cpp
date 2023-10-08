
#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Entity.hpp"
#include "Generation.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"

Generation Gen;

Game::Game(int x_dimension, int y_dimension, const std::string title) {
  Window = new sf::RenderWindow(sf::VideoMode(x_dimension, y_dimension),
                                "Game");  // making game window
  std::cout << "Init Complete";
}

void Game::run() {
  // object creations and generations here
  Entity e1(100.0f, 250.0f, sf::Vector2f(1.0f, 1.0f));
  std::cout << "Entity Created";
  Player pl1(100.0f, 250.0f, sf::Vector2f(10.0f, 10.0f));
  sf::View view(sf::FloatRect(0, 0, Window->getSize().x, Window->getSize().y));

  std::vector<Object*> blocks(10);
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

    sf::Vector2f cameraPosition = view.getCenter();
    cameraPosition.x += 0.1f;

    Gen.makeInfinite(blocks, sf::Vector2f(0.0f, 0.0f));

    // Update the view's center to follow the player
    view.setCenter(cameraPosition);

    // Apply the view to the window
    Window->setView(view);

    // all rendering logic here

    for (Object* p : blocks) {
      p->render(Window);
    }

    e1.render(Window);
    pl1.render(Window);

    Window->display();
  }
}

Game::~Game() { delete Window; }
