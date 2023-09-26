#include <SFML/Graphics.hpp>

#include "Entity.h"

class Rock : public Entity {
 public:
  Rock(float x_cord, float y_cord, sf::Vector2f size, sf::Vector2f speed,
       int size);
  void setSpeed(sf::Vector2f speed);
  sf::Vector2f getSpeed();
};
