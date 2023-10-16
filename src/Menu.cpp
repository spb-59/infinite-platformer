#include "../include/Menu.hpp"
#include "../include/Button.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>


Menu::Menu(sf::RenderWindow* window) {
    if (!font.loadFromFile("./resources/prstart.ttf")) {
        std::cout << "Error loading font prstart" << std::endl;
    }

      menu_window= window ;

   
    buttons.push_back(new Button());
    buttons.push_back(new Button());
    buttons.push_back(new Button());

    
    //make button for play 
    buttons[0]->setName("Play");
    buttons[0]->setFillColor(sf::Color::White);
    buttons[0]->setFont();
    buttons[0]->setSize(30);
    buttons[0]->setPosition(sf::Vector2f(1280.0/2, 720.0/4));

    //make button for options 
    buttons[1]->setName("How To Play");
    buttons[1]->setFillColor(sf::Color::White);
    buttons[1]->setFont();
    buttons[1]->setSize(30);
    buttons[1]->setPosition(sf::Vector2f(1280.0/2, 720.0/2.75));

    // make button to quit 
    buttons[2]->setName("Quit");
    buttons[2]->setFillColor(sf::Color::White);
    buttons[2]->setFont();
    buttons[2]->setSize(30);
    buttons[2]->setPosition(sf::Vector2f(1280.0/2, 720.0/2));

    menuState = MAIN_MENU;
    
}

void Menu::run() {
    while (menu_window->isOpen()){
    sf::Event event;

    while(menu_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            menu_window->close(); 
        }
    }

    // counter to get button index in the loop  
    int buttonIndexCounter = 0; 

    for (Button*& p :buttons) {

        menu_window->draw(p->getButton());

        if (p->mouseIsOver(*menu_window)) {
            p->setFillColor(sf::Color::Cyan);

            // if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //     std::cout << buttonIndexCounter << std::endl;
            //     switch (buttonIndexCounter) {
            //         case 0:
            //             menuState = PLAY;
            //             std::cout << "play state" << std::endl;
            //             break;
            //         case 1:
            //             menuState = HOW_TO_PLAY;
            //             break; 

            //         case 2:
            //             menuState = QUIT;
            //             break; 

            //     }
            // }
        } else {
            p->setFillColor(sf::Color::White);
        }

        buttonIndexCounter++;
    }
        menu_window->display();

    }



}

void Menu::setMenuState(MenuState newState) {
    menuState = newState; 
}

MenuState Menu::getMenuState() {
    return menuState; 
}

Menu::~Menu() {
    delete menu_window; 

    for (Button* button : buttons) {
    delete button; 
    }
    buttons.clear();

}
