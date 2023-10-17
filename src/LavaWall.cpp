#include "../include/LavaWall.hpp"

// Constructor for the LavaWall class, taking initial position, size, and speed
// as parameters
LavaWall::LavaWall(float x_cord, float y_cord, sf::Vector2f size,
                   sf::Vector2f speed)
    : Entity(x_cord, y_cord, size) {
  // Load a texture from a local file
  localTexture.loadFromFile("./resources/LavaWall.png");
  // Set the texture for the LavaWall object
  obj.setTexture(localTexture);
}

// Function for moving the LavaWall object
void LavaWall::wallMovement() {
  // Move the object horizontally by 0.1f units
  obj.move(0.1f, 0.0f);
}

// Destructor for the LavaWall class (empty, as there are no specific resources
// to release)
LavaWall::~LavaWall() {}
