#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.hpp"

enum MenuState { MAIN_MENU =0, PLAY = 1, OPTIONS=2, EXIT = 3, NEXT = 4, GAME_OVER = 5, OUT = 6};

class Menu
{
protected:
    sf::RenderWindow* menu_window; 
    sf::Sprite menu_bg; 
    sf::Texture menu_tex;
    sf::Font font; 
    Button* options[4]; 

    int selectedOptionID;

    MenuState menuState;  
    
    
public:
    Menu(); 
    Menu(sf::Vector2f(float x, float y));

    void run(sf::RenderWindow &menu_window); 

    MenuState getMenuState();
    int getSelectedOption();

    // void setVisible();
    // void setInvisible();

    ~Menu();
};

#endif 
