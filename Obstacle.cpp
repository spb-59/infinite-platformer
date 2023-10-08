
#include "Obstacle.hpp"

Obstacle::Obstacle(float x_cord, float y_cord, sf::Vector2f size)
    : Object(x_cord, y_cord, size) {
  isDeadly = false;
}

Obstacle::Obstacle() : Obstacle(0.0f, 0.0f, sf::Vector2f(1.0f, 1.0f)) {}

bool Obstacle::get_isDeadly() { return isDeadly; }