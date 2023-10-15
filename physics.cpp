#include "physics.hpp"

#include <iostream>

#include "Entity.hpp"
#include "Player.hpp"

physics::physics(float gravity) : gravity(gravity) {}

void physics::addGravity(Entity& obj) {
  obj.setSpeed(sf::Vector2f(obj.getSpeed().x, gravity));
  //   std::cout << " " << obj.getSpeed().y;
}
