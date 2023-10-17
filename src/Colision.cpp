// Include the Collision header file.
#include "../include/Colision.hpp"

#include "../include/LavaWall.hpp"

// Include the C++ Standard Library's input/output stream.
#include <iostream>

// Define the constructor for the Collision class.
Collision::Collision() {}

// Define the 'detect_collision' function for the Collision class.
// This function checks for collisions between the player and objects.
bool Collision::detect_collision(std::vector<Object*>& boxes, Player& player) {
  // Initialize a variable to track whether a collision has been detected.
  bool collisionDetected = false;

  // Get the player's current x and y positions.
  float playerX = player.get_x_cord();
  float playerY = player.get_y_cord();

  // Initialize variables to store the next position.
  sf::FloatRect nextPos;
  sf::RectangleShape nextPlayerPos;
  nextPlayerPos.setSize(sf::Vector2f(51.f, 51.f));
  nextPlayerPos.setFillColor(sf::Color::Green);

  // Iterate through each object in the 'boxes' vector.
  for (Object*& p : boxes) {
    // Get the hitboxes for the player and the current object.
    sf::FloatRect playerHitBox = player.getHitBox();
    sf::FloatRect objectHitBox = p->getHitBox();

    // Update the 'nextPos' with the player's next position based on their
    // speed.
    nextPos = playerHitBox;
    nextPos.left += player.getSpeed().x;
    nextPos.top += player.getSpeed().y;

    // Initialize 'newX' and 'newY' with the player's current position.
    float newX = player.get_x_cord();
    float newY = player.get_y_cord();

    // Check if the player's next position intersects with the object's hitbox.
    if (objectHitBox.intersects(nextPos)) {
      // Check if the object is deadly, and set the deadly collision flag
      // accordingly.
      if (p->get_isDeadly()) set_deadlyCollision();

      // Set 'collisionDetected' to true since a collision has been detected.
      collisionDetected = true;

      // Calculate the overlap on each side of the collision.
      float dx =
          std::min(playerHitBox.left + playerHitBox.width - objectHitBox.left,
                   objectHitBox.left + objectHitBox.width - playerHitBox.left);
      float dy = std::min(
          player.get_y_cord() + playerHitBox.height - objectHitBox.top,
          objectHitBox.top + objectHitBox.height - player.get_y_cord());

      // Check the type of collision based on the overlap.
      if (dx < dy) {
        // Colliding on the left side of the platform.
        if (playerHitBox.left < objectHitBox.left &&
            playerHitBox.left + playerHitBox.width <
                objectHitBox.left + objectHitBox.width &&
            playerHitBox.top < objectHitBox.top + objectHitBox.height &&
            objectHitBox.top < playerHitBox.top + playerHitBox.height) {
          newX = objectHitBox.left - playerHitBox.width - 10;
          newY = player.get_y_cord();
          player.setSpeed(sf::Vector2f(0.0f, player.getSpeed().y));
          player.set_position(newX, newY);
        } else if (playerHitBox.left > objectHitBox.left &&
                   playerHitBox.left + playerHitBox.width >
                       objectHitBox.left + objectHitBox.width &&
                   playerHitBox.top < objectHitBox.top + objectHitBox.height &&
                   objectHitBox.top < playerHitBox.top + playerHitBox.height) {
          newX = objectHitBox.left + playerHitBox.width + 10;
          newY = player.get_y_cord();
          player.setSpeed(sf::Vector2f(0.0f, player.getSpeed().y));
          player.set_position(newX, newY);
        }
      } else if (playerHitBox.top < objectHitBox.top &&
                 playerHitBox.top + playerHitBox.height <
                     objectHitBox.top + objectHitBox.height &&
                 playerHitBox.left < objectHitBox.left + objectHitBox.width &&
                 objectHitBox.left < playerHitBox.left + playerHitBox.width) {
        // Colliding on the top of the platform.
        player.setSpeed(sf::Vector2f(player.getSpeed().x, 0.0f));
        newX = player.get_x_cord();
        newY = objectHitBox.top - playerHitBox.height;
        player.set_landed(true);
      } else if (playerHitBox.top > objectHitBox.top &&
                 playerHitBox.top + playerHitBox.height >
                     objectHitBox.top + objectHitBox.height &&
                 playerHitBox.left < objectHitBox.left + objectHitBox.width &&
                 objectHitBox.left < playerHitBox.left + playerHitBox.width) {
        // Colliding on the bottom of the platform.
        newX = player.get_x_cord();
        newY = objectHitBox.top + playerHitBox.height + 10;
        player.set_position(newX, newY);
        player.set_landed(true);
      }
    }
  }

  // Return whether a collision has been detected.
  return collisionDetected;
}

// Define the 'set_deadlyCollision' function for the Collision class.
void Collision::set_deadlyCollision() { deadlyCollision = true; }

// Define the 'get_deadlyCollision' function for the Collision class.
// This function returns the status of deadly collisions.
bool Collision::get_deadlyCollision() { return deadlyCollision; }

bool Collision::detect_wall_collision(LavaWall& wall, Player& player) {
  if ((player.getHitBox()).intersects(wall.getHitBox())) {
    std::cout << " GAME OVER";
    return true;
  }
  return false;
}
