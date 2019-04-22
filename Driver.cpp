#include "AI.hpp"
#include "GameState.hpp"
#include "TTTGameState.hpp"
#include "C4GameState.hpp"

#include <iostream>

#define TIC_TAC_TOE_DEPTH 9

using namespace std;

//Checks a user-input string for validity
//@param check the string to check
//@param from the lower limit for check
//@param to the upper limit for check
bool inputInRange(string check, int from, int to){

  return (check >= to_string(from) && check <= to_string(to));

}


//Converts the user's input string to a TTT movestring usable by gs.move()
//@param input the input string to convert
//@param player whether player character is o
string toMovestring(string input, bool player){

  char column = (char)((stoi(input) - 1) % 3 + 48);
  if(input == "1" || input == "2" || input == "3") input = "0";
  else if(input == "4" || input == "5" || input == "6") input = "1";
  else input = "2";
  input += column;
  input = (player) ? (input + 'o') : (input + 'x');
  return input;

}

//Prompts user for move in ttt
//@param player whether player character is o
string tttPromptForMove(bool player){

  cout << "Where would you like to move?" << endl;
  cout << "(1, 2, 3," << endl <<
          " 4, 5, 6," << endl <<
          " 7, 8, 9)" << endl;
  string input;
  getline(cin, input);

  while(!inputInRange(input, 1, 9)){

   cout << "Invalid move. Please choose again." << endl;
   getline(cin, input);

  }
  input = toMovestring(input, player);

  return input;

}

//Prompts user for a move in C4
//@param player whether player character is o
string c4PromptForMove(bool player){

  cout << "Where would you like to go?" << endl;

  string input;
  getline(cin, input);

  while(!inputInRange(input, 1, 7)){

    cout << "Invalid move. Please choose again." << endl;
    getline(cin, input);

  }
  input = (player) ? (input + 'o') : (input + 'x');
  return input;

}

//Prompts user for choice of game to play (TTT or C4)
int gamePrompt(){

  cout << "====================================" << endl;
  cout << "Welcome! What game would you like to play?" << endl;
  cout << "1) Tic-tac-toe" << endl;
  cout << "2) Connect 4" << endl;
  cout << "====================================" << endl;

  string input;
  getline(cin, input);
  if(inputInRange(input, 1, 2)) return stoi(input);

}

bool checkEnd(GameState* master){

  //Check for win or tie
  if(master->isWon(true)){

    master->print();
    cout << "Player wins!!" << endl;
    return true;

  }
  if(master->isWon(false)){

    master->print();
    cout << "AI wins!!" << endl;
    return true;

  }
  if(master->getValidMoves(true).empty()){

    master->print();
    cout << "Tie!" << endl;
    return true;

  }

}

//Drives tic tac toe
void playTTT(){

  //TODO: Allow player to choose x or o

  GameState* master = new TTTGameState;
  AI ai(false);
  string input;
  string playerMove;
  bool player = true;

  //Game
  while (true) {
    //Print board
    master->print();
    cout << endl;

    //Player turn
    playerMove = tttPromptForMove(player);
    if (master->isValid(playerMove, true)) {
      //cout << "Moving to " << playerMove << endl;
      master = master->move(playerMove);
    } else {
      while (!master->isValid(playerMove, true)) {

        cout << "Invalid move. Please choose again." << endl;
        getline(cin, playerMove);
        playerMove = toMovestring(playerMove, player);
      }
      //cout << "Moving to " << playerMove << endl;
      master = master->move(input);
    }

    master->print();

    //AI turn
    if (player == TTTGameState::X_PLAYER) {
      string bm = ai.getBestMove(master);
      cout << "AI is playing..." << bm << endl;
      master = master->move(bm);
      cout << endl;
    }

    //Check for win or tie
    if(master->isWon(player)){

      master->print();
      cout << "Player wins!!" << endl;
      return;

    }

    if(master->isWon(!player)){

      master->print();
      cout << "AI wins!!" << endl;
      return;

    }
    if(master->getValidMoves(player).empty() && master->getValidMoves(!player).empty()){

      master->print();
      cout << "Tie!" << endl;
      return;

    }

  }

}

//Drives C4 (unimplemented)
void playC4(){

  //TODO: allow player to choose x or o

  GameState* master = new C4GameState;
  AI ai(false);
  string input;
  string playerMove;
  bool player = true;

  while(true){

    master->print();
    cout << endl;

    //Player turn
    playerMove = c4PromptForMove(player);
    if (master->isValid(playerMove, true)) {
      // cout << "Moving to " << playerMove << endl;
      master = master->move(playerMove);
      master->print();
    } else {
      while (!master->isValid(playerMove, true)) {
        cout << "Invalid move. Please choose again." << endl;
        cout << playerMove << endl;
        getline(cin, playerMove);
        playerMove = (player) ? (playerMove + 'x') : (playerMove + 'o');
      }
      master = master->move(playerMove);
    }

    if(checkEnd(master)) return;

    //AI turn
    string bm = ai.getBestMove(master);
    cout << "AI is playing..." << endl;
    master = master->move(bm);

    if(checkEnd(master)) return;
  }

}

int main() {

  switch(gamePrompt()){

    case 1:
      playTTT();

    case 2:
      playC4();

  }

}
