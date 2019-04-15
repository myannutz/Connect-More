#include "GameTree.hpp"

#include <vector>

//Constructor
TreeNode::TreeNode(GameState gs, int depth, bool player){

  this->gs = gs;
  this->depth = depth;
  this->player = player;

}

//Getter for children vector
std::vector<TreeNode*>* TreeNode::getChildren(){

  return &(this->children);

}

//GameState getter
GameState* TreeNode::getGameState(){

  return &gs;

}
