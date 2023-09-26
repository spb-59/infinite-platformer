#include <SFML/Graphics.hpp>

class Object {
 protected:
  float x_cord_;
  float y_cord_;
  sf::Vector2f size_;
  sf::Texture texture_;
  sf::Sprite sprite_;

 public:
  Object(float x_cord, float y_cord, sf::Vector2f size);
  int get_size();
  int get_x_cord();
  int get_y_cord();
  void set_size(sf::Vector2f size);
  void set_x_cord(sf::Vector2f x_cord);
  void set_y_cord(sf::Vector2f y_cord);
  void render();
};
