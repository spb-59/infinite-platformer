#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Object {
 protected:
 // initialise variables and elements 
  float x_cord_;              
  float y_cord_;               
  sf::Vector2f size_;
  sf::Texture global_texture;   
  sf::Sprite obj;              

 public:
  // Constructor 
  Object(float x_cord, float y_cord, sf::Vector2f size);

  // Default constructor 
  Object();

  sf::Vector2f get_size();

  sf::Vector2f get_position();

  float get_x_cord();

  float get_y_cord();

  void set_size(sf::Vector2f size);

  void set_position(float x_cord, float y_cord);

  // Move the position of the object by the specified x and y coordinates
  void move_position(float x_cord, float y_cord);

  // Get the bounding box (HitBox) of the object
  sf::FloatRect getHitBox();

  // Render the object in the provided window
  void render(sf::RenderWindow* window);

  // Check if the object is deadly (to be overridden in derived classes)
  virtual bool get_isDeadly();

  // Get the type of the object (to be implemented in derived classes)
  virtual std::string get_type() = 0;

  // Destructor 
  virtual ~Object();
};

#endif 
