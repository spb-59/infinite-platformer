#include "Platform.hpp"

Platform::Platform(float x_cord, float y_cord, sf::Vector2f size)
    : Obstacle(x_cord, y_cord, size) {
  isDeadly = false;
  localTexture.loadFromFile("./stone.png");
  obj.setTexture(localTexture);
}

Platform::Platform() : Platform(0.0f, 0.0f, sf::Vector2f(0.0f, 0.0f)) {}

std::string Platform::get_type() { return "PLATFORM"; }

Platform::~Platform() {}
