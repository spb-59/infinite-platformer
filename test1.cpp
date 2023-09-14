#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 15;
int map[MAP_WIDTH][MAP_HEIGHT];

class MovableObject {
 public:
  sf::Vector2f position;
  sf::Vector2f velocity;
  sf::RectangleShape shape;

  MovableObject(float x, float y) : position(x, y), velocity(0, 0) {
    shape.setSize(sf::Vector2f(40, 40));  // Example size for the player
    shape.setFillColor(sf::Color::Blue);  // Example color
    shape.setPosition(position);
  }

  void update(float deltaTime) {
    // Update the object's position based on velocity
    position += velocity * deltaTime;
    shape.setPosition(position);
  }

  void moveLeft() { velocity.x = -100; }

  void moveRight() { velocity.x = 100; }

  void moveUp() { velocity.y = -100; }

  void moveDown() { velocity.y = 100; }

  void stopMoving() { velocity = sf::Vector2f(0, 0); }
};

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600),
                          "Collision Detection Example");

  // Seed the random number generator
  srand(static_cast<unsigned>(time(nullptr)));

  sf::Clock clock;
  float updateInterval = 4.0f;  // Update the map every 4 seconds
  float elapsedTime = 0.0f;

  MovableObject player(100, 100);

  // Main game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();

      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
          player.moveLeft();
        } else if (event.key.code == sf::Keyboard::Right) {
          player.moveRight();
        } else if (event.key.code == sf::Keyboard::Up) {
          player.moveUp();
        } else if (event.key.code == sf::Keyboard::Down) {
          player.moveDown();
        }
      }

      if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left ||
            event.key.code == sf::Keyboard::Right ||
            event.key.code == sf::Keyboard::Up ||
            event.key.code == sf::Keyboard::Down) {
          player.stopMoving();
        }
      }
    }

    float deltaTime = clock.restart().asSeconds();
    elapsedTime += deltaTime;

    if (elapsedTime >= updateInterval) {
      // Generate a new map every 4 seconds
      for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
          map[x][y] = rand() % 2;  // Generate random terrain values
        }
      }
      elapsedTime = 0.0f;  // Reset the timer
    }

    // Clear the window
    window.clear();

    // Render the updated map
    for (int x = 0; x < MAP_WIDTH; x++) {
      for (int y = 0; y < MAP_HEIGHT; y++) {
        if (map[x][y] == 1) {  // Render obstacles
          sf::RectangleShape obstacle(
              sf::Vector2f(32, 32));                // Example cell size: 32x32
          obstacle.setPosition(x * 32, y * 32);     // Adjust for cell size
          obstacle.setFillColor(sf::Color::Green);  // Example obstacle color
          window.draw(obstacle);

          // Perform collision detection
          sf::FloatRect obstacleBounds = obstacle.getGlobalBounds();
          sf::FloatRect playerBounds = player.shape.getGlobalBounds();

          if (playerBounds.intersects(obstacleBounds)) {
            // Collision occurred, stop player's movement
            player.stopMoving();
          }
        }
      }
    }

    // Update and render the player character
    player.update(deltaTime);
    window.draw(player.shape);

    // Display the window
    window.display();
  }

  return 0;
}