#include "C4GameState.hpp"
#include <iostream>

C4GameState::C4GameState(){
  board = new char*[6];
  for(int i = 0; i < 6; i++){
    board[i] = new char[7];
    for(int j = 0; j < 7; j++){
      board[i][j] = ' ';
    }
  }
}

C4GameState::C4GameState(C4GameState *toCopy) {
  board = new char*[6];
  for(int i = 0; i < 6; i++){
    board[i] = new char[7];
    for(int j = 0; j < 7; j++){
      board[i][j] = toCopy->board[i][j];
    }
  }
}

C4GameState::~C4GameState(){

  for(int i = 0; i < 6; i++)
    delete[] board[i];

  delete[] board;

}

//Returns the index of the bottom most unfilled space in a particular column (-1 if column is full)
int C4GameState::getUnfilledRow(int column){
  for(int i = 0; i < 6; i--) {
    if(board[i][column] == ' ') return i;
  }
  return -1;
}

//Pass a string as "cm" - c = column, m = character indicating which player
GameState* C4GameState::move(std::string move){
  int c = move[0] - 48;
  char m = move[1];
  C4GameState* gs = new C4GameState(this);
  gs->board[getUnfilledRow(c)][c] = m;
  return (GameState*)gs;
}

std::vector<std::string> C4GameState::getValidMoves(bool player){

  std::vector<std::string> moves;
  char playerChar = 'x';
  if(player == O_PLAYER) playerChar = 'o';

  for(int  i = 0; i < 7; i++){

    //If the row isn't full, push back a string
    if(getUnfilledRow(i) != -1){

      moves.push_back(std::to_string(i) + std::to_string(playerChar));

    }

  }

  return moves;

}

bool C4GameState::isValid(std::string move, bool player){
  if (move.length() != 2) return false;
  int c = move[0] - 48;
  char m = move[1];
  bool validC = (c > -1 && c < 7 && getUnfilledRow(c) != -1);
  bool validM = (player == X_PLAYER) ? m == 'x' : m == 'o';
  return validC && validM;
}

//Who doesn't love ASCII art
void C4GameState::print(){

  std::cout << "===============" << std::endl;
  for(int i = 0; i < 6; i++){

    std::cout << "|";
    for(int  j = 0; j < 7; j++){

      std::cout << board[i][j] << "|";

    }
    std::cout << std::endl;

  }
  std::cout << "===============" << std::endl;

}

int C4GameState::count2(bool player){
  char playerChar = 'o';
  if (player == X_PLAYER) playerChar = 'x';
  int count = 0;

  //horizontal
  for (int r = 0; r < 6; r++){
    for (int c = 0; c < 5; c++){
      if (board[r][c] == playerChar && board[r][c + 1] == playerChar && board[r][c + 2] == ' ') count++;
      if (board[r][c] == ' ' && board[r][c + 1] == playerChar && board[r][c + 2] == playerChar) count++;
    }
  }

  //vertical
  for (int c = 0; c < 7; c++) {
    for (int r = 0; r < 4; r++) {
      if (board[r][c] == ' ' && board[r + 1][c] == playerChar && board[r + 2][c] == playerChar) count++;
    }
  }

  //diagonal
  for (int r = 0; r < 4; r++){
    for (int c = 0; c < 5; c++){
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
  int count = 0;

  //horizontal
  for (int r = 0; r < 6; r++) {
    for (int c = 0; c < 4; c++){
      if (board[r][c] == playerChar && board[r][c + 1] == playerChar && board[r][c + 2] == playerChar && board[r][c + 3] == ' ') count++;
      if (board[r][c] == ' ' && board[r][c + 1] == playerChar && board[r][c + 2] == playerChar && board[r][c + 3] == playerChar) count++;
    }
  }

  //vertical
  for (int c = 0; c < 7; c++) {
    for (int r = 0; r < 3; r++) {
      if (board[r][c] == ' ' && board[r + 1][c] == playerChar && board[r + 2][c] == playerChar && board[r + 3][c] == playerChar) count++;
    }
  }

  //diagonal
  for (int r = 0; r < 3; r++){
    for (int c = 0; c < 4; c++){
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

  for (int r = 0; r < 6; r++){
    for (int c = 0; c < 4; c++){
      if (board[r][c] == playerChar && board[r][c + 1] == playerChar &&
          board[r][c + 2] == playerChar && board[r][c + 3] == playerChar) return true;
    }
  }

  for (int c = 0; c < 7; c++) {
    for (int r = 0; r < 3; r++) {
      if (board[r][c] == playerChar && board[r + 1][c] == playerChar &&
          board[r + 2][c] == playerChar && board[r + 3][c] == playerChar) return true;
    }
  }

  for (int r = 0; r < 3; r++){
    for (int c = 0; c < 4; c++){
      if (board[r][c] == playerChar && board[r + 1][c + 1] == playerChar &&
          board[r + 2][c + 2] == playerChar && board[r + 3][c + 3] == playerChar) return true;
      if (board[r][c + 3] == playerChar && board[r + 1][c + 2] == playerChar &&
          board[r + 2][c + 1] == playerChar && board[r + 3][c] == playerChar) return true;
    }
  }
  return false;
}

//High value is good for AI. Low value is good for player.
int C4GameState::heuristic(bool player){
  if (isWon(player)) return 10000;
  if (isWon(!player)) return -10000;
  int adv = count2(player) + 10*count3(player);
  int dis = count2(!player) + 10*count3(!player);
  return adv - dis;
}
