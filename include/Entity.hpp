#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <SFML/Graphics.hpp>

#include "Object.hpp"

class Entity : public Object {
 protected:
  sf::Vector2f speed;
  int size;
  bool can_jump = true;
  bool landed = true;

 public:
  bool canMove;
  void set_landed(bool landed);
  Entity(float x_cord, float y_cord, sf::Vector2f size);
  void movement(sf::Event event);
  void setSpeed(sf::Vector2f speed);
  sf::Vector2f getSpeed();
  std::string get_type();
};

#endif