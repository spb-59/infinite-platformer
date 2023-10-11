// #include "Collision.hpp"

// #include <iostream>

// Collision::Collision() {}

// bool Collision::detect_collision(std::vector<Object *> &boxes, Player
// &player) {
//   // for (Object *&p : boxes) {
//   //   if ((player.getHitBox()).intersects(p->getHitBox())) {
//   //     std::cout << "collide" << std::endl;
//   //     player.setSpeed(sf::Vector2f(player.getSpeed().x, 0.0f));
//   //     if (p->get_isDeadly() == true) {
//   //       std::cout << " GAME OVER";
//   //     }

//   //   } else {
//   //   }
//   // }
// }
#include "Collision.hpp"

#include <iostream>

#include "physics.hpp"

Collision::Collision() {}

bool Collision::detect_collision(std::vector<Object*>& boxes, Player& player) {
  bool collisionDetected = false;

  // Get player x and y positions.
  float playerX = player.get_x_cord();
  float playerY = player.get_y_cord();

  // Get player hitbox once to avoid repeated calls.
  sf::FloatRect playerHitBox = player.getHitBox();
  sf::FloatRect nextPos;

  // Iterate through each object in the boxes vector.
  for (Object*& p : boxes) {
    sf::FloatRect objectHitBox = p->getHitBox();

    nextPos = playerHitBox;
    nextPos.left += player.getSpeed().x;
    nextPos.top += player.getSpeed().y;

    if (objectHitBox.intersects(nextPos)) {
      collisionDetected = true;

      // Calculate the overlap on each side.
      float dx =
          std::min(playerHitBox.left + playerHitBox.width - objectHitBox.left,
                   objectHitBox.left + objectHitBox.width - playerHitBox.left);
      float dy =
          std::min(playerHitBox.top + playerHitBox.height - objectHitBox.top,
                   objectHitBox.top + objectHitBox.height - playerHitBox.top);

      // Check if the player is above the object (touching its top side).
      if (dx < dy) {
        // Colliding on the x-axis (sides).
        if (playerHitBox.left + playerHitBox.width < objectHitBox.left) {
          player.setSpeed(sf::Vector2f(0.0f, player.getSpeed().x));
          player.canMove = false;

          // Collided on the left side of the object, push player to the right.
          float newX = objectHitBox.left - playerHitBox.width;
          player.set_position(newX, player.get_y_cord());
          player.setSpeed(sf::Vector2f(0.0f, player.getSpeed().y));
        } else {
          player.setSpeed(sf::Vector2f(0.0f, player.getSpeed().x));
          player.canMove = false;

          // Collided on the right side of the object, push player to the left.
          float newX = objectHitBox.left + objectHitBox.width;
          player.set_position(newX, player.get_y_cord());
          player.setSpeed(sf::Vector2f(0.0f, player.getSpeed().y));
        }
      } else {
        // Colliding on the y-axis (top or bottom).
        if (playerHitBox.top = objectHitBox.top + objectHitBox.height) {
          // Collided on the bottom of the object, push player up.

          float newY = objectHitBox.top + objectHitBox.height;
          player.set_position(player.get_x_cord(), newY);
          player.canMove = false;

          player.setSpeed(sf::Vector2f(player.getSpeed().x, 0.0f));
          std::cout << player.get_x_cord() << std::endl;
          std::cout << player.get_y_cord() << std::endl;

        } else {
          player.setSpeed(sf::Vector2f(player.getSpeed().x, 0.0f));
          // player.canMove = false;

          // Collided on the top of the object, push player down.
          float newY = objectHitBox.top - playerHitBox.height;
          player.set_position(player.get_x_cord(), newY);
        }
      }
    }
  }

  // Update the player's position based on the modified x and y values.
  player.set_position(playerX, playerY);
  player.canMove = true;

  // Apply gravity using the physics class.

  return collisionDetected;
}
