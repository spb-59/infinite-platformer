#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
// class to make platforms in game

class platform {
 private:
  sf::RectangleShape box;

 public:
  platform(float x, float y, sf::Vector2f(size));
  void render(sf::RenderWindow* window);

  ~platform();
};

#endif
