#ifndef GENERATION_H
#define GENRATION_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Object.hpp"

class Generation {
 private:
  std::vector<double> probabilities;
  int event;
  float base_y_cord = 500.0f;

 public:
  Generation();

  void makeTerrain(std::vector<Object *> &boxes, sf::Vector2f center);
  void makeInfinite(std::vector<Object *> &boxes, sf::Vector2f center);
  int generate(float x_cord);
  void optimize(std::vector<Object *> &boxes, sf::Vector2f center);

  ~Generation();
};

#endif
