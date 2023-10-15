#ifndef COLLISION_H
#define COLLISION_H

#include "./Object.hpp"
#include "./Player.hpp"
#include "./Physics.hpp"

class Collision {
 private:
 public:
  Collision();
  bool detect_collision(std::vector<Object *> &boxes, Player &player);
};

#endif
