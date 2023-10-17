// Include the Platform.hpp header file from a relative path
#include "../include/Platform.hpp"

// Constructor for the Platform class, taking position (x, y) and size as
// parameters
Platform::Platform(float x_cord, float y_cord, sf::Vector2f size)
    : Obstacle(x_cord, y_cord, size) {
  // Initialize the Platform as not deadly and load a texture
  isDeadly = false;
  localTexture.loadFromFile("./resources/platform.png");
  obj.setTexture(localTexture);
}

// Default constructor for the Platform class, using default values for position
// and size
Platform::Platform() : Platform(0.0f, 0.0f, sf::Vector2f(0.0f, 0.0f)) {}

// Method to get the type of the Platform (returns "PLATFORM")
std::string Platform::get_type() { return "PLATFORM"; }

// Destructor for the Platform class (empty, as there are no specific resources
// to release)
Platform::~Platform() {}
