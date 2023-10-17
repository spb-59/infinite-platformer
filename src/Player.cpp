#include "../include/Player.hpp"

Player::Player(float x_cord, float y_cord, sf::Vector2f size)
    : Entity(x_cord, y_cord, size) {
  LocalTexture.loadFromFile("./resources/player_right.png");
  obj.setTexture(LocalTexture);
  canMove = true;
}

void Player::set_position_(float x_cord, float y_cord) {
  obj.setPosition(x_cord, y_cord);
}
