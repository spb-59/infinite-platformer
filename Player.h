#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
 private:
  sf::Sprite player;

 public:
  Player(sf::Vector2f size, float x, float y, sf::Texture* texture);
  void movement(sf::Event);
  sf::Vector2f get_position();
  ~Player();
};

#endif