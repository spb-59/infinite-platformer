#include "Animation.h"

#include <SFML/Graphics.hpp>

Animation::Animation() : counter(0), timeElapsed(timeElapsed) {}

Animation::Animation(sf::Sprite &sprite, int numFrames) {
    // initialise array 
    frames[numFrames]; 
    
    // store frames into array 
    texture1.loadFromFile("tex/right1.png");
    texture2.loadFromFile("tex/right2.png");
}

void Animation::animate(float waitTime) {
    // reset time to 0 
    timeElapsed = clock.restart(); 
    if (timeElapsed.asSeconds() == waitTime) {
        
    }
    
}
eaee