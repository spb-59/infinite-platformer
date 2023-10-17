#ifndef LAVAPIT_HPP
#define LAVAPIT_HPP

#include <SFML/Graphics.hpp>
#include "Obstacle.hpp"

class LavaPit : public Obstacle {
 private:
  sf::Texture localTexture; // Texture specific to the LavaPit

 public:
  // Constructor for the class with position and size
  LavaPit(float x_cord, float y_cord, sf::Vector2f size);

  // Default constructor
  LavaPit();

  // Get the type of the object (override from base class)
  std::string get_type();

  // Destructor 
  ~LavaPit();
};

#endif