#include "AI.hpp"
#include "GameState.hpp"
#include "TTTGameState.hpp"
#include "C4GameState.hpp"

#include <iostream>

#define TIC_TAC_TOE_DEPTH 9

using namespace std;

// inputInRange function
// checks a user-input string for validity
// @param: the string to check
// @param: the lower limit for check
// @param: the upper limit for check
// @return: whether the string is in the limits
bool inputInRange(string check, int from, int to) {
  return (check >= to_string(from) && check <= to_string(to));
}

// gamePrompt function
// prompts user for choice of game to play (TTT or C4)
// @return: game to play (1 for TTT, 1 for C4)
int gamePrompt() {
  cout << "====================================" << endl;
  cout << "Welcome! What game would you like to play?" << endl;
  cout << "1) Tic-tac-toe" << endl;
  cout << "2) Connect 4" << endl;
  cout << "====================================" << endl;

  string input;
  getline(cin, input); // get input
  while (!inputInRange(input, 1, 2)) { // loop until input is valid
    cout << "Invalid choice. Please choose again." << endl;
    getline(cin, input);
  }
  return stoi(input);
}

// promptPlayer function
// asks player whether they want to be x or o
// @return: which player they want to be
bool promptPlayer() {
  cout << "Which player would you like to be?" << endl;
  cout << "1) x" << endl;
  cout << "2) o" << endl;

  string input = "";
  getline(cin, input); // get input
  while (!inputInRange(input, 1, 2)) { // loop until input is valid
    cout << "Invalid choice. Please choose again." << endl;
    getline(cin, input);
  }

  return (input == "1") ? TTTGameState::X_PLAYER : TTTGameState::O_PLAYER;
}

// promptDepth function
// asks the player to choose a game tree depth
// @return: depth for game tree
int promptDepth() {
  cout << "Please enter the depth of the game tree to search (1 - 9)" << endl;

  string input = "";
  getline(cin, input); // get input
  while (!inputInRange(input, 1, 9)) { // loop until input is valid
    cout << "Invalid choice. Please choose again." << endl;
    getline(cin, input);
  }
  return stoi(input);
}

// checkEnd function
// checks if game has ended and outputs if it has
// @param: gamestate to check
// @param: which player is the human (vs computer)
// @return: if game has ended
bool checkEnd(GameState* master, bool player) {
  if(master->isWon(player)) {
    master->print();
    cout << "Player wins!!" << endl;
    return true;
  }
  if(master->isWon(!player)) {
    master->print();
    cout << "AI wins!!" << endl;
    return true;
  }
  if(master->getValidMoves(player).empty() && master->getValidMoves(!player).empty()) { // no valid moves left
    master->print();
    cout << "Tie!" << endl;
    return true;
  }
  return false;
}

// toMoveString function
// converts the user's input string to a movestring usable by gs.move()
// @param: the input string to convert
// @param: whether player character is x or o
// @return: string representing move
string toMovestring(string input, bool player){
  char column = (char)((stoi(input) - 1) % 3 + 48); // which column player chose
  if(input == "1" || input == "2" || input == "3") input = "0"; // first row
  else if(input == "4" || input == "5" || input == "6") input = "1"; // second row
  else input = "2"; // third row
  input += column; // append column to input
  input = (player == TTTGameState::X_PLAYER) ? (input + 'x') : (input + 'o'); // append piece
  return input;
}

// tttPrompForMove function
// prompts user for move in ttt
// @param: whether player character is x or o
// @return: user's move
string tttPromptForMove(bool player){
  cout << "Where would you like to move?" << endl;
  cout << "(1, 2, 3," << endl <<
          " 4, 5, 6," << endl <<
          " 7, 8, 9)" << endl;
  
  string input;
  getline(cin, input); // get input
  while(!inputInRange(input, 1, 9)) { // loop until input is valid
   cout << "Invalid move. Please choose again." << endl;
   getline(cin, input);
  }
  input = toMovestring(input, player);

  return input;
}


// c4PrompForMove function
// prompts user for move in ttt
// @param: whether player character is x or o
// @return: user's move
string c4PromptForMove(bool player){
  cout << "Where would you like to go?" << endl;

  string input;
  getline(cin, input); // get input
  while(!inputInRange(input, 1, 7)) { // loop until input is valid
    cout << "Invalid move. Please choose again." << endl;
    getline(cin, input);
  }
  int inputC = stoi(input) - 1;
  input = (player) ? (to_string(inputC) + 'o') : (to_string(inputC) + 'x'); // append piece
  
  return input;
}

int main() {
  int game = gamePrompt(); // have user choose game
  const int TTT = 1;
  const int C4 = 2;

  bool player = promptPlayer(); // have user choose player
  GameState* master; // create master gamestate
  if (game == TTT) master = new TTTGameState;
  else master = new C4GameState;
  AI ai(!player, promptDepth()); // create AI with chosen depth

  string input;
  string playerMove;

  while (true) { // main game loop
    if (player == TTTGameState::O_PLAYER) { // AI goes first
      cout << "AI is playing, may take a while..." << endl;
      string bm = ai.getBestMove(master); // get best move for AI
      master = master->move(bm); // make move
    }

    master->print();
    cout << endl;

    if (checkEnd(master, player)) return 0; // check for win

    if (game == TTT) playerMove = tttPromptForMove(player); // prompt move for ttt
    else playerMove = c4PromptForMove(player); // prompt move for c4
    if (master->isValid(playerMove, player)) {
      master = master->move(playerMove); // make move
    } else {
      while (!master->isValid(playerMove, player)) { // loop until move is valid
        cout << "Invalid move. Please choose again." << endl;
        getline(cin, playerMove);
        if (game == TTT) playerMove = toMovestring(playerMove, player); // get move
        else playerMove = (player) ? (playerMove + 'x') : (playerMove + 'o'); // get move
      }
      master = master->move(playerMove); // make move
    }
    
    if (checkEnd(master, player)) return 0; // check for win

    master->print();
    cout << endl;

    if (player == TTTGameState::X_PLAYER) { // AI goes second
      cout << "AI is playing, may take a while..." << endl;
      string bm = ai.getBestMove(master); // get best move for AI
      master = master->move(bm); // make move
    }

    if (checkEnd(master, player)) return 0; // check for win
  }
}
