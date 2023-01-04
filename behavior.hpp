#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
using namespace std;

// Global Scope
string play_board[20] = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};
string resetted_board[20] = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

// Class Board
class Board {
public:
  void print_board();
  void reset_board();
};

// Methods (Class Board)
void Board::print_board() {
  for (int i = 0; i < 9; i++) {
    if (i % 3 == 0) {
      cout << "\n";
    }
    cout << ' ' << play_board[i];
  }
}

void Board::reset_board() {
  for (int i = 0; i < 9; i++) {
    play_board[i] = resetted_board[i];
  }
}

// Class Turn
class Turn {
  string x = "X";
  string o = "O";
public:
  void x_turn();
  void o_turn();
  void x_indexInput();
  void o_indexInput();
};

// Methods (Class Turn)
void Turn::x_turn() {
  cout << "\n\e[1mX's Turn\e[0m";
}

void Turn::o_turn() {
  cout << "\n\e[1mO's Turn\e[0m";
}

void Turn::x_indexInput() {
  int index_inputNum;
  cout << "\nInput the index (1-9): ";
  indexInput_X: cin >> index_inputNum;
  if (index_inputNum > 0 && index_inputNum < 10 && play_board[index_inputNum - 1] != "-") {
    cout << "Input in the empty index: ";
    goto indexInput_X;
  }

  if (index_inputNum > 9 || index_inputNum < 1 ) {
    cout << "Input between 1 and 9! ";
    goto indexInput_X;
  }
  play_board[index_inputNum - 1] = x;
}

void Turn::o_indexInput() {
  int index_inputNum;
  cout << "\nInput the index (1-9): ";
  indexInput_O: cin >> index_inputNum;
  if (index_inputNum > 0 && index_inputNum < 10 && play_board[index_inputNum - 1] != "-") {
    cout << "Input in the empty index: ";
    goto indexInput_O;
  }

  if (index_inputNum > 9 || index_inputNum < 1 ) {
    cout << "Input between 1 and 9! ";
    goto indexInput_O;
  }
  play_board[index_inputNum - 1] = o;
}

// Class Win/Draw Condition
class WinChecker {
public:
  int win_check();
};

// Methods (Class WinChecker)
int WinChecker::win_check() {

  // X Win
  if (play_board[0]  ==  "X"  && play_board[1]  ==  "X"  && play_board[2] ==  "X" || //straight horizontal row 1
      play_board[3]  ==  "X"  && play_board[4]  ==  "X"  && play_board[5] ==  "X" || //straight horizontal row 2
      play_board[6]  ==  "X"  && play_board[7]  ==  "X"  && play_board[8] ==  "X" || //straight horizontal row 3
      play_board[0]  ==  "X"  && play_board[3]  ==  "X"  && play_board[6] ==  "X" || //straight vertical column 1
      play_board[1]  ==  "X"  && play_board[4]  ==  "X"  && play_board[7] ==  "X" || //straight vertical column 2
      play_board[2]  ==  "X"  && play_board[5]  ==  "X"  && play_board[8] ==  "X" || //straight vertical column 2
      play_board[0]  ==  "X"  && play_board[4]  ==  "X"  && play_board[8] ==  "X" || //diagonal top-left to bottom-right
      play_board[2]  ==  "X"  && play_board[4]  ==  "X"  && play_board[6] ==  "X" )  //diagonal top-right to bottom-left
  {
    cout << "\n\e[1mGame Ended, X Win!\e[0m";
    return 1;
  }

  // O Win
  if (play_board[0]  ==  "O"  && play_board[1]  ==  "O"  && play_board[2] ==  "O" || //straight horizontal row 1
      play_board[3]  ==  "O"  && play_board[4]  ==  "O"  && play_board[5] ==  "O" || //straight horizontal row 2
      play_board[6]  ==  "O"  && play_board[7]  ==  "O"  && play_board[8] ==  "O" || //straight horizontal row 3
      play_board[0]  ==  "O"  && play_board[3]  ==  "O"  && play_board[6] ==  "O" || //straight vertical column 1
      play_board[1]  ==  "O"  && play_board[4]  ==  "O"  && play_board[7] ==  "O" || //straight vertical column 2
      play_board[2]  ==  "O"  && play_board[5]  ==  "O"  && play_board[8] ==  "O" || //straight vertical column 2
      play_board[0]  ==  "O"  && play_board[4]  ==  "O"  && play_board[8] ==  "O" || //diagonal top-left to bottom-right
      play_board[2]  ==  "O"  && play_board[4]  ==  "O"  && play_board[6] ==  "O" )  //diagonal top-right to bottom-left
  {
    cout << "\n\e[1mGame Ended, O Win!\e[0m";
    return 1;
  }

  if (play_board[0] != "-" && play_board[1] != "-" && play_board[2] != "-" && play_board[3] != "-" && 
      play_board[4] != "-" && play_board[5] != "-" && play_board[6] != "-" && play_board[7] != "-" && play_board[8] != "-")
  {
    cout << "\n\e[1mGame Ended, Tie!\e[0m";
    return 1;
  }
  return 0;
}

// Play Again Prototype Function
int FuncPlayAgain() {
  char play_again;
  Condition: cout << "\nPlay again? y/n:  ";
  cin >> play_again;

  if(play_again == 'y' || play_again == 'Y') {
    return 1;
  }
  else if(play_again == 'n' || play_again == 'N') {
    cout << "Thanks for playing!";
    return 0;
  }   
  else {
    cout << "Invalid Character, Input again!";
    goto Condition;
  }     
}
