
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#include "Generation.hpp"
#include "LavaPit.hpp"
#include "Object.hpp"
#include "Platform.hpp"

Generation::Generation() { probabilities = {0.7, 0.2, 0.1}; }

void Generation::makeTerrain(std::vector<Object*>& boxes, sf::Vector2f center) {
  float add = 0.0f;

  std::cout << "Start";
  for (Object*& p : boxes) {
    p = new Platform();
  }

  for (Object*& p : boxes) {
    p->set_position(100.0f + add, base_y_cord);
    p->set_size(sf::Vector2f(1.0f, 1.0f));
    add += 50.0f;
  }
}

void Generation::makeInfinite(std::vector<Object*>& boxes,
                              sf::Vector2f center) {
  float x = boxes.back()->get_x_cord();

  // std::cout << boxes.back()->get_x_cord() << " "
  //           << "\n"
  //           << center.x << "  \n";

  if (boxes.size() < 20 || boxes.back()->get_x_cord() - 1000.0f <= center.x) {
    float add = 50.0f;

    int rand = generate(x);
    std::cout << rand << "  \n";

    switch (rand) {
      case 0:
        boxes.push_back(
            new Platform(x + add, base_y_cord, sf::Vector2f(1.0f, 1.0f)));

        break;

      case 1:
        boxes.push_back(
            new LavaPit(x + add, base_y_cord, sf::Vector2f(1.0f, 1.0f)));
        break;

      case 2:
        boxes.push_back(
            new Platform(x + add, base_y_cord - 200, sf::Vector2f(1.0f, 1.0f)));
        break;

      default:
        break;
    }
  }
}

int Generation::generate(float x_cord) {
  // Create a random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::discrete_distribution<int> dist(probabilities.begin(),
                                       probabilities.end());
  return dist(gen);
}

void Generation::optimize(std::vector<Object*>& boxes, sf::Vector2f center) {
  for (auto it = boxes.begin(); it != boxes.end(); /* No increment here */) {
    Object* p = *it;  // Get the pointer from the iterator
    if (p->get_x_cord() < center.x - 1000.0f) {
      delete p;
      it = boxes.erase(
          it);  // Remove the pointer from the vector and update the iterator
    } else {
      ++it;  // Move to the next element in the vector
    }
  }
}

Generation::~Generation() {}
