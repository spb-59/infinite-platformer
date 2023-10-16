#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.hpp"
#include "Animation.hpp"

class Player : public Entity {
 public:
  Player(sf::Texture *texture, float x_cord, float y_cord, sf::Vector2f size, sf::Vector2u imageCount, float switchTime, float speed);
  void set_position_(float x_cord, float y_cord);
  void update(float deltaTime);

  void render(sf::RenderWindow* window);

 private:
  sf::Texture LocalTexture;
  sf::RectangleShape frame; 
  Animation animation; 

  int row;
  float speed;
  bool faceRight; 

};


#endif