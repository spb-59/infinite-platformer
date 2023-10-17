
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../include/Colision.hpp"
#include "../include/LavaWall.hpp"
#include "../include/Platform.hpp"

// TESTING FOR CLASS  OBJECT AND INHERITED CLASSES //

TEST_CASE("lavaWall class tests", "[lavaWall]") {
  // Create an Object instance for testing
  LavaWall ob(10.0f, 20.0f, sf::Vector2f(2.0f, 2.0f));

  SECTION("Position and size getters and setters") {
    REQUIRE(ob.get_x_cord() == 10.0f);
    REQUIRE(ob.get_y_cord() == 20.0f);
    REQUIRE(ob.get_size() == sf::Vector2f(2.0f, 2.0f));

    ob.set_size(sf::Vector2f(3.0f, 3.0f));

    REQUIRE(ob.get_size() == sf::Vector2f(3.0f, 3.0f));

    ob.set_position(50.0f, 60.0f);
    REQUIRE(ob.get_x_cord() == 50.0f);
    REQUIRE(ob.get_y_cord() == 60.0f);
  }

  SECTION("Movement functions") {
    // Test move_position
    ob.move_position(10.0f, 20.0f);
    REQUIRE(ob.get_x_cord() == 20.0f);
    REQUIRE(ob.get_y_cord() == 40.0f);
  }
}
