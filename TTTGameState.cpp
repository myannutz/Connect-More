#include "GameState.hpp"
#include "TTTGameState.hpp"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//Constructor - initialize a dynamic empty board of 9 characters
TTTGameState::TTTGameState(){

  char temp[9] = {
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '
  };
  board = temp;

}

//Destructor - delete the board
TTTGameState::~TTTGameState(){

  delete[] board;

}

//Make a move
void TTTGameState::move(string move){

  if(this->isValid(move)){

    //Is there a better way to do this?
    for(int i = 0; i < 9; i++){

      this->board[i] = move.at(i);

    }

  }

}

//Unfinished
std::vector<std::string> TTTGameState::getValidMoves(){

}

//Checks a move (represented by a string) for validity
bool TTTGameState::isValid(string move){

  int moves = 0;

  for(int i = 0; i < 9; i++){

    /*
      Wherever the current board and proposed move are different,
      if the current board doesn't have an empty space, the move
      is invalid.
      If the proposed move differs from the current board in more
      than one way, or if the boards are identical, the move is invalid.
    */
    if(board[i] != move.at(i)){

      moves++;
      if(move.at(i) != ' ') return false;

    }

  }

  return moves != 1;

}

//Print the tic-tac-toe board for the user
void TTTGameState::print(){

  cout << "=====" << endl <<
    "|" << board[0] << " " << board[0] << " " << board[0] << "|" << endl <<
    "|" << board[0] << " " << board[0] << " " << board[0] << "|" << endl <<
    "|" << board[0] << " " << board[0] << " " << board[0] << "|" << endl <<
          "=====" << endl;

}

char* TTTGameState::getBoard(){

  return board;

}

// Tic-tac-toe heuristic based on Kartik Kukreja's
// https://kartikkukreja.wordpress.com/2013/03/30/heuristic-function-for-tic-tac-toe
// Both players can have 0, 1, 2, or 3 characters in sets of 3,
//  which yields the Heuristic_Array.
// Returns high for human player and low for AI
// Untested (couldn't compile due to vtable error)
// int TTTGameState::heuristic() {
//
//   //Possible positions for pieces to win
//   const int winConditions[8][3] =
//     { 0, 1, 2 },
//     { 3, 4, 5 },
//     { 6, 7, 8 },
//     { 0, 3, 6 },
//     { 1, 4, 7 },
//     { 2, 5, 8 },
//     { 0, 4, 8 },
//     { 2, 4, 6 }
//   };
//
//   const int Heuristic_Array[4][4] = {
//     {     0,   -10,  -100, -1000 },
//     {    10,     0,     0,     0 },
//     {   100,     0,     0,     0 },
//     {  1000,     0,     0,     0 }
//   };
//
//   char piece;
//   int playerPos, AIPos;
//   int score = 0;
//
//   for(int i = 0; i < 8; i++){
//
//     playerPos = AIPos = 0;
//
//     for (int j = 0; j < 3; j++){
//
//       piece = board[winConditions[i][j]];
//
//       if (piece == this->playerChar)
//         playerPos++;
//       else if (piece == this->AIChar)
//         AIPos++;
//
//     }
//
//     score += Heuristic_Array[playerPos][AIPos];
//
//   }
//
//   return score;
//
// }
