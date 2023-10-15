#ifndef GENERATION_H
#define GENERATION_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Object.hpp"

class Generation {
 private:
  std::vector<double> probabilities;
  int event = 100;

  float base_y_cord = 500.0f;
  const float max_Yjump = 10.0f;
  const float max_Xjump = 20.0f;
  int platformCounter = 0;
  int lavaCounter = 0;
  int spikeCounter = 0;

 public:
  Generation();

  void makeTerrain(std::vector<Object *> &boxes, sf::Vector2f center);
  void makeInfinite(std::vector<Object *> &boxes, sf::Vector2f center);
  void generateTerrain(std::vector<Object *> &boxes, float x, int rand,
                       float add_y);
  int generate(std::vector<double> probabilities);

  void optimize(std::vector<Object *> &boxes, sf::Vector2f center);

  void applyRules(std::vector<Object *> &boxes);

  ~Generation();
};

#endif
