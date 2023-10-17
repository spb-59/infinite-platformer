// Include the Spikes.hpp header file from a relative path
#include "../include/Spikes.hpp"

// Constructor for the Spikes class, taking position (x, y) and size as
// parameters
Spikes::Spikes(float x_cord, float y_cord, sf::Vector2f size)
    : Obstacle(x_cord, y_cord, size) {
  // Load a texture for the spikes and configure the object
  localTexture.loadFromFile("./resources/spikes.png");
  isDeadly = true;  // Set the spikes as deadly
  obj.setTexture(localTexture);
}

// Default constructor for the Spikes class, using default values for position
// and size
Spikes::Spikes() : Spikes(0.0f, 0.0f, sf::Vector2f(0.0f, 0.0f)) {}

// Method to get the type of the Spikes (returns "SPIKES")
std::string Spikes::get_type() { return "SPIKES"; }

// Destructor for the Spikes class (empty, as there are no specific resources to
// release)
Spikes::~Spikes() {}
