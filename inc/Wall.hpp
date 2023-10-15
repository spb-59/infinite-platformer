#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Wall : public Entity {
 public:
  Wall(float x_cord, float y_cord, sf::Vector2f size, sf::Vector2f speed);
  void setSpeed(sf::Vector2f speed);
  sf::Vector2f getSpeed();
};
