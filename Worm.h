#include <SFML/Graphics.hpp>

#include "Entity.h"

class Worm : public Entity {
 public:
  Worm(float x_cord, float y_cord, sf::Vector2f size, sf::Vector2f speed,
       int size);
  void setSpeed(sf::Vector2f speed);
  sf::Vector2f getSpeed();
};
