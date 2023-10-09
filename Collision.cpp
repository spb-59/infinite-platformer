#include "Collision.hpp"

#include <iostream>

Collision::Collision() {}

bool Collision::detect_collision(std::vector<Object *> &boxes, Player &player) {
  for (Object *&p : boxes) {
    if ((player.getHitBox()).intersects(p->getHitBox())) {
      player.setSpeed(sf::Vector2f(player.getSpeed().x, 0.0f));
      if (p->get_isDeadly() == true) {
        std::cout << " GAME OVER";
      }

    } else {
    }
  }
}
