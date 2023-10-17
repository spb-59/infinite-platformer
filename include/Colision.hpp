#ifndef COLLISION_H
#define COLLISION_H

#include "./LavaWall.hpp"
#include "./Object.hpp"
#include "./Physics.hpp"
#include "./Player.hpp"

class Collision {
 private:
  bool deadlyCollision = false; 

 public:
  // Default constructor
  Collision();

  // Detect collisions between the player and a collection of objects (boxes)
  bool detect_collision(std::vector<Object *> &boxes, Player &player);

  // Detect collisions between the player and a specific LavaWall
  bool detect_wall_collision(LavaWall &wall, Player &player);

  // Set the deadlyCollision flag to indicate a deadly collision occurred
  void set_deadlyCollision();

  // Get the value of the deadlyCollision flag
  bool get_deadlyCollision();

  // Set the deadlyCollision flag specifically for wall collisions
  void set_deadlyCollision_wall();

  // Get the value of the deadlyCollision flag for wall collisions
  bool get_deadlyCollision_wall();
};

#endif
