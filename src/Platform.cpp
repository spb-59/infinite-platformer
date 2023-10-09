
#include "../include/Platform.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

Platform::Platform(float x, float y, sf::Vector2f size) {
  box.setPosition(x, y);
  box.setSize(size);
  box.setFillColor(sf::Color::Green);
}

void Platform::render(sf::RenderWindow* window) { window->draw(box); }

Platform::~Platform() {}