#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include<string>
#include<vector>

class GameState {
private:
  char **board;
public:
  GameState();
  ~GameState();
  
  virtual GameState move(std::string move) = 0;
  virtual std::vector<std::string> getValidMoves() = 0;
  virtual bool isValid(std::string move) = 0;
  virtual void print() = 0;
  virtual int heuristic() = 0;
};

#endif
