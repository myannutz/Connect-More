#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include<string>
#include<vector>

class GameState {
private:
public:
  char *board;
  GameState();
  ~GameState(){};

  virtual void move(std::string move);
  virtual std::vector<std::string> getValidMoves();
  virtual bool isValid(std::string move);
  virtual void print();
  //virtual int heuristic();
};

#endif
