#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Button.hpp"
#include "../include/Gamestate.hpp"

enum MenuState { PLAY = 0, HOW_TO_PLAY = 1, QUIT = 2, MAIN_MENU = 3 };

class Menu {
 protected:
  int currentScore;
  int highestCore;
  std::vector<Button*> buttons;
  MenuState menuState;
  sf::RenderWindow* menu_window;
  sf::Font font;
  bool isMenu = true;
  bool isGameOver = false;

 public:
  Menu(sf::RenderWindow* window);
  void setCurrentScore(int score);
  void setHighestScore(int score);

  void handleEvents();
  void run();

  void setIsGameOver();

  MenuState getMenuState();
  void setMenuState(MenuState);

  ~Menu();
};

#endif