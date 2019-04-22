#include "TreeNode.hpp"

#include <vector>
#include <string>
#include <iostream>

//Constructor
TreeNode::TreeNode(GameState *gs, int depth, bool player) {
  std::cout << "begin" << std::endl;
  this->gs = gs;
  this->depth = depth;
  this->player = player;

  std::vector<std::string> moves = gs->getValidMoves(player);
  if (gs->isWon(player) || gs->isWon(!player) || depth == 0) return;
  for (auto m : moves) {
    std::cout << "adding child" << std::endl;
    children.push_back(new TreeNode(gs->move(m), depth - 1, !player));
  }
}

TreeNode::~TreeNode() {
  delete gs;
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
