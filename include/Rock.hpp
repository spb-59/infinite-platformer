#ifndef ROCK_HPP
#define ROCK_HPP

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Rock : public Entity {
 public:
  Rock(float x_cord, float y_cord, sf::Vector2f size);
  void render(sf::RenderWindow* window);
  bool get_isDeadly();

 private:
  sf::Texture LocalTexture;
};

#endif