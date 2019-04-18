#include "AI.hpp"
#include "GameState.hpp"
#include "TTTGameState.hpp"

#include <iostream>
#include <string>

#define TIC_TAC_TOE_DEPTH 9

using namespace std;

void menu() {
  cout << "-------------------------------------" << endl;
  cout << "Welcome to tic-tac-toe!" << endl;
  cout << "Would you like to be x or o?" << endl;
  cout << "-------------------------------------" << endl;
}

// //For prompting the user at the beginning of a ttt game
// //Unimplemented
// char tttStart(){
//
//
//
// }

int main() {
  GameState* master = new TTTGameState;
  AI ai(false);
  string input;
  while (true) {
    master->print();
    cout << endl;
    getline(cin, input);
    if (master->isValid(input, true)) {
      master = master->move(input);
    } else {
      while (!master->isValid(input, true)) {
       getline(cin, input);
      }
      master = master->move(input);
    }
    string bm = ai.getBestMove(master);
    cout << "ai best move: " << bm << endl;
    master = master->move(bm);
  }
  delete master;
  return 0;
}

//
// //Returns true on game end
// bool tttPlayerTurn(GameState &gs, char playerChar){
//
//   string input;
//
//   cout << "-------------" << endl;
//   gs.print();
//
//   cout << "Which square would you like to choose?" << endl;
//   cout <<
//     "(1, 2, 3," << endl <<
//     " 4, 5, 6," << endl <<
//     " 7, 8, 9)"
//   << endl;
//
//   getline(cin, input);
//
//   //Check input for validity
//   while(input < "1" || input > "9"){
//
//     cout << "Invalid input, please try again" << endl;
//     getline(cin, input);
//
//   }
//
//   char* proposed = {"YEEEEEEET"};
//   do{
//
//     cout << "Move is invalid, please choose again" << endl;
//     getline(cin, input);
//     proposed = gs.getBoard();
//     proposed[stoi(input)] = playerChar;
//
//   }while(!gs.isValid(proposed));
//
//   gs.move(proposed);
//
//   return gs.isWin() != 0;
//
// }
//
// //Returns true on game end
// bool tttAITurn(GameState &gs, AI &bot, char AIChar){
//
//   int move = bot.getBestMove();
//   char* proposed = gs.getBoard();
//
//   proposed[move] = AIChar;
//   gs.move(proposed);
//
//   return gs.isWin() != 0;
//
// }
//
// int main() {
//
//   string input;
//   char playerChar;
//   char AIChar;
//
//   menu();
//   getline(cin, input);
//
//   while(input != "x" && input != "o" && input != "X" && input != "O"){
//
//     cout << "Please enter a valid input" << endl;
//     getline(cin, input);
//
//   }
//
//   if(input == "x" || input == "X"){
//
//     playerChar = 'x';
//     AIChar = 'o';
//
//   }else{
//
//     playerChar = 'o';
//     AIChar = 'x';
//
//   }
//
//   TTTGameState gameState;
//   AI tttBot = AI(start, TIC_TAC_TOE_DEPTH);
//
//   while(true){
//
//     if(tttPlayerTurn(gameState, playerChar)) break;
//     if(tttAITurn(gameState, AIChar)) break;
//
//   }
//
//   if(gs.isWin() == 1){
//
//     cout << "You win!!" << endl;
//     return 0;
//
//   }else{
//
//     cout << "AI wins!!" << endl;
//     return 0;
//
//   }
//
// }
