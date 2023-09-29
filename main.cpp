#include "Menu.h"

int main() {
  Menu* menu = new Menu();
  menu->run_menu();
  delete menu;
  menu = nullptr;
  return EXIT_SUCCESS;
}