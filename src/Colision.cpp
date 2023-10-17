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
#include "../include/Colision.hpp"

#include <iostream>

Collision::Collision() {}

bool Collision::detect_collision(std::vector<Object*>& boxes, Player& player) {
  bool collisionDetected = false;

  // Get player x and y positions.
  float playerX = player.get_x_cord();
  float playerY = player.get_y_cord();

  // Get player hitbox once to avoid repeated calls.
  sf::FloatRect nextPos;
  sf::RectangleShape nextPlayerPos;
  nextPlayerPos.setSize(sf::Vector2f(51.f, 51.f));
  nextPlayerPos.setFillColor(sf::Color ::Green);

  // Iterate through each object in the boxes vector.
  for (Object*& p : boxes) {
    sf::FloatRect playerHitBox = player.getHitBox();
    sf::FloatRect objectHitBox = p->getHitBox();

    nextPos = playerHitBox;
    nextPos.left += player.getSpeed().x;
    nextPos.top += player.getSpeed().y;
    float newX =
        player.get_x_cord();  // Initialize to the player's current position.
    float newY = player.get_y_cord();

    if (objectHitBox.intersects(nextPos)) {
      collisionDetected = true;

      // Calculate the overlap on each side.
      float dx =
          std::min(playerHitBox.left + playerHitBox.width - objectHitBox.left,
                   objectHitBox.left + objectHitBox.width - playerHitBox.left);
      float dy = std::min(
          player.get_y_cord() + playerHitBox.height - objectHitBox.top,
          objectHitBox.top + objectHitBox.height - player.get_y_cord());

      // Check if the player is above the object (touching its top side).
      if (dx < dy) {
        // Colliding on right of the platform
        // std::cout << playerHitBox.left;
        // if (playerHitBox.left + playerHitBox.width < objectHitBox.left) {
        if (playerHitBox.left < objectHitBox.left &&
            playerHitBox.left + playerHitBox.width <
                objectHitBox.left + objectHitBox.width &&
            playerHitBox.top < objectHitBox.top + objectHitBox.height &&
            objectHitBox.top < playerHitBox.top + playerHitBox.height) {
          // std::cout << std::endl << "collided left: " << std::endl;

          // Colliding on left of the platform
          newX = objectHitBox.left - playerHitBox.width - 10;
          newY = player.get_y_cord();

          // std::cout << "initial x: " << player.get_x_cord() << std::endl;
          // std::cout << "initial y: " << player.get_y_cord() << std::endl;

          player.setSpeed(sf::Vector2f(0.0f, player.getSpeed().y));

          // Collided on the right side of the object, push player to the
          player.set_position(newX, newY);
          // std::cout << "altered x: " << newX << std::endl;
          // std::cout << "altered y: " << newY << std::endl;

          // std::cout << "final x: " << player.get_x_cord() << std::endl;
          // std::cout << "final y: " << player.get_y_cord() << std::endl;
        } else if (playerHitBox.left > objectHitBox.left &&
                   playerHitBox.left + playerHitBox.width >
                       objectHitBox.left + objectHitBox.width &&
                   playerHitBox.top < objectHitBox.top + objectHitBox.height &&
                   objectHitBox.top < playerHitBox.top + playerHitBox.height) {
          // std::cout << std::endl << "collided right: " << std::endl;
          //  Colliding on left of the platform
          newX = objectHitBox.left + playerHitBox.width + 10;
          newY = player.get_y_cord();

          // std::cout << "initial x: " << player.get_x_cord() << std::endl;
          // std::cout << "initial y: " << player.get_y_cord() << std::endl;

          player.setSpeed(sf::Vector2f(0.0f, player.getSpeed().y));

          // Collided on the right side of the object, push player to the
          player.set_position(newX, newY);
          // std::cout << "altered x: " << newX << std::endl;
          // std::cout << "altered y: " << newY << std::endl;

          // std::cout << "final x: " << player.get_x_cord() << std::endl;
          // std::cout << "final y: " << player.get_y_cord() << std::endl;
        }
      } else if (playerHitBox.top < objectHitBox.top &&
                 playerHitBox.top + playerHitBox.height <
                     objectHitBox.top + objectHitBox.height &&
                 playerHitBox.left < objectHitBox.left + objectHitBox.width &&
                 objectHitBox.left < playerHitBox.left + playerHitBox.width) {
        player.setSpeed(sf::Vector2f(player.getSpeed().x, 0.0f));
        // std::cout << std::endl << "collided top: " << std::endl;

        newX = player.get_x_cord();

        newY = objectHitBox.top - playerHitBox.height;
        player.set_landed(true);
        // player.set_position(newX, newY);
      } else if (playerHitBox.top > objectHitBox.top &&
                 playerHitBox.top + playerHitBox.height >
                     objectHitBox.top + objectHitBox.height &&
                 playerHitBox.left < objectHitBox.left + objectHitBox.width &&
                 objectHitBox.left < playerHitBox.left + playerHitBox.width) {
        // std::cout << std::endl << "collided bottom: " << std::endl;

        newX = player.get_x_cord();

        newY = objectHitBox.top + playerHitBox.height + 10;
        player.set_position(newX, newY);
        player.set_landed(true);

        // // player.setSpeed(sf::Vector2f(player.getSpeed().x, 0.0f));
        // std::cout << player.get_x_cord() << std::endl;
        // std::cout << player.get_y_cord() << std::endl;
      }
    }
  }
  // if (collisionDetected) {
  //   player.set_position(newX, newY);
  //   std::cout << "altered x: " << newX << std::endl;
  //   std::cout << "altered y: " << player.get_y_cord() << std::endl;

  //   // player.set_x_cord(newX);
  // player.set_position(player.get_x_cord(), player.get_y_cord());

  // player.move_position(player.get_x_cord(), player.get_y_cord());
  //   std::cout << "final x: " << player.get_x_cord() << std::endl;
  //   std::cout << "final y: " << player.get_y_cord() << std::endl;

  return collisionDetected;
}

// Apply gravity using the physics class.