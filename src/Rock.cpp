#include "../include/Rock.hpp"

Rock::Rock(float x_cord, float y_cord, sf::Vector2f size)
    : Entity(x_cord, y_cord, size) {
  LocalTexture.loadFromFile("./resources/stone.png");
  obj.setTexture(LocalTexture);
  canMove = true;
}

void Rock::render(sf::RenderWindow* window) {
  window->draw(obj);
  obj.move(0.0f, 0.3f);
}

bool Rock::get_isDeadly() { return true; }
