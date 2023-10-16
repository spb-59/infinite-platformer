#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Button.hpp"

enum MenuState {
    PLAY = 0,
    HOW_TO_PLAY = 1,
    QUIT = 2,
    MAIN_MENU = 3
};

class Menu
{
protected:
    std::vector <Button*> buttons; 
    MenuState menuState; 
    sf::RenderWindow* menu_window;
    sf::Font font; 
public:
    Menu(sf::RenderWindow* window);

    void run(); 

    MenuState getMenuState();
    void setMenuState(MenuState);

    ~Menu();
};

#endif