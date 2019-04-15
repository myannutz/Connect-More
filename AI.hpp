#ifndef AI_HPP
#define AI_HPP

#include "TreeNode.hpp"
#include "GameState.hpp"
#include <string>

class AI {
private:
  static const bool HUMAN_PLAYER = false;
  static const bool AI_PLAYER = true;
  
  int maxDepth;
  TreeNode *gameTree;

  int minimax(TreeNode *T);
public:
  AI();
  ~AI();
  
  std::string getBestMove(GameState gs);
};

#endif
