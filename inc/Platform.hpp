#pragma once

#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class Platform : public Obstacle {
 private:
  sf::Texture localTexture;

 public:
  Platform();
  Platform(float x_cord, float y_cord, sf::Vector2f size);
  ~Platform();
};
