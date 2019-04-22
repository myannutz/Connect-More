#include "AI.hpp"
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

AI::AI(bool player, int depth) {
  maxDepth = depth;
  gameTree = 0;
  this->player = player;
}

AI::~AI() {

}

std::string AI::getBestMove(GameState *gs) {
  std::vector<std::string> moves = gs->getValidMoves(player);
  int bestMoveScore = INT_MIN;
  std::string bestMove = "";
  for (auto m : moves) {
    //std::cout << "move: " << m << std::endl;
    gameTree = new TreeNode(gs->move(m), maxDepth, !player);
    int score = minimax(gameTree);
    //std::cout << "score: " << score << std::endl;
    if (score > bestMoveScore) {
      bestMoveScore = score;
      bestMove = m;
    }
    delete gameTree;
  }
  //std::cout << "best move h value: " << bestMoveScore << std::endl;
  return bestMove;
}

int AI::minimax(TreeNode *T) {
  if (T->getDepth() == 0 || T->getChildren().size() == 0) {
    //std::cout << "h value: " << T->getGameState()->heuristic(player) << std::endl;
    return T->getGameState()->heuristic(player); //evaluate favorability for AI
  }
  if (T->getPlayer() == !player) {
    //assume human player will minimize heuristic
    int val = INT_MAX - 1;
    for (TreeNode* child : T->getChildren()) {
      val = std::min(val, minimax(child));
    }
    return val;
  } else {
    //maximize heuristic
    int val = INT_MIN + 1;
    for (TreeNode* child : T->getChildren()) {
      val = std::max(val, minimax(child));
    }
    return val;
  }
}
