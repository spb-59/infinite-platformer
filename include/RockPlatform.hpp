#ifndef ROCKRockPlatform_HPP
#define ROCKRockPlatform_HPP

#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class RockPlatform : public Obstacle {
 private:
  sf::Texture localTexture;

 public:
  RockPlatform();
  RockPlatform(float x_cord, float y_cord, sf::Vector2f size);

  std::string get_type();

  ~RockPlatform();
};
#endif