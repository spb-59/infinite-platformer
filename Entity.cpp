
#include "Entity.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Entity::Entity(sf::Vector2f size, float x, float y, sf::Texture texture) {
  entity.setPosition(x, y);
  entity.setTexture(texture);
}

void Entity::render(sf::RenderWindow* window) { window->draw(entity); }

Entity::~Entity() {}