#pragma once

#include <iostream>

#include "LavaPit.hpp"

class EntityTest {
 private:
 public:
  EntityTest();
  ~EntityTest();
};

EntityTest::EntityTest(/* args */) {
  LavaPit lava;

  std::cout << " TYPE:" << lava.get_type() << "\n";
}

EntityTest::~EntityTest() {}
