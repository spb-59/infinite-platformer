#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#pragma once

#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class Platform : public Obstacle {
 private:
  sf::Texture localTexture;

 public:
  Platform();
  Platform(float x_cord, float y_cord, sf::Vector2f size);

  std::string get_type();

  ~Platform();
};
#endif