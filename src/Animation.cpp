// Include the Animation header file.
#include "../include/Animation.hpp"

// Include the SFML Graphics library.
#include <SFML/Graphics.hpp>

// Define the constructor for the Animation class.
Animation::Animation(sf::Texture* texture_, sf::Vector2u imageCount_,
                     float switchTime_) {
  // Initialize member variables with values provided in the constructor.
  imageCount = imageCount_;
  switchTime = switchTime_;
  totalTime = 0.0f;
  currentImage.x = 0;

  // Calculate the width and height of each frame in the texture.
  uvRect.width = texture_->getSize().x / float(imageCount.x);
  uvRect.height = texture_->getSize().y / float(imageCount.y);
}

// Define the destructor for the Animation class.
Animation::~Animation() {}

// Define a function to set the switch time for animation.
void Animation::setSwitchTime(float switchTime_) { switchTime = switchTime_; }

// Define a function to update the animation frame.
void Animation::update(int row, float deltaTime) {
  // Set the current row for the animation.
  currentImage.y = row;

  // Accumulate the time passed since the last frame update.
  totalTime += deltaTime;

  // Check if it's time to switch to the next frame.
  if (totalTime >= switchTime && imageCount.x > 1) {
    totalTime -= switchTime;

    // Check if the total time still exceeds the switch time.
    if (totalTime >= switchTime) {
      totalTime -= switchTime;
      currentImage.x++;

      // Reset to the first frame if the end of the animation is reached.
      if (currentImage.x >= imageCount.x) {
        currentImage.x = 0;
      }
    }
  }

  // Update the UV rectangle to display the current frame.
  uvRect.left = currentImage.x * uvRect.width;
  uvRect.top = currentImage.y * uvRect.height;
}
