// test_generation.cpp

#define CATCH_CONFIG_MAIN

#include <SFML/Graphics.hpp>
#include <catch2/catch.hpp>
#include <vector>

#include "../include/Colision.hpp"
#include "../include/Generation.hpp"
#include "../include/Object.hpp"
#include "../include/Platform.hpp"

class TestObject : public Platform {
 public:
  TestObject(float x, float y, float width, float height) : Platform() {
    obj.setScale(sf::Vector2f(width, height));
  }
};

TEST_CASE("Generation Methods", "[Generation]") {
  Generation generation;
  std::vector<Object*> boxes(4, nullptr);

  SECTION("Test makeTerrain method") {
    generation.makeTerrain(boxes, sf::Vector2f(0.0f, 0.0f));

    REQUIRE(boxes.size() == 4);  // Assuming 4 objects were created
    REQUIRE(boxes[1]->get_x_cord() == Approx(150.0f));
  }

  generation.makeTerrain(boxes, sf::Vector2f(0.0f, 0.0f));

  SECTION("Test makeInfinite method") {
    int initialSize, finalSize;

    initialSize = boxes.size();

    bool condition = true;

    while (condition) {
      if (boxes.size() > 20) condition = false;
      generation.makeInfinite(boxes, sf::Vector2f(200.0f, 200.0f));
    }

    finalSize = boxes.size();

    REQUIRE(finalSize > initialSize);
  }

  SECTION("Test transition method") {
    // Create some test data and objects
    float randomValue = 100.0f;
    float addY = 20.0f;

    // Call the transition method
    generation.transition(boxes, randomValue, addY);

    REQUIRE(boxes.size() == 12);
    }

  SECTION("Test optimize method") {
    generation.optimize(boxes, sf::Vector2f(10000.0f, 0.0f));

    REQUIRE(boxes.size() < 2);
  }
}