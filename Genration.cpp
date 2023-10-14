
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#include "Generation.hpp"
#include "LavaPit.hpp"
#include "Object.hpp"
#include "Platform.hpp"
#include "Spikes.hpp"

Generation::Generation() { probabilities = {0.4, 0.3, 0.2, 0.1}; }

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
  // getting x coordinate of last object

  float x = boxes.back()->get_x_cord();

  // condtion to limit the number of boxes rendered
  if (boxes.size() < 20 || boxes.back()->get_x_cord() - 750.0f <= center.x) {
    float add = 50.0f;  // float to add to the x coord

    int rand =
        generate(x);  // function returns 0,1,2 generate objects accordingly

    switch (rand) {
      case 0:

        if (platformCounter <= 1) {
          boxes.push_back(
              new Platform(x + add, base_y_cord, sf::Vector2f(1.0f, 1.0f)));
          boxes.push_back(
              new Platform(x + add * 2, base_y_cord, sf::Vector2f(1.0f, 1.0f)));
          boxes.push_back(
              new Platform(x + add * 3, base_y_cord, sf::Vector2f(1.0f, 1.0f)));
          boxes.push_back(
              new Platform(x + add * 4, base_y_cord, sf::Vector2f(1.0f, 1.0f)));

          platformCounter++;
          lavaCounter = 0;
          spikeCounter = 0;
        }

        break;

      case 1:

        if (lavaCounter <= 1 && !(boxes.back()->get_type() == "SPIKES")) {
          boxes.push_back(
              new LavaPit(x + add, base_y_cord, sf::Vector2f(1.0f, 1.0f)));

          boxes.push_back(
              new LavaPit(x + add * 2, base_y_cord, sf::Vector2f(1.0f, 1.0f)));

          platformCounter = 0;
          spikeCounter = 0;
          lavaCounter++;
        }
        // else {
        //   boxes.push_back(
        //       new Platform(x + add, base_y_cord, sf::Vector2f(1.0f, 1.0f)));
        //   boxes.push_back(
        //       new Spikes(x + add, base_y_cord - 50,
        //       sf::Vector2f(1.0f, 1.0f)));

        //   spikeCounter++;
        //   lavaCounter = 0;
        //   platformCounter = 0;
        // }

        break;

      case 2:

        if (spikeCounter <= 1 && !(boxes.back()->get_type() == "LAVA")) {
          boxes.push_back(
              new Platform(x + add, base_y_cord, sf::Vector2f(1.0f, 1.0f)));
          boxes.push_back(
              new Spikes(x + add, base_y_cord - 50, sf::Vector2f(1.0f, 1.0f)));

          spikeCounter++;
          lavaCounter = 0;
          platformCounter = 0;
        }

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
  for (Object*& p : boxes) {
    if (p->get_x_cord() < center.x - 750.0f) {
      delete p;
      p = nullptr;
    }
  }
  boxes.erase(std::remove(boxes.begin(), boxes.end(), nullptr), boxes.end());
}

Generation::~Generation() {}
