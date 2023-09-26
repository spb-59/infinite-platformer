#ifndef GENERATION_H
#define GENRATION_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "platform.h"

class Generation {
 private:
 public:
  Generation();

  void makeTerrain(std::vector<platform> &boxes, sf::Vector2f center);

  ~Generation();
};

#endif