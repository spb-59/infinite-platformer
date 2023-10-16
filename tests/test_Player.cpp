#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../include/Player.hpp"

TEST_CASE("Object class tests", "[Object]") {
  // Create an Object instance for testing
  Player ob(10.0f, 20.0f, sf::Vector2f(2.0f, 2.0f));

  SECTION("Position and size getters and setters") {
    REQUIRE(ob.get_x_cord() == 10.0f);
    REQUIRE(ob.get_y_cord() == 20.0f);
    REQUIRE(ob.get_size() == sf::Vector2f(2.0f, 2.0f));

    ob.set_x_cord(30.0f);
    ob.set_y_cord(40.0f);
    ob.set_size(sf::Vector2f(3.0f, 3.0f));

    REQUIRE(ob.get_x_cord() == 30.0f);
    REQUIRE(ob.get_y_cord() == 40.0f);
    REQUIRE(ob.get_size() == sf::Vector2f(3.0f, 3.0f));

    ob.set_position(50.0f, 60.0f);
    REQUIRE(ob.get_x_cord() == 50.0f);
    REQUIRE(ob.get_y_cord() == 60.0f);

    ob.move_position(10.0f, 10.0f);
    REQUIRE(ob.get_x_cord() == 60.0f);
    REQUIRE(ob.get_y_cord() == 70.0f);
  }

  SECTION("HitBox and isDeadly") {
    sf::FloatRect hitbox = ob.getHitBox();
    REQUIRE(hitbox.left == 10.0f);
    REQUIRE(hitbox.top == 20.0f);
    REQUIRE(hitbox.width == 2.0f);
    REQUIRE(hitbox.height == 2.0f);

    REQUIRE(ob.get_isDeadly() == false);
  }

  // Add more test cases as needed to cover other functions and scenarios.
}
