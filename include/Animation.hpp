#include <SFML/Graphics.hpp>
#ifndef ANIMATION_H_
#define ANIMATION_H_

class Animation {
 protected:
  sf::Vector2u imageCount;
  sf::Vector2u currentImage;

  float totalTime;

  float switchTime;

 public:
  sf::IntRect uvRect;

  // Constructor for the Animation class
  Animation(sf::Texture* texture_, sf::Vector2u imageCount_, float switchTime_);

  // Destructor for the Animation class
  ~Animation();

  // Set the switch time for the animation
  void setSwitchTime(float imageCount_);

  // Check if the animation is playing forward
  bool isForward();

  // Update the animation based on the specified row and time elapsed
  void update(int row, float deltaTime);

  // Get the IntRect representing the current frame's texture coordinates
  sf::IntRect getIntRect();
};

#endif