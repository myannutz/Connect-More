
#ifndef AI_HPP
#define AI_HPP

#include "TreeNode.hpp"
#include <string>

class AI {
private:
  int maxDepth; // the depth of the game tree when generated
  TreeNode *gameTree; // stores a pointer to the game tree to be evaluated
  bool player; // which player the AI is (e.g. white/black, x/o)

  // minimax function
  // finds the best move that the AI can force the player into given perfect play
  // @param: tree node containing gamestate
  // @return: the heuristic value of the best state that can be force
  int minimax(TreeNode *T);
public:
  // constructor
  // @param: bool representing which player the AI is
  // @param: max depth of game tree
  AI(bool player, int depth);
  ~AI();
  
  // getBestMove function
  // uses minimax to find which move can force the best game state
  // @param: pointer to gamestate to evaluate
  // @return: string representing best move
  std::string getBestMove(GameState* gs);
};

#endif
