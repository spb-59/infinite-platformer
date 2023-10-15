#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.hpp"

enum MenuState {
    MAIN_MENU,
    PLAY,
    OPTIONS,
    EXIT,
};

class Menu
{
protected:
    sf::RenderWindow menu_window; 
    sf::RectangleShape winclose; 
    sf::Sprite sprite; 
    sf::Texture texture;
    sf::Font font; 
    std::vector<Button> buttons; 

    int selectedOptionID;

    MenuState menuState;
    
public:
    Menu(); 
    Menu(sf::RenderWindow &menu_window);
    void handleEvents();


    void run(); 

    MenuState getMenuState() const;

    ~Menu();
};

#endif 
