
#include "platform.h"

#include <SFML/Graphics.hpp>
#include <iostream>

platform::platform(float x, float y, sf::Vector2f size) {
  box.setPosition(x, y);
  box.setSize(size);
  box.setFillColor(sf::Color::Green);
}

void platform::render(sf::RenderWindow* window) { window->draw(box); }

platform::~platform() {}
