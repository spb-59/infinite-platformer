#pragma once

#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class LavaPit : public Obstacle {
 private:
  int size;

 public:
  LavaPit(float x_cord, float y_cord, sf::Vector2f size);
};
