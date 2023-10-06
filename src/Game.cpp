#include "../include/Game.hpp"

#include <SFML/Graphics.hpp>

Game::Game() {
  window.create(sf::VideoMode(1280, 720), "Lava Run",
                sf::Style::Close | sf::Style::Titlebar);
}

void Game::run() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == event.Closed) {
        window.close();
      }
    }

    window.clear();  // Clear the window

    // Add your game rendering logic here

    window.display();  // Display the content
  }
}
