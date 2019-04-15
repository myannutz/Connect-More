#ifndef AI_HPP
#define AI_HPP

#include "TreeNode.hpp"
#include "GameState.hpp"
#include <string>

class AI {
private:
  static const bool HUMAN = false;
  static const bool AI = true;
  
  int maxDepth;
  TreeNode *gameTree;

  int minimax(TreeNode *T, int depth, bool player);
public:
  AI();
  ~AI();
  
  std::string getBestMove(GameState gs);
};

#endif
