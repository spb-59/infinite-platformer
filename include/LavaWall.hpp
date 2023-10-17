#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class LavaWall : public Entity {
 private:
  sf::Texture localTexture; // Texture specific to the LavaWall

 public:
  // Constructor for lavaWall with position, size, and speed
  LavaWall(float x_cord, float y_cord, sf::Vector2f size, sf::Vector2f speed);

  // Set the speed vector for the LavaWall
  void setSpeed(sf::Vector2f speed);

  // Get the current speed vector
  sf::Vector2f getSpeed();

  // Perform wall movement
  void wallMovement();

  // Destructor
  ~LavaWall();
};
