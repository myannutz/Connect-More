#include "TreeNode.hpp"

#include <vector>
#include <string>
#include <iostream>

TreeNode::TreeNode(GameState *gs, int depth, bool player) {
  // initialize data members
  this->gs = gs;
  this->depth = depth;
  this->player = player;

  std::vector<std::string> moves = gs->getValidMoves(player); // get possible moves
  if (gs->isWon(player) || gs->isWon(!player) || depth == 0) return; // this should be a leaf node
  for (auto m : moves) { // iterate over moves
    children.push_back(new TreeNode(gs->move(m), depth - 1, !player)); // add a child
  }
}

TreeNode::~TreeNode() {
  delete gs; // free memory for game state
  if (children.size() == 0) return; // base case
  for (auto Tp : children) {
    delete Tp; // recursively delete each child
  }
}

std::vector<TreeNode*> TreeNode::getChildren() {
  return children;
}

GameState* TreeNode::getGameState() {
  return gs;
}

bool TreeNode::getPlayer() {
  return player;
}

int TreeNode::getDepth() {
  return depth;
}
