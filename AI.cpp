#include "AI.hpp"
#include <vector>
#include <algorithm>
#include <climits>

AI::AI() {
  maxDepth = 6;
  gameTree = 0;
}

AI::~AI() {
  
}

std::string AI::getBestMove(GameState gs) {
  std::vector<std::string> moves = gs.getValidMoves();
  int bestMoveScore = INT_MIN;
  std::string bestMove = "";
  for (auto m : moves) {
    gameTree = new TreeNode(gs.move(m), 1, AI_PLAYER);
    int score = minimax(gameTree);
    //recursively delete gameTree
    if (score > bestMoveScore) {
      bestMoveScore = score;
      bestMove = m;
    }
  }
  return bestMove;
}

int minimax(TreeNode *T) {
  if (T->depth == maxDepth) return T->gs.hueristic();
  if (T->player == AI_PLAYER) {
    //assume player will minimize heuristic
    int val = INT_MAX;
    for (TreeNode* child : T->getChildren()) {
      val = min(val, minimax(child));
    }
    return val;
  } else {
    //maximize heuristic
    int val = INT_MIN;
    for (TreeNode* child : T->getChildren()) {
      val = max(val, minimax(child));
    }
    return val;
  }
}
