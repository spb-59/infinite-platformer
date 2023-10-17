#include "../include/RockPlatform.hpp"

RockPlatform::RockPlatform(float x_cord, float y_cord, sf::Vector2f size)
    : Obstacle(x_cord, y_cord, size) {
  isDeadly = false;
  localTexture.loadFromFile("./resources/fall_platform.png");
  obj.setTexture(localTexture);
}

RockPlatform::RockPlatform()
    : RockPlatform(0.0f, 0.0f, sf::Vector2f(0.0f, 0.0f)) {}

std::string RockPlatform::get_type() { return "PLATFORM"; }

RockPlatform::~RockPlatform() {}
