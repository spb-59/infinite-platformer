#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
 protected:
  sf::Text text;   // Text element for the button
  sf::Font font;   // Font used for the button's text

 public:
  // Default constructor
  Button();

  // Constructor with parameters for button name, text size, and number of options
  Button(std::string name, int size, int numOptions);

  // Set the position of the button
  void setPosition(sf::Vector2f pos);

  // Set the fill color of the button
  void setFillColor(sf::Color color);

  // Set the name (text) displayed on the button
  void setName(std::string name);

  // Set the font for the button's text
  void setFont();

  // Set the text size for the button's text
  void setSize(int size);

  // Check if the mouse is over the button (within a specified RenderWindow)
  bool mouseIsOver(sf::RenderWindow& window);

  // Get the text element of the button
  sf::Text getButton();

  // Destructor for the Button class
  ~Button();
};

#endif