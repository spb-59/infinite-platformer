#pragma once

#include "Object.hpp"
#include "Player.hpp"
#include "Wall.hpp"

class Collision {
 private:
 public:
  Collision();
  bool detect_collision(std::vector<Object *> &boxes, Player &player);
  bool detect_collision(Wall &wall, Player &player);
};
