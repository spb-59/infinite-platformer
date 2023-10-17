// Include the Obstacle.hpp header file from a relative path
#include "../include/Obstacle.hpp"

// Include the C++ standard input/output library
#include <iostream>

// Constructor for the Obstacle class, taking position (x, y) and size as
// parameters
Obstacle::Obstacle(float x_cord, float y_cord, sf::Vector2f size)
    : Object(x_cord, y_cord, size) {
  // Initialize the Obstacle and set it as not deadly by default
  isDeadly = false;
}

// Default constructor for the Obstacle class, using default values for position
// and size
Obstacle::Obstacle() : Obstacle(0.0f, 0.0f, sf::Vector2f(1.0f, 1.0f)) {}

// Method to check if the obstacle is deadly (returning the value of isDeadly)
bool Obstacle::get_isDeadly() { return isDeadly; }

// Destructor for the Obstacle class (empty, as there are no specific resources
// to release)
Obstacle::~Obstacle() {}
