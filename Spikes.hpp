
#pragma once

#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class Spikes : public Obstacle {
 private:
  sf::Texture localTexture;

 public:
  Spikes(float x_cord, float y_cord, sf::Vector2f size);
  Spikes();

  std::string get_type();
  ~Spikes();
};
