#include "AI.hpp"
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

AI::AI(bool player, int depth) {
  // initialize data members
  maxDepth = depth;
  gameTree = 0;
  this->player = player;
}

AI::~AI() {
  // empty
}

std::string AI::getBestMove(GameState *gs) {
  std::vector<std::string> moves = gs->getValidMoves(player); // gets a vector of possible moves to explore
  int bestMoveScore = INT_MIN; // store score of current best move
  std::string bestMove = ""; // store the current best move
  
  for (auto m : moves) { // iterate over possible moves
    //std::cout << "move: " << m << std::endl;
    gameTree = new TreeNode(gs->move(m), maxDepth, !player); // build game tree from passed in game state and move
    int score = minimax(gameTree); // evaluate move
    //std::cout << "score: " << score << std::endl;
    if (score > bestMoveScore) { // replace the current best move
      bestMoveScore = score;
      bestMove = m;
    }
    delete gameTree; // free memory
    gameTree = 0;
  }
  //std::cout << "best move h value: " << bestMoveScore << std::endl;
  return bestMove;
}

// CREDIT:
// this algorithm was adapted from pseudocode on wikipedia
// https://en.wikipedia.org/wiki/minimax
int AI::minimax(TreeNode *T) {
  if (T->getDepth() == 0 || T->getChildren().size() == 0) { // leaf node
    //std::cout << "h value: " << T->getGameState()->heuristic(player) << std::endl;
    return T->getGameState()->heuristic(player); // evaluate favorability for AI
  }
  if (T->getPlayer() == !player) { // assume the human player will minimize heuristic
    int val = INT_MAX - 1;
    for (TreeNode* child : T->getChildren()) { // iterate over children
      val = std::min(val, minimax(child)); // update if child is better
    }
    return val;
  } else { // figure out how to maximize the heuristic
    int val = INT_MIN + 1;
    for (TreeNode* child : T->getChildren()) { // iterate over children
      val = std::max(val, minimax(child)); //update if child is better
    }
    return val;
  }
}
