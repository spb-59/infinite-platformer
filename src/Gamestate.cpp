// Include necessary headers and libraries.
#include "../include/Gamestate.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

// Constructor for the Gamestate class.
Gamestate::Gamestate() {
  // Initialize the current state to MENU.
  currentState = MENU;
}

// Set the current state to a new state.
void Gamestate::setState(state newState) { currentState = newState; }

// Get the current state.
Gamestate::state Gamestate::getState() const { return currentState; }

// Calculate the player's score based on elapsed time and update high scores.
void Gamestate::calculateScore(double time) {
  // Update the score based on points earned per second.
  currentScore = pointsPerSecond * time;

  // Display the updated score.
  std::cout << "Score: " << currentScore << " points" << std::endl;

  // Append the score to a text file.
  std::ofstream outputFile(
      "score.txt", std::ios::app);  // Use ios::app to append to the file.
  if (outputFile.is_open()) {
    outputFile << "Score: " << currentScore << " points" << std::endl;
    outputFile.close();
    std::cout << "Score appended to score.txt" << std::endl;
  } else {
    std::cerr << "Unable to open the file for writing." << std::endl;
  }

  // Read and display all scores from the file and find the highest score.
  std::ifstream inputFile("score.txt");
  if (inputFile.is_open()) {
    highestScore = 0.0;
    std::string line;
    std::vector<double> allScores;

    while (std::getline(inputFile, line)) {
      if (line.find("Score:") != std::string::npos) {
        double score = std::stod(line.substr(line.find("Score:") + 6));
        allScores.push_back(score);

        if (score > highestScore) {
          highestScore = score;
        }
      }
    }
    inputFile.close();

    // Display all scores and the highest score.
    std::cout << "All Scores:" << std::endl;
    for (const double& score : allScores) {
      std::cout << score << " points" << std::endl;
    }

    std::cout << "Highest Score: " << highestScore << " points" << std::endl;
  } else {
    std::cerr << "Unable to open the file for reading." << std::endl;
  }
}

// Get the highest score.
int Gamestate::getHighScore() { return highestScore; }

// Get the current score.
int Gamestate::getCurrentScore() { return currentScore; }
