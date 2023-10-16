#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.hpp"
#include "Animation.hpp"

class Player : public Entity {
 public:
  Player(float x_cord, float y_cord, sf::Vector2f size);
  void set_position_(float x_cord, float y_cord);

 private:
  sf::Texture LocalTexture;
};


#endif