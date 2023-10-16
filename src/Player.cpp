#include "../include/Player.hpp"
#include<SFML/Graphics.hpp>

 sf::Texture localTexture;
 

Player::Player(sf::Texture* texture, float x_cord, float y_cord, sf::Vector2f size, sf::Vector2u imageCount, float switchTime, float speed) :
animation(texture, imageCount, switchTime), Entity(x_cord, y_cord, size) {

      speed=speed; 
      row = 0;
      faceRight = true; 

  frame.setTexture(texture);
  frame.setPosition(sf::Vector2f(x_cord, y_cord));
  frame.setSize(size);
  canMove = true;
}

//Animation animation(localTexture, sf::Vector2u(2,2), 0.01f);

void Player::set_position_(float x_cord, float y_cord) {

  obj.setPosition(x_cord, y_cord);
}

void Player::update(float deltaTime) {

  sf::Vector2f movement(0.0f, 0.0f);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    movement.x -= speed * deltaTime; 
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    movement.x += speed *deltaTime; 
  }

  if (movement.x >0) {
    faceRight = true; 
  } else if (movement.x <0) {
    faceRight = false; // facing left 
  }

  animation.update(deltaTime, faceRight);
  frame.setTextureRect(animation.uvRect);
}
 
//  sf::Clock pclock;
//  float deltatime=0;

void Player::render(sf::RenderWindow* window){
  window->draw(frame); 
}