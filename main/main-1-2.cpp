#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "Button.hpp"

#include <iostream>

int main() {
    sf::RenderWindow mainWindow(sf::VideoMode(1280, 720), "Game");

    // Create an instance of the Menu class
    Menu menu;

    // Call the run function to start the menu loop
    menu.run(mainWindow);

    return 0;
}
