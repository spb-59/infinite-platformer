#include "../include/Physics.hpp"

#include <iostream>

#include "../include/Entity.hpp"
#include "../include/Player.hpp"

Physics::Physics(float gravity) : gravity(gravity) {}

void Physics::addGravity(Entity& obj) {
  obj.setSpeed(sf::Vector2f(obj.getSpeed().x, gravity));
  //   std::cout << " " << obj.getSpeed().y;
}