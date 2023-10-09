#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation {
protected:
    sf::Texture frames[2]; 
    sf::Texture texture1;
    sf::Texture texture2; 
    int numFrame; 
    int counter; 
    sf::Clock clock; 
    sf::Time timeElapsed; 
    float waitTime; 

public:
    Animation();
    Animation(sf::Sprite &sprite);

    void animate(float waitTime); 

    bool keyPressed(); 

    ~Animation();
};

#endif
