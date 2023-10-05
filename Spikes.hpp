#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class Spikes : public Obstacle {
 private:
  int size;

 public:
  Spikes(float x_cord, float y_cord, sf::Vector2f size);
};
