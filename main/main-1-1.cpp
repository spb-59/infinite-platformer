#include "Game.hpp"
#include "Menu.hpp"

int main(int argc, char const *argv[]) {
  Menu game(1280, 720);
  game.run();

  return 0;
}
