#include "Generation.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#include "platform.h"

Generation::Generation() {}

void Generation::makeTerrain(std::vector<platform>& boxes,
                             sf::Vector2f center) {
  float add = 0.0f;

  for (platform& p : boxes) {
    p.setDimensions(100.0f + add, base_y_cord, sf::Vector2f(100.0f, 100.0f));
    add += 100.0f;
  }
}

void Generation::makeInfinite(std::vector<platform>& boxes,
                              sf::Vector2f center) {
  float x = boxes.back().get_Xcord();

  float add = 100.0f;
  std::cout << "more stuff";
  boxes.push_back(platform(x + add, base_y_cord - generate(x),
                           sf::Vector2f(100.0f, 100.0f)));
  add += 100.0f;
}

float Generation::generate(float x_cord) {
  // Create a random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  float minNum = 0.0f;
  float maxNum = 450.0f;
  std::uniform_real_distribution<float> dist(minNum, maxNum);
  return dist(gen);
}

void Generation::optimize(std::vector<platform>& boxes, sf::Vector2f center) {
  for (platform& p : boxes) {
    if (p.get_Xcord() < center.x) {
      delete &p;
    }
  }
}

Generation::~Generation() {}