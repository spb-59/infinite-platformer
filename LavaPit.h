#include <SFML/Graphics.hpp>

#include "Obstacle.h"

class LavaPit : public Obstacle {
 private:
  int size;

 public:
  LavaPit(float x_cord, float y_cord, sf::Vector2f size);
};
