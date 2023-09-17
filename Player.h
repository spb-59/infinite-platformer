#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
 private:
  sf::RectangleShape player;

 public:
  Player(sf::Vector2f size, float x, float y);
  void movement(sf::Event);

  ~Player();
};

#endif