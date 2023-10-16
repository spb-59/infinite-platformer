#ifndef GAMESTATE_H
#define GAMESTATE_H

class Gamestate {
 private:
  enum state { MENU, PLAYING, PAUSED, END };
  state currentState;

 public:
  Gamestate();

  void setState(state newState);

  state getState() const;
};

#endif
