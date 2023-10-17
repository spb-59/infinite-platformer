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
  Collision();
  bool detect_collision(std::vector<Object *> &boxes, Player &player);
  bool detect_wall_collision(LavaWall &wall, Player &player);
  void set_deadlyCollision();
  bool get_deadlyCollision();
  void set_deadlyCollision_wall();
  bool get_deadlyCollision_wall();
};

#endif
