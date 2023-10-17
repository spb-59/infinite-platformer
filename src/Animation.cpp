#include "../include/Animation.hpp"

#include <SFML/Graphics.hpp>

Animation::Animation(sf::Texture* texture_, sf::Vector2u imageCount_,
                     float switchTime_) {
  imageCount = imageCount_;
  switchTime = switchTime_;
  totalTime = 0.0f;
  currentImage.x = 0;

  uvRect.width = texture_->getSize().x / float(imageCount.x);
  uvRect.height = texture_->getSize().y / float(imageCount.y);
}

Animation::~Animation() {}

void Animation::setSwitchTime(float switchTime_) { switchTime = switchTime_; }

void Animation::update(int row, float deltaTime) {
  currentImage.y = row;
  totalTime += deltaTime;

  if (totalTime >= switchTime && imageCount.x > 1) {
    totalTime -= switchTime;

    if (totalTime >= switchTime) {
      totalTime -= switchTime;
      currentImage.x++;
      if (currentImage.x >= imageCount.x) {
        currentImage.x = 0;
      }
    }
  }

  uvRect.left = currentImage.x * uvRect.width;
  uvRect.top = currentImage.y * uvRect.height;
}
