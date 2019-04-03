#include "GameTree.hpp"

class Board {
private:
  GameState gs;
  int h, w;
public:
  Board();
  ~Board();
  bool isValidMove(int m);
  void move(int m);
};
