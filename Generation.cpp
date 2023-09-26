#include "Generation.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "platform.h"

Generation::Generation() {}

void Generation::makeTerrain(std::vector<platform>& boxes,
                             sf::Vector2f center) {
  float x = 0.0f;

  for (platform& p : boxes) {
    p.setDimensions(100.0f + x, 100.0f + x, sf::Vector2f(100.0f, 100.0f));
    x = x + 100.0f;
    std::cout << "doing stuuf";
  }
}

Generation::~Generation() {}