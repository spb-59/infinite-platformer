#include "Player.h"

#include <SFML/Graphics.hpp>

#include "Entity.h"

Player::Player(sf::Vector2f size, float x, float y, sf::Texture* texture)
    : Entity(size, x, y, texture) {}


void Player::movement(sf::Event event) {
 

  switch (event.type) {
    case sf::Event::KeyPressed:
      // Handle specific key events for movement
      switch (event.key.code) {
        case sf::Keyboard::Up:
        // jump mech
        timeElapsed = clock.restart(); 
        
        if (timeElapsed.asSeconds() < 2) {
          break;
        } else {
          entity.move(0.0f, -50.0f);
          break;  
        }
          break;
        case sf::Keyboard::Down:
          entity.move(0.0f, 0.50f);
          break;
        case sf::Keyboard::Left:
          entity.move(-0.50f, 0.0f);
          break;
        case sf::Keyboard::Right:
          entity.move(0.50f, 0.0f);
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }


}

Player::~Player() {}
