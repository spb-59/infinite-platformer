
#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Collision.hpp"
#include "Entity.hpp"
#include "Generation.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "physics.hpp"
#include "Menu.hpp"
#include "Button.hpp"
#include "Menu.hpp"

Generation Gen;
physics phy(0.5f);
Collision col;
Menu menu;



Game::Game(int x_dimension, int y_dimension, const std::string title) {
  Window = new sf::RenderWindow(sf::VideoMode(x_dimension, y_dimension),
                                "Game");  // making game window
  std::cout << "Init Complete";
}

void Game::run() {

  // object creations and generations here
  Entity e1(100.0f, 250.0f, sf::Vector2f(1.0f, 1.0f));
  std::cout << "Entity Created";
  Player pl1(100.0f, 250.0f, sf::Vector2f(1.0f, 1.0f));
  sf::View view(sf::FloatRect(0, 0, Window->getSize().x, Window->getSize().y));

  std::vector<Object*> blocks(10, nullptr);
  std::cout << "Vector Created";

  Gen.makeTerrain(blocks, sf::Vector2f(0.0f, 0.0f));
  std::cout << "Vector intialised";

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
    cameraPosition.x += 0.0f;

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
    e1.render(Window);
    pl1.render(Window);

    Window->display();
  }
 }

Game::~Game() { delete Window; }
