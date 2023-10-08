
#pragma once

#include <SFML/Graphics.hpp>

#include "Object.hpp"

class Entity : public Object {
 protected:
  sf::Vector2f speed;
  int size;

 public:
  Entity(float x_cord, float y_cord, sf::Vector2f size);
  void movement(sf::Event event);
  void setSpeed(sf::Vector2f speed);
  sf::Vector2f getSpeed();
};