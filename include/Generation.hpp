#ifndef GENERATION_HPP
#define GENERATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Object.hpp"

class Generation {
 private:
  std::vector<double> probabilities;
  int event = 0;
  int event2 = 0;
  bool changed = true;
  float add_y = 0;

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
  void generateTerrain(std::vector<Object *> &boxes, int rand, float add_y);
  int generate(std::vector<double> probabilities);

  void transition(std::vector<Object *> &boxes, float randomValue, float add_y);

  void optimize(std::vector<Object *> &boxes, sf::Vector2f center);

  void applyRules(std::vector<Object *> &boxes);

  ~Generation();
};

#endif