#pragma once

#include <SFML/Graphics.hpp>

#include "Object.hpp"

class Obstacle : public Object {
 protected:
  bool isDeadly;

 public:
  Obstacle();
  Obstacle(float x_cord, float y_cord, sf::Vector2f size);
  bool get_isDeadly();

  virtual std::string get_type() = 0;

  ~Obstacle();
};
