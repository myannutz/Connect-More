#ifndef C4GAMESTATE_HPP
#define C4GAMESTATE_HPP

#include <iostream>

#include "GameState.hpp"

class C4GameState : public GameState{
private:
  //X's and O's for connect four? It's more likely than you think
  static const bool X_PLAYER = false;
  static const bool O_PLAYER = true;

  int getUnfilledRow(int column);
  int count2(bool player);
  int count3(bool player);
public:
  C4GameState();
  C4GameState(C4GameState *toCopy);
  ~C4GameState();

  GameState *move(std::string move);
  std::vector<std::string> getValidMoves(bool player);
  bool isValid(std::string move, bool player);
  void print();
  int heuristic(bool player);
  bool isWon(bool player);
};

#endif
