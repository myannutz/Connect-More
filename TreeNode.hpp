#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <vector>
#include "GameState.hpp"

class TreeNode {
private:
  bool player; // which player this is (e.g. white/black, x/o)
  int depth; // the depth of this node in the tree
  GameState *gs; // the gamestate associated with this node
  std::vector<TreeNode*> children; // the children of this node
public:
  // constructor
  // @param: gamestate to associate
  // @param: depth of this node
  // @param: which player's turn is associated with this node
  TreeNode(GameState *gs, int depth, bool player);
  ~TreeNode();
  
  // getters for data members
  std::vector<TreeNode*> getChildren();
  bool getPlayer();
  int getDepth();
  GameState *getGameState();
};

#endif
