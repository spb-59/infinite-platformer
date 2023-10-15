#ifndef PHYSICS_H
#define PHYSICS_H

#include "Entity.hpp"

class Physics {
 private:
  float gravity;

 public:
  Physics(float gravity);

  void addGravity(Entity& obj);
};

#endif
