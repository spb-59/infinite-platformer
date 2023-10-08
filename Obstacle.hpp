#pragma once

#include <SFML/Graphics.hpp>

#include "Object.hpp"

class Obstacle : public Object {
 protected:
  bool isDeadly;

 public:
  Obstacle(float x_cord, float y_cord, sf::Vector2f size);
  bool get_isDeadly();
};
