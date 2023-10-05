#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Rock : public Entity {
 public:
  Rock(float x_cord, float y_cord, sf::Vector2f size);
}
