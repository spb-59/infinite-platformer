#ifndef COLLISION_H
#define COLLISION_H

#include "./Object.hpp"
#include "./Physics.hpp"
#include "./Player.hpp"

class Collision {
 private:
  bool deadlyCollision = false;

 public:
  Collision();
  bool detect_collision(std::vector<Object *> &boxes, Player &player);
  void set_deadlyCollision();
  bool get_deadlyCollision();
};

#endif
