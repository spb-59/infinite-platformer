#include "LavaPit.hpp"

LavaPit::LavaPit(float x_cord, float y_cord, sf::Vector2f size)
    : Obstacle(x_cord, y_cord, size) {
  localTexture.loadFromFile("lavapit.png");
  isDeadly = true;
  obj.setTexture(localTexture);
}

LavaPit::LavaPit() : LavaPit(0.0f, 0.0f, sf::Vector2f(0.0f, 0.0f)) {}

std::string LavaPit::get_type() { return "LAVA"; }

LavaPit::~LavaPit() {}