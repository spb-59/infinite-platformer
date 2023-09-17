
#include "game.h"

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Player.h"
#include "platform.h"

game::game() {
  Window = new sf::RenderWindow(sf::VideoMode(800, 800),
                                "Game");  // making game window
}

void game::run() {
  // object creations and generations here
  platform p1(100.0f, 100.0f, sf::Vector2f(50.0f, 50.0f));
  Entity e1(sf::Vector2f(100.0f, 100.0f), 100.0f, 250.0f);
  Player pl1(sf::Vector2f(100.0f, 100.0f), 10.0f, 10.0f);

  while (Window->isOpen()) {
    sf::Event event;

    while (Window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) Window->close();
    }

    Window->clear();
    pl1.movement(event);

    // all rendering logic here

    p1.render(Window);
    e1.render(Window);
    pl1.render(Window);

    Window->display();
  }
}

game::~game() { delete Window; }
