#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
public:
    Menu();
    ~Menu();
n
    void run_menu();

private:
    sf::RenderWindow* window;
    sf::RectangleShape* winclose;
    sf::Font* font;
    sf::Texture* image;
    sf::Sprite* bg;

    int pos;
    bool pressed;
    bool theselect;
    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;

    std::vector<std::string> options;
    std::vector<sf::Text> texts;
    std::vector<sf::Vector2f> coords;
    std::vector<int> sizes;

    void set_values();
    void loop_events();
    void draw_all();
};

#endif // MENU_H
