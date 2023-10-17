// Include the Object.hpp header file from a relative path
#include "../include/Object.hpp"

// Include the SFML graphics library
#include <SFML/Graphics.hpp>

// Constructor for the Object class, taking position (x, y) and size as
// parameters
Object::Object(float x_cord, float y_cord, sf::Vector2f size)
    : x_cord_(x_cord), y_cord_(y_cord), size_(size) {
  // Set the object's position and scale based on the provided parameters
  obj.setPosition(x_cord, y_cord);
  obj.setScale(size_);
  // The texture loading is commented out
  // global_texture.loadFromFile("./resources/textures1.png");
}

// Default constructor for the Object class, using default values for position
// and size
Object::Object() : Object(1.0f, 1.0f, sf::Vector2f(1.0, 1.0)) {}

// Method to get the size of the object
sf::Vector2f Object::get_size() { return obj.getScale(); }

// Method to get the X coordinate of the object's position
float Object::get_x_cord() { return obj.getPosition().x; }

// Method to get the Y coordinate of the object's position
float Object::get_y_cord() { return obj.getPosition().y; }

// Method to set the size of the object
void Object::set_size(sf::Vector2f size) { obj.setScale(size); }

// Method to set the position of the object
void Object::set_position(float x_cord, float y_cord) {
  obj.setPosition(x_cord, y_cord);
}

// Method to move the object's position by a certain amount
void Object::move_position(float x_cord, float y_cord) {
  obj.move(x_cord, y_cord);
}

// Method to get the hitbox of the object
sf::FloatRect Object::getHitBox() { return obj.getGlobalBounds(); }

// Method to render the object on an SFML window
void Object::render(sf::RenderWindow* window) { window->draw(obj); }

// Method to check if the object is deadly (default: false)
bool Object::get_isDeadly() { return false; }

// Destructor for the Object class (empty, as there are no specific resources to
// release)
Object::~Object() {}
