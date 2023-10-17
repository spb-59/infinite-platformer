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

  Animation(sf::Texture* texture_, sf::Vector2u imageCount_, float switchTime_);
  ~Animation();

  void setSwitchTime(float imageCount_);
  bool isForward();

  void update(int row, float deltaTime);
  sf::IntRect getIntRect() { return this->uvRect; }
};

#endif