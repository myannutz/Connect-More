
#ifndef AI_HPP
#define AI_HPP

#include "TreeNode.hpp"
#include <string>

class AI {
private:
  int maxDepth;
  TreeNode *gameTree;
  bool player; //which player AI is (e.g. white/black, x/o)

  int minimax(TreeNode *T);
public:
  AI(bool player, int depth);
  ~AI();

  std::string getBestMove(GameState* gs);
};

#endif
