#pragma once

#include <SFML/Graphics.hpp>

class Object {
 protected:
  float x_cord_;
  float y_cord_;
  sf::Vector2f size_;
  sf::Texture global_texture;
  sf::Sprite obj;

 public:
  Object(float x_cord, float y_cord, sf::Vector2f size);
  Object();
  sf::Vector2f get_size();
  float get_x_cord();
  float get_y_cord();
  void set_size(sf::Vector2f size);
  void set_position(float x_cord, float y_cord);
  void render(sf::RenderWindow* window);
  ~Object();
};
