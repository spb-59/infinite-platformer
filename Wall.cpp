#include "Wall.hpp"

Wall::Wall(float x_cord, float y_cord, sf::Vector2f size, sf::Vector2f speed)
    : Entity(x_cord, y_cord, size) {
  localTexture.loadFromFile("./textures/lavaWall.png");
  obj.setTexture(localTexture);
}

void Wall::wallMovement() { obj.move(0.0509f, 0.0f); }
Wall::~Wall() {}
