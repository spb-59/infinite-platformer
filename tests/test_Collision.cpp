#pragma once
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../include/Colision.hpp"
#include "../include/Platform.hpp"

class TestObject : public Platform {
 public:
  TestObject(float x, float y, float width, float height) : Platform() {
    obj.setScale(sf::Vector2f(width, height));
  }
};

TEST_CASE("Collision detection", "[Collision]") {
  Collision collision;

  Player player(100.0f, 100.0f, sf::Vector2f(50.0f, 50.0f));
  TestObject object1(150.0f, 150.0f, 30.0f, 30.0f);  // Object to test collision
  TestObject object2(200.0f, 200.0f, 30.0f, 30.0f);  // Object not colliding

  // Create a vector of Object pointers
  std::vector<Object*> objects = {&object1, &object2};

  SECTION("No collision detected") {
    bool collisionDetected = collision.detect_collision(objects, player);
    REQUIRE(collisionDetected == false);
  }

  SECTION("Collision detected") {
    // Move the player to overlap with object1
    player.set_position(155.0f, 155.0f);

    bool collisionDetected = collision.detect_collision(objects, player);
    REQUIRE(collisionDetected == true);
  }
}
