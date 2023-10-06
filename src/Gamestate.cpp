#include "../include/Gamestate.hpp"

Gamestate::Gamestate() { currentState = MENU; }

void Gamestate::setState(state newState) { currentState = newState; }

Gamestate::state Gamestate::getState() const { return currentState; }
