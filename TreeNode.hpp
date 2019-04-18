#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <vector>
#include "GameState.hpp"

class TreeNode {
private:
  //which player this is (e.g. white/black, x/o)
  bool player;
  int depth;
  GameState *gs;
  std::vector<TreeNode*> children;
public:
  TreeNode(GameState *gs, int depth, bool player);
  ~TreeNode();
  std::vector<TreeNode*> getChildren();
  bool getPlayer();
  int getDepth();
  GameState *getGameState();
};

#endif
