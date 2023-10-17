// Include necessary libraries and headers.
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Menu.hpp"

// Define the constructor for the Button class.
Button::Button() {
  // Load the 'yoster.ttf' font file for text rendering.
  if (!font.loadFromFile("./resources/yoster.ttf")) {
    std::cout << "Error loading font 'yoster.ttf'" << std::endl;
  }

  // Set the character size, fill color, and default text for the button.
  text.setCharacterSize(30);
  text.setFillColor(sf::Color::White);
  text.setFont(font);
  text.setString("Default");

  // Calculate the position of the text based on its size.
  text.setPosition(sf::Vector2f(text.getGlobalBounds().width / 2,
                                text.getGlobalBounds().height / 3));
}

// Define an overloaded constructor for the Button class.
Button::Button(std::string name, int size, int numOptions) {
  // Load the 'yoster.ttf' font file for text rendering.
  if (!font.loadFromFile("./resources/yoster.ttf")) {
    std::cout << "Error loading font 'yoster.ttf'" << std::endl;
  }

  // Set the character size, fill color, and text for the button.
  text.setCharacterSize(size);
  text.setFillColor(sf::Color::White);
  text.setFont(font);
  text.setString(name);

  // Calculate the position of the text based on its size and the number of
  // options.
  text.setPosition(sf::Vector2f((text.getGlobalBounds().width) / 2,
                                (text.getGlobalBounds().height) / numOptions));
}

// Define a function to set the position of the button.
void Button::setPosition(sf::Vector2f pos) { text.setPosition(pos); }

// Define a function to set the fill color of the button.
void Button::setFillColor(sf::Color new_colour) {
  text.setFillColor(new_colour);
}

// Define a function to set the font for the button text.
void Button::setFont() { text.setFont(font); }

// Define a function to set the character size for the button text.
void Button::setSize(const int size) { text.setCharacterSize(size); }

// Define a function to set the text of the button.
void Button::setName(std::string name) { text.setString(name); }

// Define a function to check if the mouse cursor is over the button.
bool Button::mouseIsOver(sf::RenderWindow& window) {
  // Get the current mouse position on the window.
  sf::Vector2i mouse_pos1 = sf::Mouse::getPosition(window);

  // Convert mouse position to a float vector for comparison.
  sf::Vector2f mouse_pos =
      sf::Vector2f(mouse_pos1.x * 1.0f, mouse_pos1.y * 1.0f);

  // Check if the mouse position is within the bounds of the button's text.
  if (text.getGlobalBounds().contains(mouse_pos)) {
    return true;  // Mouse is over the button.
  } else {
    return false;  // Mouse is not over the button.
  }
}

// Define a function to get the button text for rendering.
sf::Text Button::getButton() { return text; }

// Define the destructor for the Button class.
Button::~Button() {}
