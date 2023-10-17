#include "../include/LavaWall.hpp"

LavaWall::LavaWall(float x_cord, float y_cord, sf::Vector2f size,
                   sf::Vector2f speed)
    : Entity(x_cord, y_cord, size) {
  localTexture.loadFromFile("./resources/LavaWall.png");
  obj.setTexture(localTexture);
}

void LavaWall::wallMovement() { obj.move(0.1f, 0.0f); }
LavaWall::~LavaWall() {}