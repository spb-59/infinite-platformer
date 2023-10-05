#include <SFML/Graphics.hpp>

#include "Obstacle.h"

class Platform : public Obstacle {
 private:
  int size;

 public:
  Platform(float x_cord, float y_cord, sf::Vector2f size, bool isDeadly,
           int size);
  int get_size();
};
