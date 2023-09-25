#ifndef GAME_H
#define GAME_H

// class to intiliaze the game window

#include <SFML/Graphics.hpp>

class game {
 public:
  sf::RenderWindow* Window;
  sf::Texture texture;

  game();
  void run();
  ~game();
};

#endif