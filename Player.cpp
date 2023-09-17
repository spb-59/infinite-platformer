#include "Player.h"

#include <SFML/Graphics.hpp>

#include "Entity.h"

Player::Player(sf::Vector2f size, float x, float y) : Entity(size, x, y) {}
void Player::movement(sf::Event event) {
  switch (event.type) {
    case sf::Event::KeyPressed:
      // Handle specific key events for movement
      switch (event.key.code) {
        case sf::Keyboard::Up:
          entity.move(0.0f, -1.0f);
          break;
        case sf::Keyboard::Down:
          entity.move(0.0f, 1.0f);
          break;
        case sf::Keyboard::Left:
          entity.move(-1.0f, 0.0f);
          break;
        case sf::Keyboard::Right:
          entity.move(1.0f, 0.0f);
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