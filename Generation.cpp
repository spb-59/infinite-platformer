#include "Generation.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "platform.h"

Generation::Generation() {}

void Generation::makeTerrain(std::vector<platform>& boxes,
                             sf::Vector2f center) {
  float add = 0.0f;

  for (platform& p : boxes) {
    p.setDimensions(100.0f + add, 100.0f, sf::Vector2f(100.0f, 100.0f));
    add += 100.0f;
  }
}

void Generation::makeInfinite(std::vector<platform>& boxes,
                              sf::Vector2f center) {
  float x = boxes.back().get_Xcord();

  float add = 100.0f;
  std::cout << "more stuff";
  boxes.push_back(platform(x + add, 100.0f, sf::Vector2f(100.0f, 100.0f)));
  add += 100.0f;
}

Generation::~Generation() {}