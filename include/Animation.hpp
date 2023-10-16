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

  Animation(sf::Texture* texture_, sf::Vector2u imageCount_, float switchTime_ );
  ~Animation();

  void setSwitchTime(float imageCount_);
  bool isForward();

  void update(float deltaTime, bool faceRight);
  sf::IntRect getIntRect() { return this->uvRect; }
};

// class Animation {
//   protected: 
//     sf::Texture texture;
//     std::vector<sf::Sprite> sprites;
//     sf::Texture textures[2];
//     int currentFrame;
//     float currentTime;  
//     sf::Clock clock; 

//   public: 
//     Animation(const std::string &textureFileName, const sf::Vector2u &numFrames);
//     Animation(); // to test for player 

//     // functions for player movement 
//     void moveRight(sf::Sprite &sprite, float waitTime);
//     void moveLeft(float waitTime);

//   // functions for general animation
//     void makeFrames(); 
//     void update(float waitTime);
//     void drawCurrent(sf::RenderWindow *window);

//     ~Animation();


// };

#endif
