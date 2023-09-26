#include <SFML/Graphics.hpp>

#include "Obstacle.h"

class Spike : public Obstacle {
 private:
  int size;

 public:
  Spike(float x_cord, float y_cord, sf::Vector2f size, bool isDeadly, int size);
  int get_size();
};
