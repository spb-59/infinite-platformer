#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
protected:
    sf::RenderWindow menu_window; 
    sf::Font font; 
    std::string title; 
    sf::Sprite menu_background;
    int selection;
    //
    
public:
    Menu(sf::RenderWindow menu_window);
    ~Menu();
};

#endif 