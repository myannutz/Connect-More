#include "TreeNode.hpp"

#include <vector>
#include <string>
#include <iostream>

//Constructor
TreeNode::TreeNode(GameState *gs, int depth, bool player) {
  this->gs = gs;
  this->depth = depth;
  this->player = player;

  std::vector<std::string> moves = gs->getValidMoves(player);
  if (gs->isWon(player) || gs->isWon(!player)) return;
  for (auto m : moves) {
    children.push_back(new TreeNode(gs->move(m), depth - 1, !player));
  }
}

TreeNode::~TreeNode() {
  if (children.size() == 0) return;
  for (auto Tp : children) {
    delete Tp;
  }
}

//Getter for children vector
std::vector<TreeNode*> TreeNode::getChildren() {
  return children;
}

//GameState getter
GameState* TreeNode::getGameState() {
  return gs;
}

bool TreeNode::getPlayer() {
  return player;
}

int TreeNode::getDepth() {
  return depth;
}
