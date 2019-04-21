#include "TTTGameState.hpp"
#include <iostream>

TTTGameState::TTTGameState() {
  board = new char*[3];
  for (int i = 0; i < 3; i++) {
    board[i] = new char[3];
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

TTTGameState::TTTGameState(TTTGameState *toCopy) {
  board = new char*[3];
  for (int i = 0; i < 3; i++) {
    board[i] = new char[3];
    for (int j = 0; j < 3; j++) {
      board[i][j] = toCopy->board[i][j];
    }
  }
}

TTTGameState::~TTTGameState() {
  for (int i = 0; i < 3; i++) {
    delete [] board[i];
  }
  delete [] board;
}

GameState *TTTGameState::move(std::string move) {
  int r = (int)move[0] - 48;
  int c = (int)move[1] - 48;
  char m = move[2];
  TTTGameState* gs = new TTTGameState(this);
  gs->board[r][c] = m;
  return (GameState*)gs;
}

std::vector<std::string> TTTGameState::getValidMoves(bool player) {
  std::vector<std::string> moves;
  //if (isWon(player) || isWon(!player)) return moves;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        std::string m = "";
        m.append(std::to_string(i));
        m.append(std::to_string(j));
        if (player == O_PLAYER) m.append("o");
        else m.append("x");
        moves.push_back(m);
      }
    }
  }
  return moves;
}

bool TTTGameState::isValid(std::string move, bool player) {
  int r = move[0] - 48;
  //std::cout << "R: " << r << " "; //Debug
  int c = move[1] - 48;
  //std::cout << "C: " << c << " "; //Debug
  char m = move[2];
  //std::cout << "M: " << m << std::endl; //Debug
  bool validR = r > -1 && r < 3;
  bool validC = r > -1 && r < 3;
  bool validM = (player == X_PLAYER) ? m == 'x' : m == 'o';
  bool empty = board[r][c] == ' ';
  return validR && validC && validM && empty;
}

void TTTGameState::print() {
  std::cout << " ------" << std::endl;
  for (int i = 0; i < 3; i++) {
    std::cout << "|";
    for (int j = 0; j < 3; j++) {
      std::cout << board[i][j] << " ";
    }
    std::cout << "|" << std::endl;
  }
  std::cout << " ------" << std::endl;
}

int TTTGameState::heuristic(bool player) {
  if (isWon(player)) return 1000;
  if (isWon(!player)) return -1000;
  return 0;
}

bool TTTGameState::isWon(bool player) {
  char p = (player == O_PLAYER) ? 'o' : 'x';
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
    if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
  }
  if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
  if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
  return false;
}
