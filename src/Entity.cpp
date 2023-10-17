#include "../include/Entity.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

Entity::Entity(float x_cord, float y_cord, sf::Vector2f size)
    : Object(x_cord, y_cord, size) {
  speed = sf::Vector2f(0.0f, 0.0f);
  canMove = true;
  can_jump = true;
}

void Entity::movement(sf::Event event) {
  // std::cout << x_cord_ << " "
  if (canMove) {

  
    // switch (event.type) {
    //   case sf::Event::KeyPressed:
    //     // Handle specific key events for movement
    //     switch (event.key.code) {
    //       case sf::Keyboard::Up:
    //         // if (can_jump) {
    //         // can_jump = false;
    //         speed.y = -0.30f;
    //         break;
    //         // } else {
    //         //   break;
    //         // }
    //       // case sf::Keyboard::Down:
    //       //   speed.y = 0.50f;
    //       //  break;
    //       case sf::Keyboard::Left:
    //         speed.x = -0.70f;
    //         break;
    //       case sf::Keyboard::Right:
    //         speed.x = 0.70f;
    //         break;
    //       default:
    //         break;
    //     }
    //     break;
    //   case sf::Event::KeyReleased:
    //     // Stop movement when the key is released

    //     switch (event.key.code) {
    //       case sf::Keyboard::Up:
    //         can_jump = true;
    //         speed.y -= 0.0f;
    //         break;
    //       case sf::Keyboard::Left:
    //         speed.x = 0;
    //         break;
    //       case sf::Keyboard::Right:
    //         speed.x = 0;
    //         break;
    //       default:
    //         break;
    //     }
    //     break;
    //   default:
    //     break;
    // }


    if (can_jump) {
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
          speed.y += -1.0f;
          can_jump = false;
        }
      }
    }

    // } else if (can_jump && speed.y > 10.0f) {
    //   speed.y -= -0.2f;
    // }


    std::cout << speed.y;
    speed.x = 0.3f;
    obj.move(speed);


  }
}

void Entity::setSpeed(sf::Vector2f speed_) { speed = speed_; }
sf::Vector2f Entity::getSpeed() { return speed; }

std::string Entity::get_type() { return " "; }

void Entity::setCanJump() { can_jump = true; }

void Entity::setCantJump() { can_jump = false; }