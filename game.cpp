
#include "game.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "Player.h"
#include "platform.h"

game::game() {
  Window = new sf::RenderWindow(sf::VideoMode(800, 800),
                                "Game");  // making game window
  background.loadFromFile("tex/background.png");
  // sf::Sprite bg(background);

  if (texture.loadFromFile("tex/yipppe.png")) {
    std::cout << "Failed to load";
  }
}

void game::run() {
  // object creations and generations here
  platform p1(100.0f, 100.0f, sf::Vector2f(50.0f, 50.0f));
  Entity e1(sf::Vector2f(1.0f, 1.0f), 100.0f, 250.0f, &texture);
  Player pl1(sf::Vector2f(1.0f, 1.0f), 10.0f, 10.0f, &texture);
  Entity bg(sf::Vector2f(1.0f, 1.0f), 0.0f, 0.0f, &background);

  sf::View view(sf::FloatRect(0, 0, Window->getSize().x, Window->getSize().y));

  while (Window->isOpen()) {
    sf::Event event;

    while (Window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) Window->close();
    }

    Window->clear();
    pl1.movement(event);

    // all rendering logic here
    sf::Vector2f cameraPosition = view.getCenter();
    cameraPosition.x += 0.01f;

    // Update the view's center to follow the player
    view.setCenter(cameraPosition);

    // Apply the view to the window
    Window->setView(view);

    // test render background

    bg.render(Window);

    p1.render(Window);
    e1.render(Window);
    pl1.render(Window);

    Window->display();
  }
}

game::~game() { delete Window; }
