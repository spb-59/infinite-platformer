#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
 private:
  sf::Sprite player;
  sf::Clock clock; 
  sf::Time timeElapsed;

 public:
  Player(sf::Vector2f size, float x, float y,sf::Texture* texture);
  void movement(sf::Event);

  ~Player();
};

#endif
