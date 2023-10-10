#pragma once

#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class Platform {
 private:
  sf::RectangleShape body;

 public:
  Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
  ~Platform();

  void draw(sf::RenderWindow& window) { window.draw(body); }
  Collider getCollider() { return Collider(body); }
};
