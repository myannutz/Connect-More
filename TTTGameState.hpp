#ifndef TTTGAMESTATE_HPP
#define TTTGAMESTATE_HPP

#include "GameState.hpp"

class TTTGameState : public GameState {
private:
  //Marks which character player and AI are (out of 'x' or 'o')
  char playerChar;
  char AIChar;
public:
  TTTGameState();
  ~TTTGameState();
  void move(std::string move);
  std::vector<std::string> getValidMoves();
  bool isValid(std::string move);
  int isWin(); //0 for no win, 1 for player, 2 for AI
  void print();
  char* getBoard();
  // int heuristic();
};

#endif
