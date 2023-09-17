
#include "Entity.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Entity::Entity(sf::Vector2f size, float x, float y) {
  entity.setPosition(x, y);
  entity.setSize(size);
  entity.setFillColor(sf::Color::Blue);
}

void Entity::render(sf::RenderWindow* window) {
  std::cout << "Rendering\n";
  window->draw(entity);
}

Entity::~Entity() {}