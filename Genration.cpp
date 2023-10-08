
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#include "Generation.hpp"
#include "Object.hpp"
#include "Platform.hpp"

Generation::Generation() {}

void Generation::makeTerrain(std::vector<Object*>& boxes, sf::Vector2f center) {
  float add = 0.0f;

  std::cout << "Start";
  for (Object*& p : boxes) {
    p = new Platform();
  }

  for (Object*& p : boxes) {
    p->set_position(100.0f + add, base_y_cord);
    p->set_size(sf::Vector2f(1.0f, 1.0f));
    add += 100.0f;
  }
}

void Generation::makeInfinite(std::vector<Object*> boxes, sf::Vector2f center) {
  float x = boxes.back()->get_x_cord();

  float add = 100.0f;
  std::cout << "more stuff";
  boxes.push_back(new Object(x + add, base_y_cord - generate(x),
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

void Generation::optimize(std::vector<Object*>& boxes, sf::Vector2f center) {
  for (Object* p : boxes) {
    if (p->get_x_cord() < center.x) {
      delete p;
    }
  }
}

Generation::~Generation() {}
