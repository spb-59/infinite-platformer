#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>

class Game {
 private:
  sf::RenderWindow* Window;  // Pointer to the game window
  int x_dimension;  // Width of the game window
  int y_dimension;  // Height of the game window
  std::string title; // Title of the game window

 public:
  // Constructor for the Game class, takes window dimensions and a title
  Game(int x_dimension, int y_dimension, const std::string title);

  // Run the game
  void run();

  // Get the width of the game window
  int get_x_dimension() const;

  // Get the height of the game window
  int get_y_dimension() const;

  // Get the title of the game window
  std::string get_title() const;

  // Destructor for the Game class
  ~Game();
};

#endif
