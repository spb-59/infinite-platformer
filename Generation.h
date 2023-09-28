#ifndef GENERATION_H
#define GENRATION_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "platform.h"

class Generation {
 private:
  std::vector<double> probabilities;
  int event;
  const float base_y_cord = 500.0f;

 public:
  Generation();

  void makeTerrain(std::vector<platform> &boxes, sf::Vector2f center);
  void makeInfinite(std::vector<platform> &boxes, sf::Vector2f center);
  float generate(float x_cord);
  void optimize(std::vector<platform> &boxes, sf::Vector2f center);

  ~Generation();
};

#endif()