#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

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
  sf::Vector2f get_position();
  float get_x_cord();
  float get_y_cord();
  void set_size(sf::Vector2f size);

  void set_position(float x_cord, float y_cord);
  void move_position(float x_cord, float y_cord);
  sf::FloatRect getHitBox();
  void render(sf::RenderWindow* window);
  virtual bool get_isDeadly();
  virtual std::string get_type() = 0;

  virtual ~Object();
};

#endif