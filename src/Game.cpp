#include "../include/Game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../include/Colision.hpp"
#include "../include/Entity.hpp"
#include "../include/Generation.hpp"
#include "../include/Obstacle.hpp"
#include "../include/Physics.hpp"
#include "../include/Player.hpp"
#include "../include/Menu.hpp"
#include "../include/Animation.hpp"

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

  // object creations and generations here
  Player pl1(100.0f, 250.0f, sf::Vector2f(0.8f, 0.8f));

  sf::View view(sf::FloatRect(0, 0, Window->getSize().x, Window->getSize().y));

  std::vector<Object*> blocks(10, nullptr);
  std::cout << "Vector Created";

  Gen.makeTerrain(blocks, sf::Vector2f(0.0f, 0.0f));
  std::cout << "Vector initialized";
  
  sf::Vector2f cameraPosition;
  
  Menu menu(Window); 

  while (Window->isOpen()) {
    sf::Event event;


    while (Window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        Window->close();
      }
    }

    Window->clear();

    if (inMenu) {
      menu.run();

      if (menu.getMenuState() == MenuState::PLAY) {
        std::cout << "PLAY selected - game::Run" << std::endl;
        inMenu = false; 

      } else if (menu.getMenuState() == MenuState::HOW_TO_PLAY) {
        std::cout << "How to play selected- game::run" << std::endl; 

      } else if (menu.getMenuState() == MenuState::QUIT) {
        std::cout << "Quit has been chosen- game::run function" << std::endl; 
        Window->close();
      }

    } else {
      // run the game 
        pl1.movement(event);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          //animation.moveLeft(0.5f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          //animation.moveRight(0.5f);
        }

        phy.addGravity(pl1);

        col.detect_collision(blocks, pl1);

        // Move this line outside the switch block
         cameraPosition = view.getCenter();
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
        Window->setView(view);
        Window->display();
        

    }
    }
}


Game::~Game() { delete Window; }
