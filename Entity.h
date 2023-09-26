#include <SFML/Graphics.hpp>

#include "Object.h"

class Entity : public Object {
    protected:
        sf::Vector2f speed;
        int size;
    public:
        Entity(float x_cord, float y_cord, sf::Vector2f size, sf::Vector2f speed, int size);
        void movement(sf::Event event);
};