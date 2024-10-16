// Include the Player.hpp header file from a relative path
#include "../include/Player.hpp"

// Constructor for the Player class, taking position (x, y) and size as
// parameters
Player::Player(float x_cord, float y_cord, sf::Vector2f size)
    : Entity(x_cord, y_cord, size) {
  // Load a texture for the player and configure the object
  LocalTexture.loadFromFile("./resources/player_right.png");
  obj.setTexture(LocalTexture);
  canMove = true;
}

// Method to set the position of the player
void Player::set_position_(float x_cord, float y_cord) {
  // Set the position of the player object
  obj.setPosition(x_cord, y_cord);
}

bool Player::detectOffStage(sf::Vector2f center){

if(obj.getPosition().y>1000.0f+center.y){
  return true;
}
return false;
}

