#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
protected:
    sf::Text text; 
    sf::Font font;
    int maxOptions;


public:
    Button(std::string optionName, int fontSize);
    Button();

    void setPosition(const sf::Vector2f &position);
    void setColour(sf::Color colour_);
    void setName(std::string name);
    void setFont();
    void setSize(const int size);
    bool mouseIsOver(sf::RenderWindow &); // pass menu window 

    void draw(sf::RenderWindow button_window); 
    ~Button();
};

#endif
