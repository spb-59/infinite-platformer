#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class LavaWall : public Entity {
 private:
  sf::Texture localTexture;

 public:
  LavaWall(float x_cord, float y_cord, sf::Vector2f size, sf::Vector2f speed);
  void setSpeed(sf::Vector2f speed);
  sf::Vector2f getSpeed();
  void wallMovement();
  ~LavaWall();
};