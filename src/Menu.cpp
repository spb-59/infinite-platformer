#include "../include/Menu.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Button.hpp"

Menu::Menu(sf::RenderWindow* window) {
  if (!font.loadFromFile("./resources/prstart.ttf")) {
    std::cout << "Error loading font prstart" << std::endl;
  }

  menu_window = window;

  buttons.push_back(new Button());
  buttons.push_back(new Button());
  buttons.push_back(new Button());

  // make button for play
  buttons[0]->setName("Play");
  buttons[0]->setFillColor(sf::Color::White);
  buttons[0]->setFont();
  buttons[0]->setSize(30);
  buttons[0]->setPosition(
      sf::Vector2f(menu_window->getView().getCenter().x / 4,
                   menu_window->getView().getCenter().y / 1.5+25));

  // make button for options
  buttons[1]->setName("How To Play");
  buttons[1]->setFillColor(sf::Color::White);
  buttons[1]->setFont();
  buttons[1]->setSize(30);
  buttons[1]->setPosition(sf::Vector2f(menu_window->getView().getCenter().x/4,menu_window->getView().getCenter().y / 1));

  // make button to quit
  buttons[2]->setName("Quit");
  buttons[2]->setFillColor(sf::Color::White);
  buttons[2]->setFont();
  buttons[2]->setSize(30);
  buttons[2]->setPosition(sf::Vector2f(menu_window->getView().getCenter().x/4,menu_window->getView().getCenter().y /1+100));


  setMenuState(MAIN_MENU);
}

void Menu::run() {
  std::cout << "Menu is running- menu::run function" << std::endl;
  bool isButtonClicked = false;
  int selectedButton = -1;
    if(isGameOver){


buttons.push_back(new Button());

  buttons[3]->setName("You Died!!!");
  buttons[3]->setFillColor(sf::Color::Red);
  buttons[3]->setFont();
  buttons[3]->setSize(70);
  buttons[3]->setPosition(sf::Vector2f(500,250));



  }

  while (menu_window->isOpen() && isMenu) {
    sf::Event event;

    // load menu texture 
    sf::Sprite menuBG;
    sf::Texture menu_tex;
    if (!menu_tex.loadFromFile("./resources/menu_background.png")) {
        std::cout << "Error loading menu background" << std::endl;
    }

    menuBG.setTexture(menu_tex);
        menu_window->draw(menuBG);

    while (menu_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        menu_window->close();
      }
    }

    // counter to get button index in the loop
    int buttonIndexCounter = 0;

    if(buttons.size()>4) buttons.resize(4);

    for (Button*& p : buttons) {
      menu_window->draw(p->getButton());

      if (p->mouseIsOver(*menu_window)) {
        p->setFillColor(sf::Color::Cyan);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          if (!isButtonClicked) {
            selectedButton = buttonIndexCounter;
            isButtonClicked = true;
          }
        }

      } else {
        if (buttonIndexCounter == 3) {
            p->setFillColor(sf::Color::Red);
        } else {
            p->setFillColor(sf::Color::White);
        }
      }
      buttonIndexCounter++;
    }

    menu_window->display();

    if (isButtonClicked) {
      switch (selectedButton) {
        case 0:
          menuState = PLAY;
          std::cout << "PLAY has been chosen" << std::endl;
          isMenu = false;
          break;
        case 1:
          menuState = HOW_TO_PLAY;
          std::cout << "HOW TO PLAY has been chosen" << std::endl;
          isMenu = false;
          break;
        case 2:
          menuState = QUIT;
          std::cout << "QUIT has been chosen" << std::endl;
          menu_window->close();
          break;
      }
    }
  }
}

void Menu::setIsGameOver() {
    isGameOver = true; 
    isMenu=true;
}

void Menu::setMenuState(MenuState newState) { menuState = newState; }

MenuState Menu::getMenuState() { return menuState; }

Menu::~Menu() {
  for (Button* button : buttons) {
    delete button;
  }

  buttons.clear();
}