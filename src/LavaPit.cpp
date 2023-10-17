// Include the header file for the LavaPit class.
#include "../include/LavaPit.hpp"

// Constructor for the LavaPit class with parameters.
LavaPit::LavaPit(float x_cord, float y_cord, sf::Vector2f size)
    : Obstacle(x_cord, y_cord, size) {
  // Load the texture for the lava pit.
  localTexture.loadFromFile("./resources/lavaPit.png");
  // Set the obstacle as deadly.
  isDeadly = true;
  // Set the texture for the lava pit object.
  obj.setTexture(localTexture);
}

// Default constructor for the LavaPit class.
LavaPit::LavaPit() : LavaPit(0.0f, 0.0f, sf::Vector2f(0.0f, 0.0f)) {}

// Method to get the type of the obstacle (LAVA).
std::string LavaPit::get_type() { return "LAVA"; }

// Destructor for the LavaPit class.
LavaPit::~LavaPit() {}
