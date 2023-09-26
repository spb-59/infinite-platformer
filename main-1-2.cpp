#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "platform.h"

// Function to perform midpoint displacement
void midpointDisplacement(std::vector<float>& heights, int left, int right,
                          float roughness) {
  if (right - left < 2) return;

  int mid = (left + right) / 2;

  // Calculate the midpoint height
  float midpointHeight =
      (heights[left] + heights[right]) / 2.0f +
      (static_cast<float>(rand()) / RAND_MAX - 0.5f) * roughness;

  // Assign the midpoint height to the middle point
  heights[mid] = midpointHeight;

  // Recursively displace the left and right segments
  midpointDisplacement(heights, left, mid, roughness);
  midpointDisplacement(heights, mid, right, roughness);
}

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Scrolling Terrain");
  srand(static_cast<unsigned int>(time(nullptr)));

  const int terrainWidth = 16000;  // Double the window width for scrolling
  const int terrainHeight = 300;
  const float roughness = 50.0f;

  std::vector<float> terrain(terrainWidth + 1, 0.0f);

  // Initialize endpoints
  terrain[0] = 0.0f;
  terrain[terrainWidth] = 0.0f;

  // Apply midpoint displacement
  midpointDisplacement(terrain, 0, terrainWidth, roughness);

  sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

  // Replace the definition of terrainVertices with a vector of platforms
  std::vector<platform> platforms;

  // Convert heights to platforms
  for (int x = 0; x <= terrainWidth; ++x) {
    int height = static_cast<int>(terrain[x]);
    sf::Vector2f position(x, terrainHeight - height);
    sf::Vector2f size(
        1.0f, height);  // You can adjust the width of the platforms here

    platforms.push_back(platform(position.x, position.y, size));
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // Handle scrolling (for example, using arrow keys)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      view.move(-5.0f, 0);  // Move the view left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      view.move(5.0f, 0);  // Move the view right
    }

    window.setView(view);

    window.clear(sf::Color::Black);

    // Render the platforms
    for (platform& p : platforms) {
      p.render(&window);
    }

    window.display();
  }

  return 0;
}
