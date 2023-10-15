#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
protected:
    sf::RenderWindow button_window;
    sf::Text text; 
    sf::Font font;
    int maxOptions;


public:
    Button(std::string option, int fontSize);
    Button();

    void setPosition(const sf::Vector2f &position);
    void setColour(sf::Color colour_);
    void setName(std::string name);
    void setFont();
    void setSize(const int size);
    void showSelected(sf::RenderWindow &); // pass menu window

    void render(sf::RenderWindow button_window); 
    ~Button();
};

#endif
