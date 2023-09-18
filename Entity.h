#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
 protected:
  sf::RectangleShape entity;

 public:
  Entity(sf::Vector2f size, float x, float y);
  void render(sf::RenderWindow* window);
  virtual void movement(sf::Event event){};

  ~Entity();
};

#endif