
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../include/Animation.hpp"
#include "../include/Button.hpp"
#include "../include/Colision.hpp"
#include "../include/Entity.hpp"
#include "../include/Game.hpp"
#include "../include/Gamestate.hpp"
#include "../include/Generation.hpp"
#include "../include/LavaPit.hpp"
#include "../include/LavaWall.hpp"
#include "../include/Menu.hpp"
#include "../include/Object.hpp"
#include "../include/Obstacle.hpp"
#include "../include/Physics.hpp"
#include "../include/Platform.hpp"
#include "../include/Player.hpp"
#include "../include/Rock.hpp"
#include "../include/Spikes.hpp"

class TestObject : public Platform {
 public:
  TestObject(float x, float y, float width, float height) : Platform() {
    obj.setScale(sf::Vector2f(width, height));
  }
};

// TESTING FOR CLASS PLAYER //

TEST_CASE("Player class tests", "[Player]") {
  // Create an Object instance for testing
  Player ob(10.0f, 20.0f, sf::Vector2f(2.0f, 2.0f));

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

// TESTING FOR CLASS  PLATFORM //

TEST_CASE("Platform class tests", "[Platform]") {
  // Create an Object instance for testing
  Platform ob(10.0f, 20.0f, sf::Vector2f(2.0f, 2.0f));

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

// TESTING FOR CLASS  LAVAPIT //

TEST_CASE("LavaPit class tests", "[LavaPit]") {
  // Create an Object instance for testing
  LavaPit ob(10.0f, 20.0f, sf::Vector2f(2.0f, 2.0f));

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

  SECTION("Get type test") { REQUIRE(ob.get_type() == "LAVA"); }
}

// TESTING FOR CLASS  SPIKES//

TEST_CASE("Spikes class tests", "[Spikes]") {
  // Create an Object instance for testing
  Spikes ob(10.0f, 20.0f, sf::Vector2f(2.0f, 2.0f));

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

  SECTION("Get type test") { REQUIRE(ob.get_type() == "SPIKES"); }
}

// TESTING CASE FOR CLASS COLLLISION //

TEST_CASE("Collision detection", "[Collision]") {
  Collision collision;

  Player player(10.0f, 10.0f, sf::Vector2f(50.0f, 50.0f));
  TestObject object1(150.0f, 150.0f, 2.0f, 2.0f);  // Object to test collision
  TestObject object2(200.0f, 200.0f, 2.0f, 2.0f);  // Object not colliding

  // Create a vector of Object pointers
  std::vector<Object*> objects = {&object1, &object2};

  SECTION("No collision detected") {
    bool collisionDetected = collision.detect_collision(objects, player);
    REQUIRE(collisionDetected == true);
  }

  SECTION("Collision detected") {
    // Move the player to overlap with object1
    player.set_position(150.0f, 150.0f);

    bool collisionDetected = collision.detect_collision(objects, player);
    REQUIRE(collisionDetected == false);
  }
}

// TESTING FOR THE GENERATION CLASS

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
TEST_CASE("Entity class tests", "[Entity]") {
  // Create an Object instance for testing
  Entity ob(10.0f, 20.0f, sf::Vector2f(2.0f, 2.0f));

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
