#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>

#include "Object.hpp"

class Obstacle : public Object {
 protected:
  bool isDeadly;  // A flag indicating if the obstacle is deadly

 public:
  // Default constructor for the Obstacle class
  Obstacle();

  // Constructor for the Obstacle class with specified position (x, y) and size
  Obstacle(float x_cord, float y_cord, sf::Vector2f size);

  // Get whether the obstacle is deadly
  bool get_isDeadly();

  // Get the type of the obstacle (to be implemented in derived classes)
  virtual std::string get_type() = 0;

  // Destructor for the Obstacle class
  ~Obstacle();
};

#endif  // OBSTACLE_HPP
