#include "C4GameState.hpp"
#include <iostream>

C4GameState::C4GameState(){
  board = new char*[6]; // allocate memory
  for(int i = 0; i < 6; i++){
    board[i] = new char[7]; // allocate memory
    for(int j = 0; j < 7; j++){
      board[i][j] = ' '; // fill board
    }
  }
}

C4GameState::C4GameState(C4GameState *toCopy) {
  board = new char*[6]; // allocate memory
  for(int i = 0; i < 6; i++){
    board[i] = new char[7]; // allocate memory
    for(int j = 0; j < 7; j++){
      board[i][j] = toCopy->board[i][j]; // copy board
    }
  }
}

C4GameState::~C4GameState() {
  for(int i = 0; i < 6; i++)
    delete[] board[i]; // free memory
  delete[] board; // free memory
}

int C4GameState::getUnfilledRow(int column) {
  for(int i = 5; i >= 0; i--){ // iterate over rows from bottom to top
    if(board[i][column] == ' ') return i; // found the open space
  }
  return -1;
}

GameState* C4GameState::move(std::string move) {
  int c = move[0] - 48; // what column to move to (shift to convert to int)
  char m = move[1]; // what piece to place
  C4GameState* gs = new C4GameState(this); // create new game state
  gs->board[getUnfilledRow(c)][c] = m; // add piece
  return (GameState*)gs;
}

std::vector<std::string> C4GameState::getValidMoves(bool player){
  std::vector<std::string> moves; // store valid moves
  char playerChar = 'x';
  if(player == O_PLAYER) playerChar = 'o';
  
  for(int  i = 0; i < 7; i++) {
    if(getUnfilledRow(i) != -1) { // column is open
      moves.push_back(std::to_string(i) + playerChar); // add move to vector
    }
  }
  return moves;
}

bool C4GameState::isValid(std::string move, bool player){
  if (move.length() != 2) return false; // invalid string
  int c = move[0] - 48; // column
  char m = move[1]; // piece 
  bool validC = (c > -1 && c < 7 && getUnfilledRow(c) != -1); // make sure column is within range
  bool validM = (player == X_PLAYER) ? m == 'x' : m == 'o'; // make sure piece matches player
  return validC && validM;
}

// who doesn't love ASCII art
void C4GameState::print(){
  std::cout << "=============================" << std::endl;
  for(int i = 0; i < 6; i++){
    std::cout << "| ";
    for(int  j = 0; j < 7; j++){
      std::cout << board[i][j] << " | ";
    }
    std::cout << std::endl;
  }
  std::cout << "=============================" << std::endl;
  std::cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |" << std::endl;
}

int C4GameState::count2(bool player){
  char playerChar = 'o';
  if (player == X_PLAYER) playerChar = 'x';
  int count = 0; // keep track of number

  // horizontal
  for (int r = 0; r < 6; r++){
    for (int c = 0; c < 5; c++){
      // pass a mask over board and check for match
      if (board[r][c] == playerChar && board[r][c + 1] == playerChar && board[r][c + 2] == ' ') count++;
      if (board[r][c] == ' ' && board[r][c + 1] == playerChar && board[r][c + 2] == playerChar) count++;
    }
  }

  // vertical
  for (int c = 0; c < 7; c++) {
    for (int r = 0; r < 4; r++) {
      // pass a mask over board and check for match
      if (board[r][c] == ' ' && board[r + 1][c] == playerChar && board[r + 2][c] == playerChar) count++;
    }
  }

  // diagonal
  for (int r = 0; r < 4; r++){
    for (int c = 0; c < 5; c++){
      // pass a mask over board and check for match
      if (board[r][c] == playerChar && board[r + 1][c + 1] == playerChar &&
          board[r + 2][c + 2] == ' ' && (r == 3 || board[r + 3][c + 2] != ' ')) count++;
      if (board[r][c + 2] == playerChar && board[r + 1][c + 1] == playerChar &&
          board[r + 2][c] == ' ' && (r == 3 || board[r + 3][c] != ' ')) count++;

      if (board[r][c] == ' ' && board[r + 1][c + 1] == playerChar &&
          board[r + 2][c + 2] == playerChar && board[r + 1][c] != ' ') count++;
      if (board[r][c + 2] == ' ' && board[r + 1][c + 1] == playerChar &&
          board[r + 2][c] == playerChar && board[r + 1][c + 2] != ' ') count++;
    }
  }
  return count;
}

int C4GameState::count3(bool player) {
  char playerChar = 'o';
  if (player == X_PLAYER) playerChar = 'x';
  int count = 0; // keep track of number

  // horizontal
  for (int r = 0; r < 6; r++) {
    for (int c = 0; c < 4; c++){
      // pass a mask over board and check for match
      if (board[r][c] == playerChar && board[r][c + 1] == playerChar && board[r][c + 2] == playerChar && board[r][c + 3] == ' ') count++;
      if (board[r][c] == ' ' && board[r][c + 1] == playerChar && board[r][c + 2] == playerChar && board[r][c + 3] == playerChar) count++;
    }
  }

  // vertical
  for (int c = 0; c < 7; c++) {
    for (int r = 0; r < 3; r++) {
      // pass a mask over board and check for match
      if (board[r][c] == ' ' && board[r + 1][c] == playerChar && board[r + 2][c] == playerChar && board[r + 3][c] == playerChar) count++;
    }
  }

  // diagonal
  for (int r = 0; r < 3; r++){
    for (int c = 0; c < 4; c++){
      // pass a mask over board and check for match
      if (board[r][c] == playerChar && board[r + 1][c + 1] == playerChar && board[r + 2][c + 2] == playerChar &&
          board[r + 3][c + 3] == ' ' && (r == 2 || board[r + 4][c + 3] != ' ')) count++;
      if (board[r][c + 3] == playerChar && board[r + 1][c + 2] == playerChar &&
          board[r + 2][c + 1] == playerChar && board[r + 3][c] == ' ' && (r == 2 || board[r + 4][c] != ' ')) count++;

      if (board[r][c] == ' ' && board[r + 1][c + 1] == playerChar &&
          board[r + 2][c + 2] == playerChar && board[r + 3][c + 3] == playerChar && board[r + 1][c] != ' ') count++;
      if (board[r][c + 3] == ' ' && board[r + 1][c + 3] == playerChar &&
          board[r + 2][c + 1] == playerChar && board[r + 3][c] == playerChar && board[r + 1][c + 3] != ' ') count++;
    }
  }
  return count;
}

bool C4GameState::isWon(bool player) {
  char playerChar = 'o';
  if (player == X_PLAYER) playerChar = 'x';

  // horizontal check
  for (int r = 0; r < 6; r++){
    for (int c = 0; c < 4; c++){
      // pass a mask over board and check for match
      if (board[r][c] == playerChar && board[r][c + 1] == playerChar &&
          board[r][c + 2] == playerChar && board[r][c + 3] == playerChar) return true;
    }
  }
  
  // vertical check
  for (int c = 0; c < 7; c++) {
    for (int r = 0; r < 3; r++) {
      // pass a mask over board and check for match
      if (board[r][c] == playerChar && board[r + 1][c] == playerChar &&
          board[r + 2][c] == playerChar && board[r + 3][c] == playerChar) return true;
    }
  }
  
  // diagonal check
  for (int r = 0; r < 3; r++){
    for (int c = 0; c < 4; c++){
      // pass a mask over board and check for match
      if (board[r][c] == playerChar && board[r + 1][c + 1] == playerChar &&
          board[r + 2][c + 2] == playerChar && board[r + 3][c + 3] == playerChar) return true;
      if (board[r][c + 3] == playerChar && board[r + 1][c + 2] == playerChar &&
          board[r + 2][c + 1] == playerChar && board[r + 3][c] == playerChar) return true;
    }
  }
  return false;
}

//high value is good for player, low value is bad for player.
int C4GameState::heuristic(bool player){
  if (isWon(player)) return 10000;
  if (isWon(!player)) return -10000;
  int adv = count2(player) + 10*count3(player); // how good it is for player
  int dis = count2(!player) + 10*count3(!player); // how good it is for opponent
  return adv - dis;
}
