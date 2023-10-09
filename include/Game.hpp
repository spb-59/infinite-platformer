#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Gamestate.hpp"

class Game {
 protected:
  sf::RenderWindow window;
  Gamestate state;
  sf::Texture texture;
  sf::Texture background;

 public:
  Game();
  ~Game();
  void run();
  sf::RenderWindow& getWindow();
  Gamestate getState();
  void setState(Gamestate);
};

#endif
