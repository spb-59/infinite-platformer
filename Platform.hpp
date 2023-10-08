#pragma once

#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class Platform : public Obstacle {
 private:
  int size;

 public:
  Platform(float x_cord, float y_cord, sf::Vector2f size, bool isDeadly);
  int get_size();
};
