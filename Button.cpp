#include "Button.hpp"

#include "SFML/Graphics.hpp"
#include <iostream>

Button::Button() {
    if (!font.loadFromFile("prstart.ttf")) {
        std::cout << "Error loading font prstart" << std::endl;
    }

    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString("Placeholder");
    text.setPosition(sf::Vector2f((text.getGlobalBounds().width)/2, (text.getGlobalBounds().height)/3));
                                        // text.getGlobalBounds().height/3 <- 3 is =nummaxOptions

    
}

Button::Button(std::string option, int fontSize) {
    if (!font.loadFromFile("prstart.ttf")) {
        std::cout << "Error loading font prstart" << std::endl;
    }

    text.setCharacterSize(fontSize);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString("Placeholder");
    text.setPosition(sf::Vector2f((text.getGlobalBounds().width)/2, (text.getGlobalBounds().height)/maxOptions));
}

void Button::setPosition(const sf::Vector2f &position) {
    text.setPosition(position);
    return; 
}

void Button::setColour(sf::Color new_colour) {
    text.setFillColor(new_colour);
    return; 
}

void Button::setFont() {
    text.setFont(font);
    return; 
}

void Button::setSize(const int size) {
    text.setCharacterSize(size);
    return;
}

void Button::setName(std::string name) {
    text.setString(name);
    return;
}

void Button::showSelected(sf::RenderWindow &window) {
    // get mouse position relative to window 
    sf::Vector2i mouse_pos1 = sf::Mouse::getPosition(window);
    
    sf::Vector2f mouse_pos = sf::Vector2f(mouse_pos1.x*1.0f, mouse_pos1.y*1.0f);


    if (text.getGlobalBounds().contains(mouse_pos)) {
        text.setFillColor(sf::Color::Cyan);
    } else {
        text.setFillColor(sf::Color::White);
    }
    return;
}

void Button::render(sf::RenderWindow button_window) {
    button_window.draw(text);
}