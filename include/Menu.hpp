#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Button.hpp"
#include "../include/Gamestate.hpp"

// Enumeration defining possible menu states
enum MenuState { PLAY = 0, HOW_TO_PLAY = 1, QUIT = 2, MAIN_MENU = 3 };

class Menu {
 protected:
 // initialise elements and variables 
  int currentScore;               
  int highestCore;              
  std::vector<Button*> buttons;  
  MenuState menuState;          
  sf::RenderWindow* menu_window; 
  sf::Font font;                
  bool isMenu = true;       
  bool isGameOver = false;       

 public:
  // Constructor for the Menu class, takes a pointer to the menu window
  Menu(sf::RenderWindow* window);

  // Set the current score
  void setCurrentScore(int score);

  // Set the highest score
  void setHighestScore(int score);

  // Handle events in the menu
  void handleEvents();

  // Run the menu
  void run();

  // Set the game over flag
  void setIsGameOver();

  // Get the current menu state
  MenuState getMenuState();

  // Set the menu state to a new menu state
  void setMenuState(MenuState newState);

  // Destructor
  ~Menu();
};

#endif