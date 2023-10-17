#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Entity : public Object {
 protected:
  sf::Vector2f speed;  // Speed vector for entity movement
  int size;           // Size of the entity
  bool can_jump = true;  // A flag indicating if the entity can jump

 public:
  bool canMove;  // A boolean indicating if the entity can move
  Entity(float x_cord, float y_cord, sf::Vector2f size);

  // Handle movement based on an SFML event
  void movement(sf::Event event);

  // Set the speed vector for entity movement
  void setSpeed(sf::Vector2f speed);

  // Get the current speed vector of the entity
  sf::Vector2f getSpeed();

  // Set whether the entity has landed 
  void set_landed(bool landed);

  // Get the type of the entity 
  std::string get_type();
};

#endif