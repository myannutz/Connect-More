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
public:
  C4GameState();
  ~C4GameState();

};

#endif
