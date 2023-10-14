
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Collision.hpp"
#include "Entity.hpp"
#include "EntityTest.hpp"
#include "Game.hpp"
#include "Generation.hpp"
#include "Obstacle.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "physics.hpp"

// class collision_test {
//  private:
//   sf::RenderWindow* Window;

//  public:
//   collision_test();
//   void run();
//   ~collision_test();
// };

// collision_test::collision_test() {
//   Window = new sf::RenderWindow(sf::VideoMode(1280, 720),
//                                 "Game");  // making game window
// }

// Generation Gen;
// physics phy(0.5f);
// Collision col;

// void collision_test::run() {
//   // object creations and generations here

//   Player pl1(100.0f, 250.0f, sf::Vector2f(0.8f, 0.8f));
//   sf::View view(sf::FloatRect(0, 0, Window->getSize().x,
//   Window->getSize().y));

//   std::vector<Object*> blocks(20, nullptr);
//   std::cout << "Vector Created";

//   sf::Vector2f size = sf::Vector2f(1.0f, 1.0f);

//   Gen.makeTerrain(blocks, size);
//   blocks.push_back(new Platform(200.0f, 200.0f, size));
//   float add = 50.0f;
//   for (int i = 0; i < 10; i++) {
//     blocks.push_back(new Platform(200.0f + add, 200.0f, size));
//     add += 50.0f;
//   }

//   blocks.push_back(
//       new Platform(blocks.back()->get_x_cord() + 100.0f, 200.0f, size));
//   blocks.push_back(
//       new Platform(blocks.back()->get_x_cord() + 50.0f, 200.0f, size));

//   add = 50.0f;

//   for (int i = 0; i < 10; i++) {
//     blocks.push_back(new Platform(500.0f, 200.0f + add, size));
//     add += 50.0f;
//   }

//   while (Window->isOpen()) {
//     sf::Event event;

//     while (Window->pollEvent(event)) {
//       if (event.type == sf::Event::Closed) Window->close();
//     }
//     Window->clear();
//     pl1.movement(event);
//     phy.addGravity(pl1);
//     col.detect_collision(blocks, pl1);

//     sf::Vector2f cameraPosition = view.getCenter();
//     cameraPosition.x += 0.0f;

//     // Update the view's center to follow the player
//     view.setCenter(cameraPosition);

//     // Apply the view to the window
//     Window->setView(view);

//     // all rendering logic here

//     for (Object*& p : blocks) {
//       if (p) {  // Check if the pointer is valid (not null)
//         p->render(Window);
//       } else {
//         std::cout << "Error ";
//       }
//     }
//     pl1.render(Window);
//     Window->display();
//   }
// }
// collision_test::~collision_test() {}

int main() {
  Game game(1280, 720, "Game");
  game.run();
  return 0;
}
