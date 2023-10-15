#include <iostream>

#include "../include/Game.hpp"
int main() {
  Game game(1280, 720, "Game");
  game.run();
  std::cout << "Hello world!" << std::endl;

  return 0;
}
