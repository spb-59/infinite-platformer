

#include "../include/Object.hpp"

#include <SFML/Graphics.hpp>

Object::Object(float x_cord, float y_cord, sf::Vector2f size)
    : x_cord_(x_cord), y_cord_(y_cord), size_(size) {
  obj.setPosition(x_cord, y_cord);
  obj.setScale(size_);
  //   global_texture.loadFromFile("./resources/textures1.png");
}

Object::Object() : Object(1.0f, 1.0f, sf::Vector2f(1.0, 1.0)) {}

sf::Vector2f Object::get_size() { return obj.getScale(); }

float Object::get_x_cord() { return obj.getPosition().x; }

float Object::get_y_cord() { return obj.getPosition().y; }

void Object::set_size(sf::Vector2f size) { obj.setScale(size); }
void Object::set_y_cord(float x_cord) { x_cord_ = x_cord; };
void Object::set_x_cord(float y_cord) { y_cord_ = y_cord; };

void Object::set_position(float x_cord, float y_cord) {
  obj.setPosition(x_cord, y_cord);
}
void Object::move_position(float x_cord, float y_cord) {
  obj.move(x_cord, y_cord);
}

sf::FloatRect Object::getHitBox() { return obj.getGlobalBounds(); }

void Object::render(sf::RenderWindow* window) { window->draw(obj); }

bool Object::get_isDeadly() { return false; }

Object::~Object() {}