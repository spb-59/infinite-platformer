#include <SFML/Graphics.hpp>
#include <catch2/catch.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#include "../include/Generation.hpp"
#include "../include/LavaPit.hpp"
#include "../include/Object.hpp"
#include "../include/Platform.hpp"
#include "../include/Spikes.hpp"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() function

TEST_CASE("Test Generation::generate") {
  Generation generation;
  std::vector<double> probabilities = {0.4, 0.3, 0.2, 0.1};
  int generatedValue = generation.generate(probabilities);
  REQUIRE(generatedValue >= 0);
  REQUIRE(generatedValue <= 3);
  // You can add more specific checks based on your probability distribution.
}

TEST_CASE("Test Generation::applyRules") {
  Generation generation;
  std::vector<Object*> boxes;
  // Populate the boxes vector with objects

  size_t originalSize = boxes.size();

  // Ensure that the applyRules method adds objects as expected
  generation.applyRules(boxes);

  // Check if the objects have been added according to the rules
  REQUIRE(boxes.size() >=
          originalSize + 4);  // Assuming originalSize is the size of the vector
                              // before applying rules
}