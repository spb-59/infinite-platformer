#pragma once

#include "Object.hpp"
#include "Player.hpp"
#include "physics.hpp"

class Collision {
 private:
 public:
  Collision();
  bool detect_collision(std::vector<Object *> &boxes, Player &player);
};
