
#include "../include/Generation.hpp"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#include "../include/LavaPit.hpp"
#include "../include/Object.hpp"
#include "../include/Platform.hpp"
#include "../include/Spikes.hpp"

Generation::Generation() { probabilities = {0.4, 0.3, 0.2, 0.1}; }

void Generation::makeTerrain(std::vector<Object*>& boxes, sf::Vector2f center) {
  float add_x = 0.0f;

  std::cout << "Start";
  for (Object*& p : boxes) {
    p = new Platform();
  }

  for (Object*& p : boxes) {
    p->set_position(100.0f + add_x, base_y_cord);
    p->set_size(sf::Vector2f(1.0f, 1.0f));
    add_x += 50.0f;
  }
}

void Generation::makeInfinite(std::vector<Object*>& boxes,
                              sf::Vector2f center) {
  // getting x coordinate of last object

  float x = boxes.back()->get_x_cord();

  // condtion to limit the number of boxes rendered
  if (boxes.size() < 20 || boxes.back()->get_x_cord() - 750.0f <= center.x) {
    float add_x = 50.0f;  // float to add to the x cord
    float add_y = 0;
    int rand1 = 0;

    std::vector<double> prob = {0.9, 0.1};
    rand1 = generate(prob);

    bool changed = true;

    if (event > 30) {
      if (event < 60 && changed) {
        std::cout << "THIS RAN\n";

        std::cout << "Value changed ";
        // Seed the random number generator with the current time
        std::mt19937_64 rng(std::time(0));

        // Define a range for the random number (200 to 400)
        std::uniform_real_distribution<float> dist(-200.0, 200.0);

        // Generate a random float number within the specified range
        float randomValue = dist(rng);

        add_y = randomValue;
      } else if (event > 60) {
        changed = false;
        event = 0;
      } else {
        changed = true;
      }
    }

    event++;

    generateTerrain(boxes, x, rand1, add_y);
  }
}

void Generation::generateTerrain(std::vector<Object*>& boxes, float x,
                                 int rand1, float add_y) {
  float add_x = 50.0f;

  applyRules(boxes);

  int rand = generate(probabilities);  // function returns 0,1,2
                                       // generate objects accordingly

  switch (rand) {
    case 0:

      if (platformCounter <= 1) {
        boxes.push_back(new Platform(x + add_x, base_y_cord + add_y,
                                     sf::Vector2f(1.0f, 1.0f)));
        boxes.push_back(new Platform(x + add_x * 2, base_y_cord + add_y,
                                     sf::Vector2f(1.0f, 1.0f)));
        boxes.push_back(new Platform(x + add_x * 3, base_y_cord + add_y,
                                     sf::Vector2f(1.0f, 1.0f)));
        boxes.push_back(new Platform(x + add_x * 4, base_y_cord + add_y,
                                     sf::Vector2f(1.0f, 1.0f)));

        platformCounter++;
        lavaCounter = 0;
        spikeCounter = 0;
      }

      break;

    case 1:

      if (lavaCounter <= 1 && !(boxes.back()->get_type() == "SPIKES")) {
        boxes.push_back(new LavaPit(x + add_x, base_y_cord + add_y,
                                    sf::Vector2f(1.0f, 1.0f)));

        boxes.push_back(new LavaPit(x + add_x * 2, base_y_cord + add_y,
                                    sf::Vector2f(1.0f, 1.0f)));

        platformCounter = 0;
        spikeCounter = 0;
        lavaCounter++;
      }

      break;

    case 2:

      if (spikeCounter <= 1 && !(boxes.back()->get_type() == "LAVA")) {
        boxes.push_back(new Platform(x + add_x, base_y_cord + add_y,
                                     sf::Vector2f(1.0f, 1.0f)));
        boxes.push_back(new Spikes(x + add_x, base_y_cord - 50 + add_y,
                                   sf::Vector2f(1.0f, 1.0f)));

        spikeCounter++;
        lavaCounter = 0;
        platformCounter = 0;
      }

      break;

    default:
      break;
  }
}

int Generation::generate(std::vector<double> probabilities) {
  // Create a random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::discrete_distribution<int> dist(probabilities.begin(),
                                       probabilities.end());
  return dist(gen);
}

void Generation::optimize(std::vector<Object*>& boxes, sf::Vector2f center) {
  // std::cout << "No of Obj: " << boxes.size() << " \n";

  for (Object*& p : boxes) {
    if (p->get_x_cord() < center.x - 750.0f) {
      delete p;
      p = nullptr;
    }
  }
  boxes.erase(std::remove(boxes.begin(), boxes.end(), nullptr), boxes.end());
}

void Generation::applyRules(std::vector<Object*>& boxes) {
  int size = boxes.size() - 1;

  if (boxes[size]->get_isDeadly() && boxes[size - 1]->get_isDeadly() &&
      boxes[size - 2]->get_isDeadly() && boxes[size - 4]->get_isDeadly()) {
    float x = boxes.back()->get_x_cord();
    float add_x = 50.0f;

    boxes.push_back(
        new Platform(x + add_x, base_y_cord, sf::Vector2f(1.0f, 1.0f)));
    boxes.push_back(
        new Platform(x + add_x * 2, base_y_cord, sf::Vector2f(1.0f, 1.0f)));
    boxes.push_back(
        new Platform(x + add_x * 3, base_y_cord, sf::Vector2f(1.0f, 1.0f)));
    boxes.push_back(
        new Platform(x + add_x * 4, base_y_cord, sf::Vector2f(1.0f, 1.0f)));

    std::cout << "IMPOSSIBLE DETECTED \n";
  }
}

Generation::~Generation() {}