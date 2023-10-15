
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Mouse Click Example");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Left mouse button was clicked
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    std::cout << "Mouse clicked at position: " << mousePosition.x << ", " << mousePosition.y << std::endl;
                }
            }
        }

        window.clear(sf::Color::White);
        // Draw your graphics here
        window.display();
    }

    return 0;
}
