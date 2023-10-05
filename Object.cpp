#include "Object.hpp"

#include <SFML/Graphics.hpp>

Object::Object(float x_cord, float y_cord, sf::Vector2f size)
    : x_cord_(x_cord), y_cord_(y_cord), size_(size), texture_() {
  obj.setPosition(x_cord_, y_cord_);
  obj.setScale(size_);
  obj.setTexture(texture_);
}

Object::Object() : Object(0.0f, 0.0f, sf::Vector2f(0, 0)) {}

sf::Vector2f Object::get_size() { return obj.getScale(); }

float Object::get_x_cord() { return obj.getPosition().x; }

float Object::get_y_cord() { return obj.getPosition().y; }

void Object::set_size(sf::Vector2f size) { obj.setScale(size); }

void Object::set_position(float x_cord, float y_cord) {
  obj.setPosition(x_cord, y_cord);
}

void Object::render(sf::RenderWindow* window) { window->draw(obj); }