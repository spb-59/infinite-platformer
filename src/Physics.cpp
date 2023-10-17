// Include the Physics.hpp header file from a relative path
#include "../include/Physics.hpp"

// Include the C++ standard input/output library
#include <iostream>

// Include the Entity.hpp and Player.hpp header files from relative paths
#include "../include/Entity.hpp"
#include "../include/Player.hpp"

// Constructor for the Physics class, taking the gravity as a parameter
Physics::Physics(float gravity) : gravity(gravity) {
  // Initialize the Physics object with the provided gravity value
}

// Method to apply gravity to an entity
void Physics::addGravity(Entity& obj) {
  // Set the vertical speed of the entity to simulate gravity
  obj.setSpeed(sf::Vector2f(obj.getSpeed().x, gravity));
  // Uncommenting the following line would print the entity's vertical speed
  // std::cout << " " << obj.getSpeed().y;
}
