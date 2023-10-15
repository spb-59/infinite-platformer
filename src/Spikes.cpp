#include "../include/Spikes.hpp"

Spikes::Spikes(float x_cord, float y_cord, sf::Vector2f size)
    : Obstacle(x_cord, y_cord, size) {
  localTexture.loadFromFile("./resources/spikes.png");
  isDeadly = true;
  obj.setTexture(localTexture);
}

Spikes::Spikes() : Spikes(0.0f, 0.0f, sf::Vector2f(0.0f, 0.0f)) {}

std::string Spikes::get_type() { return "SPIKES"; }

Spikes::~Spikes() {}