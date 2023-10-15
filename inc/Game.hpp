#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Game {
 private:
  sf::RenderWindow* Window;

  int x_dimension;
  int y_dimension;
  std::string title;

 public:
  Game(int x_dimension, int y_dimension, const std::string title);
  void run();
  int get_x_dimension() const;
  int get_y_dimension() const;
  std::string get_title() const;
  ~Game();
};
