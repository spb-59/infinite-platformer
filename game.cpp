
#include "game.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Entity.h"
#include "Generation.h"
#include "Player.h"
#include "platform.h"

Generation Gen;

game::game() {
  Window = new sf::RenderWindow(sf::VideoMode(1280, 720),
                                "Game");  // making game window
  if (texture.loadFromFile("tex/yipppe.png")) {
    std::cout << "Failed to load";
  }
}

void game::run() {
  // object creations and generations here
  Entity e1(sf::Vector2f(1.0f, 1.0f), 100.0f, 250.0f, &texture);
  Player pl1(sf::Vector2f(1.0f, 1.0f), 10.0f, 10.0f, &texture);
  sf::View view(sf::FloatRect(0, 0, Window->getSize().x, Window->getSize().y));

  std::vector<platform> blocks(10);
  Gen.makeTerrain(blocks, sf::Vector2f(0.0f, 0.0f));

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

    for (platform& p : blocks) {
      p.render(Window);
    }

    e1.render(Window);
    pl1.render(Window);

    Window->display();
  }
}

game::~game() { delete Window; }
