
#include "Obstacle.h"

Obstacle::Obstacle(float x_cord, float y_cord, sf::Vector2f size)
    : Object(x_cord, y_cord, size) {
  isDeadly = false;
}

bool Obstacle::get_isDeadly() { return isDeadly; }