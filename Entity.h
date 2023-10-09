#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class Entity {
 protected:
  sf::Sprite entity;

 public:
  Entity(sf::Vector2f size, float x, float y,sf::Texture* texture);
  void render(sf::RenderWindow* window);
  virtual void movement(sf::Event event){};

  ~Entity();
};

#endif
