
#include "platform.h"

#include <SFML/Graphics.hpp>
#include <iostream>

platform::platform(float x, float y, sf::Vector2f size) {
  box.setPosition(x, y);
  box.setSize(size);
  box.setFillColor(sf::Color::Green);
}
platform::platform() : platform(0, 0, sf::Vector2f(0, 0)) {}

void platform::setDimensions(float x, float y, sf::Vector2f size) {
  box.setPosition(x, y);
  box.setSize(size);
  box.setFillColor(sf::Color::Green);

  std::cout << box.getPosition().x;
}

void platform::render(sf::RenderWindow* window) { window->draw(box); }

platform::~platform() {}