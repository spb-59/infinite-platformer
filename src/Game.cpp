#include "../include/Game.hpp"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "../include/Animation.hpp"
#include "../include/Colision.hpp"
#include "../include/Entity.hpp"
#include "../include/Generation.hpp"
#include "../include/Menu.hpp"
#include "../include/Obstacle.hpp"
#include "../include/Physics.hpp"
#include "../include/Player.hpp"

Generation Gen;
Physics phy(0.3f);
Collision col;

Game::Game(int x_dimension, int y_dimension, const std::string title) {
  Window = new sf::RenderWindow(sf::VideoMode(x_dimension, y_dimension),
                                "Game");  // making game window
  std::cout << "Init Complete";
}

void Game::run() {
  bool inMenu = true;
  bool game = false;

  // object creations and generations here
  Player pl1(100.0f, 250.0f, sf::Vector2f(0.8f, 0.8f));

  sf::View view(sf::FloatRect(0, 0, Window->getSize().x, Window->getSize().y));
  sf::Vector2f originalCenter = view.getCenter();
  std ::cout << view.getCenter().x;
  std::vector<Object*> blocks(10, nullptr);
  Menu menu(Window);

  while (Window->isOpen()) {
    sf::Event event;
    
    // Poll events
    while (Window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        Window->close();
      }
    }

    Window->clear();

    if (inMenu) {
      // Handle the menu here
      Window->clear();
      
      menu.run();

      if (menu.getMenuState() == MenuState::PLAY) {
        inMenu = false;
        game = true;
        // Initialize game state
        blocks.resize(10);
        Gen.makeTerrain(blocks, sf::Vector2f(0.0f, 0.0f));
        pl1.set_position(100.0f, 250.0f);
        view.setCenter(originalCenter);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "Done waiting!" << std::endl;
      } else if (menu.getMenuState() == MenuState::HOW_TO_PLAY) {
        std::cout << "Menu state has been chosen - game run function" << std::endl; 
        //Handle "How to play" menu state 
        sf::Sprite howToPlay;
        sf::Texture howToPlay_tex; 
        // error handling 
        if (!howToPlay_tex.loadFromFile("./resources/howToBackground.png")) {
          std::cout << "Error loading HOWTO texture" << std::endl; 
        }
        howToPlay.setPosition(sf::Vector2f(0,0));
        howToPlay.setTexture(howToPlay_tex);
        Window->draw(howToPlay);

      } else if (menu.getMenuState() == MenuState::QUIT) {
        Window->close();
      } 
    }

    if (game) {
      sf::Vector2f cameraPosition;

      // Handle the game logic here

      pl1.movement(event);

      phy.addGravity(pl1);

      col.detect_collision(blocks, pl1);

      // Update the view's center to follow the player
      cameraPosition = view.getCenter();
      cameraPosition.x += 0.1f;

      Gen.optimize(blocks, view.getCenter());
      Gen.makeInfinite(blocks, view.getCenter());

      view.setCenter(((((cameraPosition)))));

      Window->setView(view);

      // Render the game
      for (Object*& p : blocks) {
        if (p) {
          p->render(Window);
        } else {
          std::cout << "Error ";
        }
      }

      pl1.render(Window);
    }

    // Set the view and display the window
    Window->setView(view);
    Window->display();

    if (col.get_deadlyCollision()) {
      game = false;
      inMenu = true;
      blocks.resize(10);
      Gen.makeTerrain(blocks, sf::Vector2f(0.0f, 0.0f));
      pl1.set_position(100.0f, 100.0f);
      view.setCenter(originalCenter);
      Window->setView(view);
      menu.setIsGameOver();
    }
  }
}

Game::~Game() { delete Window; }