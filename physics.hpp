#pragma once

#include "Entity.hpp"

class physics {
 private:
  float gravity;

 public:
  physics(float gravity);

  void addGravity(Entity& obj);
};
