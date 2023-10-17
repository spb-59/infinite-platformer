#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Button.hpp"
#include "../include/Gamestate.hpp"

enum MenuState { PLAY = 0, HOW_TO_PLAY = 1, QUIT = 2, MAIN_MENU = 3 };

class Menu {
 protected:
  int currentScore;         // The current score
  int highestCore;          // The highest score achieved
  std::vector<Button*> buttons;  // Collection of buttons on the menu
  MenuState menuState;      // The current state of the menu
  sf::RenderWindow* menu_window;  // Pointer to the menu window
  sf::Font font;            // Font used for text
  bool isMenu = true;       // Flag indicating if it's a menu
  bool isGameOver = false;  // Flag indicating if the game is over

 public:
  // Constructor for the Menu class, takes a pointer to the menu window
  Menu(sf::RenderWindow* window);

  // Set the current score
  void setCurrentScore(int score);

  // Set the highest score achieved
  void setHighestScore(int score);

  // Handle events (e.g., button clicks) in the menu
  void handleEvents();

  // Run the menu
  void run();

  // Set the game over boolean
  void setIsGameOver();

  // Get the current menu state
  MenuState getMenuState();

  // Set the menu state to a new state
  void setMenuState(MenuState newState);

  // Destructor for the Menu class
  ~Menu();
};

#endif 
