#include "C4GameState.hpp"

C4GameState::C4GameState(){

  board = new char*[6];
  for(int i = 0; i < 6; i++){

    board[i] = new char[7];
    for(int j = 0; j < 7; j++){

      board[i][j] = ' ';

    }

  }

}

C4GameState::~C4GameState(){

  for(int i = 0; i < 6; i++)
    delete[] board[i];

  delete[] board;

}

//Returns the index of the topmost unfilled space in a particular column (-1 if column is full)
int C4GameState::getUnfilledRow(int column){

  for(int i = 5; i <= 0; i--){

    if(board[i][c] == ' ') return i;

  }

  return -1;

}

//Pass a string as "cm" - c = column, m = character indicating which player
GameState C4GameState::move(std::string move){

  int c = (int)move[0];
  char m = move[2];
  board[c][getUnfilledRow(c)] = m;

}

std::vector<std::string> C4GameState::getValidMoves(bool player){

  std::vector<std::string> moves;
  char playerChar = 'x';
  if(player == O_PLAYER) playerChar = 'o';

  for(int  i = 0; i < 7; i++){

    //If the row isn't full, push back a string
    if(getUnfilledRow(i) != -1){

      moves.push_back(i + playerChar);

    }

  }

  return moves;

}

bool C4GameState::isValid(std::string move, bool player){

  std::vector<std::string> valid = this->getValidMoves(player);

  for(int i = 0; i < valid.size(); i++){

    if(move == valid[i]) return true;

  }

  return false;

}

//Who doesn't love ASCII art
void C4GameState::print(){

  cout << "===============" << endl;
  for(int i = 0; i < 6; i++){

    cout << "|";
    for(int  i = 0; i < 7; i++){

      cout << board[i][j] << "|";

    }
    cout << endl;

  }
  cout << "===============" << endl;

}

int C4GameState::count1(bool player){

  for(int i = 0; i < 7; i++){

    //Iterate through rows somehow, adding and subtracting from heuristic based
    // on configuration of column

  }

}

int C4GameState::count2(bool player){

  //Rows
  for(int  i = 0; i < 6; i++){

    //Columns
    for(int j = 0; j < 7; j++){

      //Watch for double-counting

    }

  }

}

int C4GameState::count3(bool player){}

int C4GameState::count4(bool player){}

//High value is good for AI. Low value is good for player.
int C4GameState::heuristic(bool player){
  /*

    Possible configurations:
    1       1(),
    10      ()1(), 2(),
    100     ()2(), 3(),
    1000    ()3(), 4

  */

  //Add vertical, horizontal, and diagonal heuristics

}
