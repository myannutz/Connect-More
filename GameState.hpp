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
  
  virtual GameState move(std::string move);
  virtual std::vector<std::string> getValidMoves();
  virtual bool isValid(std::string move);
  virtual void print();
};

#endif
