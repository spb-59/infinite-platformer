#ifndef LAVAPIT_HPP
#define LAVAPIT_HPP

#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class LavaPit : public Obstacle {
 private:
  sf::Texture localTexture;

 public:
  LavaPit(float x_cord, float y_cord, sf::Vector2f size);
  LavaPit();

  std::string get_type();

  ~LavaPit();
};

#endif
