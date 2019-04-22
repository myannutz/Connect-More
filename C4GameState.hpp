#ifndef C4GAMESTATE_HPP
#define C4GAMESTATE_HPP

#include <iostream>

#include "GameState.hpp"

class C4GameState : public GameState{
private:
  // X's and O's for connect four? It's more likely than you think
  static const bool X_PLAYER = false;
  static const bool O_PLAYER = true;
  
  // getUnfilledRow function
  // gets the row of the first empty space
  // @param: column to check
  // @return: index of row
  int getUnfilledRow(int column);
  
  // count2 function
  // counts how many open 2-in-a-rows there are
  // @param: bool representing which player to count for
  // @return: number of open 2-in-a-rows
  int count2(bool player);
  
  // count3 function
  // counts how many open 3-in-a-rows there are
  // @param: bool representing which player to count for
  // @return: number of open 3-in-a-rows
  int count3(bool player);
public:
  C4GameState();
  
  // copy constructor
  // @param: pointer to gamestate to copy
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
