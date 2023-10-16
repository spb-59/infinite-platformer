#include "../include/Menu.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

Button::Button() {
    if(!font.loadFromFile("./resources/prstart.ttf")) {
        std::cout << "Error loading fron prstart" << std::endl;
    }

    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString("Default");
    text.setPosition(sf::Vector2f(text.getGlobalBounds().width/2,text.getGlobalBounds().height/3));
}

Button::Button(std::string name, int size, int numOptions) {
    if(!font.loadFromFile("./resources/prstart.ttf")) {
        std::cout << "Error loading fron prstart" << std::endl;
    }

    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString(name);
    text.setPosition(sf::Vector2f((text.getGlobalBounds().width)/2,(text.getGlobalBounds().height)/numOptions));
}

void Button::setPosition(sf::Vector2f(pos)) {
    text.setPosition(pos);
    return; 
}

void Button::setFillColor(sf::Color new_colour) {
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

bool Button::mouseIsOver(sf::RenderWindow & window) {
    sf::Vector2i mouse_pos1 = sf::Mouse::getPosition(window);
    
    sf::Vector2f mouse_pos = sf::Vector2f(mouse_pos1.x*1.0f, mouse_pos1.y*1.0f);

    if (text.getGlobalBounds().contains(mouse_pos)) {
        return true; 
    } else {
        return false; 
    }
}

sf::Text Button::getButton() {
    return text; 
}

Button::~Button() {

}
