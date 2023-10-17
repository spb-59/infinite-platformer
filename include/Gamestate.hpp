
#ifndef GAMESTATE_H
#define GAMESTATE_H

class Gamestate {
 private:
  enum state { MENU, PLAY, END };
  state currentState;
  int currentScore = 0;
  int pointsPerSecond = 10;
  int startTime;

 public:
  Gamestate();

  void setState(state newState);

  void calculateScore(double time);

  state getState() const;
};

#endif
