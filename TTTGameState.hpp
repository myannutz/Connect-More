#ifndef TTTGAMESTATE_HPP
#define TTTGAMESTATE_HPP

#include "GameState.hpp"

class TTTGameState : public GameState {
private:
  static const bool X_PLAYER = false;
  static const bool O_PLAYER = true;
public:
  TTTGameState();
  TTTGameState(TTTGameState *toCopy);
  ~TTTGameState();

  GameState *move(std::string move);
  std::vector<std::string> getValidMoves(bool player);
  bool isValid(std::string move, bool player);
  void print();
  int heuristic(bool player);
  bool isWon(bool player);
};

#endif
