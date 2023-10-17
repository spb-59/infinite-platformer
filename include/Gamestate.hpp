#ifndef GAMESTATE_H
#define GAMESTATE_H

class Gamestate {
 private:
  enum state { MENU, PLAY, END };  // Possible game states (menu, play, end)
  state currentState; // The current game state
  int currentScore = 0; // The current score
  int highestScore; // The highest score achieved
  int pointsPerSecond = 10; // Points earned per second of play
  int startTime; // Starting time of the game

 public:
  // Get the highest score achieved
  int getHighScore();

  // Get the current score
  int getCurrentScore();

  // Constructor for the Gamestate class
  Gamestate();

  // Set the current game state to a new state
  void setState(state newState);

  // Calculate the score based on the time played
  void calculateScore(double time);

  // Get the current game state
  state getState() const;
};

#endif // GAMESTATE_H
