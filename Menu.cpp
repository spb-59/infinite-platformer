#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu(sf::Vector2f(float x, float y)) {
    if (!font.loadFromFile("prstart.ttf")) {
        std::cout << "Error loading font prstart" << std::endl;
    }
     menu_window = new sf::RenderWindow(sf::VideoMode(1280, 720),
                                "Game");

    options[0]->setFont();
    options[0]->setColour(sf::Color::Cyan);
    options[0]->setName("Play");
    options[0]->setPosition(sf::Vector2f(x/2, (y/4) * 1));
    options[0]->setSize(30);

    options[1]->setFont();
    options[1]->setColour(sf::Color::White);
    options[1]->setName("Settings");
    options[1]->setPosition(sf::Vector2f(x/2, (y/4) * 2));
    options[1]->setSize(30);

    selectedOptionID = 0; 
    menuState = MAIN_MENU;
    texture.loadFromFile("tempButton.png");
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(100,100));


//     options[2].setFont(font);
//     options[2].setFillColor(sf::Color::White);
//     options[2].setString("Quit");
//     options[2].setPosition(sf::Vector2f(width/2, (height/4) * 3));
//     options[2].setCharacterSize(30);
}

void Menu::handleEvents() {
    sf::Event event; 

    while (menu_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            menu_window.close(); 
        } 
        
        for (size_t i=0; i < buttons.size(); i++) {
            if (buttons[i].mouseIsOver(menu_window)) {
                selectedOptionID=i;
                buttons[i].setColour(sf::Color::Cyan);
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                
            }
        }
    }

    for (int i =0; i < buttons.size(); i++) {
        if (buttons[i].mouseIsOver(menu_window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            buttons[i].getSelectedID();
        }
    }
}

void Menu::run(sf::RenderWindow &menu_window) {
while (menu_window.isOpen()){
    sf::Event event;
  while (menu_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
      menu_window.close();
        }

    menu_window.clear(); 

    for (int i = 0; i < 2; i++) {
        menu_window.draw(buttons[i]);
    }

    menu_window.display();
    }   
    }

    for ()
}

Menu::~Menu() {}



void Menu::handleEvents() {
    sf::Event event;
    while (menu_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            menu_window.close();
        }

        for (size_t i = 0; i < buttons.size(); i++) {
            if (buttons[i].mouseIsOver(menu_window)) {
                selectedOptionID = i;
                buttons[i].setColour(sf::Color::Cyan);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (menuState == MAIN_MENU) {
                        if (selectedOptionID == PLAY) {
                            // Start the game
                            menuState = NEXT;  // Transition to the next state (e.g., gameplay)
                        } else if (selectedOptionID == OPTIONS) {
                            // Go to options menu
                            menuState = OPTIONS;
                        } else if (selectedOptionID == EXIT) {
                            // Exit the game
                            menuState = OUT;  // Transition to exit
                        }
                    } else if (menuState == OPTIONS) {
                        // Handle options menu
                        // Add your options menu logic here
                    }
                }
            } else {
                buttons[i].setColour(sf::Color::White);
            }
        }
    }
}

void Menu::run(sf::RenderWindow &menu_window) {
    while (menu_window.isOpen()) {
        handleEvents();
        menu_window.clear();

        // Draw the menu buttons
        for (Button& button : buttons) {
            button.draw(menu_window);
        }

        menu_window.display();

        if (menuState == NEXT || menuState == OUT) {
            menu_window.close();
        }
    }
}
