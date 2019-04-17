#ifndef AI_HPP
#define AI_HPP

#include "GameTree.hpp"

class AI {
private:
  static const bool HUMAN = false;
  static const bool AI = true;

  int maxDepth;
  TreeNode *gameTree;

  int minimax(TreeNode *T, int depth, bool player);
public:
  AI(GameState gs, int treeDepth){

    //Initialize a gameTree on player's turn
    gameTree = new TreeNode(gs, treeDepth, true);

  }; //Inline for now
  ~AI();

  int getBestMove(GameState gs);
};

#endif
