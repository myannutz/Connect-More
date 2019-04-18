#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include<string>
#include<vector>

class GameState {
protected:
  char **board;
public:
  virtual ~GameState(){};

  // move function
  // returns a gamestate object created by applying the move
  // @param: string representing move
  virtual GameState* move(std::string move) = 0;

  // getValidMoves function
  // returns a vector of all valid moves for a given player
  // @param: bool representing which player it is
  virtual std::vector<std::string> getValidMoves(bool player) = 0;

  // isValid function
  // returns true if a move is valid, false if not
  // @param: string representing move
  // @param: bool representing which player it is
  virtual bool isValid(std::string move, bool player) = 0;

  // print function
  // prints a graphical representation of the game state
  virtual void print() = 0;

  // heuristic function
  // evaluates favorability of the gamestate for a given player
  // @param: bool representing which player it is
  virtual int heuristic(bool player) = 0;

  // isWon function
  // returns whether the game is won for a particular player
  // @param: bool representing which player it is
  virtual bool isWon(bool player) = 0;
};

#endif
