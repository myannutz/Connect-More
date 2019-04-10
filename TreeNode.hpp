#ifndef TREENODE_HPP
#define TREENODE_HPP

#include<vector>

class TreeNode {
private:
  bool player;
  int depth;
  GameState gs;
  std::vector<TreeNode*> children;
public:
  TreeNode(GameState gs, int depth, bool player);
  std::vector<TreeNode*> *getChildren();
  GameState *getGameState();
};

#endif
