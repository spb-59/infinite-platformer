#include "../include/Animation.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

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

void Animation::update(float deltaTime, bool faceRight) {
  if (faceRight) {
    currentImage.y = 0;
  } else {
    currentImage.y = 1;
  }
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

// Animation::Animation(const std::string &textureFileName, const sf::Vector2u &numFrames) {
//   // load texture
//   if (!texture.loadFromFile(textureFileName)) {
//     std::cout << "Error loading sprite texture" << std::endl; 
//   }

//   sf::Vector2u size; 

//   // initialise frame dimensions 
//   size.x = texture.getSize().x / numFrames.x;
//   size.y = texture.getSize().y / numFrames.y; 

//   // // cut out frames from sprite sheet
//   // for (int i =0; i < numFrames.y + 1; i++) {
//   //   for (int j =0; j < numFrames.x + 1; j++) {
//   //     sprites.push_back(sf::Sprite(texture, sf::IntRect(size.x * j, size.y * i, size.x, size.y)));
//   //     sprites.back().setPosition(100.0f,100.0f);
//   //   }
//   // }
// }

// Animation::Animation() {
//   if (!texture.loadFromFile("../resources/playersheet_FIXED.png")) {
//     std::cout << "Error loading sprite sheet texture" << std::endl; 
//   }

//   sf::Vector2u player_size; 

//   player_size.x = texture.getSize().x / 2;
//   player_size.y = texture.getSize().y / 2;

//   sprites.push_back(sf::Sprite(texture, sf::IntRect(0,0, player_size.x, player_size.y)));
//   sprites.push_back(sf::Sprite(texture, sf::IntRect(0,texture.getSize().x/2, player_size.x, player_size.y)));
  
// }

// void Animation::moveRight(sf::Sprite &sprite,float waitTime) {

//   sprite.setTextureRect(sf::IntRect(0,0,player_size.x, player_size.y));


//   currentTime = clock.getElapsedTime().asSeconds();

//   if (currentTime >= waitTime) {
//     currentTime = 0.0f;
//     clock.restart(); 
//   }

//   if (++currentFrame >= sprites.size()/2) {
//     currentFrame = 0; 
//   }
// }

// void Animation::moveLeft(float waitTime) {
//   currentTime = clock.getElapsedTime().asSeconds();
  
//   currentFrame = sprites.size()/2; // to start where moving left is 

//   if (currentTime >= waitTime) {
//     currentTime = 0.0f;
//     clock.restart(); 
//   }

//   if (++currentFrame >= sprites.size()) {
//     currentFrame = 0; 
//   }
// }

// void Animation::update(float waitTime) {
//   currentTime = clock.getElapsedTime().asSeconds();

//   if (currentTime >= waitTime) {
//     currentTime = 0.0f; // reset the current time in intervals of waitTime
//     clock.restart(); // restart the clock 

//     if (++currentFrame >= sprites.size()) {
//       currentFrame = 0; 
//     }
//   }
// }

// void Animation::drawCurrent(sf::RenderWindow *window) {
//   window->draw(sprites[currentFrame]);
// }

// Animation::~Animation() {

// }
