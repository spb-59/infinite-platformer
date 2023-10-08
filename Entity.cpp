#include "Entity.hpp"

Entity::Entity(float x_cord, float y_cord, sf::Vector2f size)
    : Object(x_cord, y_cord, size) {}
void Entity::movement(sf::Event event) {
  switch (event.type) {
    case sf::Event::KeyPressed:
      // Handle specific key events for movement
      switch (event.key.code) {
        case sf::Keyboard::Up:
          obj.move(0.0f, -0.5f);
          break;
        case sf::Keyboard::Down:
          obj.move(0.0f, 0.50f);
          break;
        case sf::Keyboard::Left:
          obj.move(-0.50f, 0.0f);
          break;
        case sf::Keyboard::Right:
          obj.move(0.50f, 0.0f);
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

void Entity::setSpeed(sf::Vector2f speed) { speed = speed; }
sf::Vector2f Entity::getSpeed() { return speed; }