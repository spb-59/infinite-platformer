#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Gamestate.hpp"

class Game {
 protected:
  sf::RenderWindow window;
  Gamestate state;

 public:
  Game();
  void run();
};

#endif
