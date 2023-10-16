#include "../include/Game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Animation.hpp"
#include "../include/Entity.hpp"
#include "../include/Menu.hpp"
#include "../include/Player.hpp"

Game::Game() {
  window.create(sf::VideoMode(1280, 720), "Lava Run", sf::Style::Close);
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);
  background.loadFromFile("../resources/background.png");
  // sf::Sprite bg(background);

  if (!(texture.loadFromFile("../resources/animation_yipee.png"))) {
    std::cout << "Failed to load";
  }
}

Game::~Game() { std::cout << "Game closed" << std::endl; }

sf::RenderWindow& Game::getWindow() { return window; }

Gamestate Game::getState() { return state; }

void Game::setState(Gamestate state_) { this->state = state_; }

void Game::run() {
  // Animation properties
  Animation animation(&texture, sf ::Vector2u(2, 2), 0.3f);
  // sf::Vector2u textureSize = texture.getSize();
  // textureSize.x /= 2;
  // textureSize.y /= 2;
  // pl1.setTextureRect(sf::IntRect(textureSize.x*))

  Menu menu(window);

  float deltaTime = 0.0f;
  sf::Clock clock;
  Player pl1(sf::Vector2f(1.0f, 1.0f), 10.0f, 10.0f, &texture);
  Entity bg(sf::Vector2f(1.0f, 1.0f), 0.0f, 0.0f, &background);
  sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
  sf::Vector2f cameraPosition = view.getCenter();
  cameraPosition.x += 0.01f;

  while (window.isOpen()) {
    deltaTime = clock.restart().asSeconds();
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();

    // run menu 
    menu.run();

    window.clear();

    switch(menu.getMenuState()) {
      case PLAY:
        pl1.movement(event);

        // all rendering logic here


        // Update the view's center to follow the player
        view.setCenter(cameraPosition);

        // Apply the view to the window
        window.setView(view);
        animation.update(0, deltaTime);

        // test render background
        bg.render(&window);
        pl1.render(&window);

        window.display();
        break;

      case HOW_TO_PLAY:
          std::cout << "You play by playing" << std::endl;
        break;

      case QUIT:
        window.close();
        break;

      default:
        std::cout << "Nothing happened- this should never happen" << std::endl; 
    }


  }
}
