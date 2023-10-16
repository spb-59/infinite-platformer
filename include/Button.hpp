#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
 protected:
  sf::Text text;
  sf::Font font;

 public:
  Button();
  Button(std::string name, int size, int numOptions);

  void setPosition(sf::Vector2f(pos));
  void setFillColor(sf::Color);
  void setName(std::string name);
  void setFont();
  void setSize(int size);
  bool mouseIsOver(sf::RenderWindow &);

  sf::Text getButton();

  ~Button();
};

#endif