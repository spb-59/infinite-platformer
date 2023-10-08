#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Player : public Entity {
 public:
  Player(float x_cord, float y_cord, sf::Vector2f size);

 private:
  sf::Texture LocalTexture;
};
