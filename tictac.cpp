#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
#include "behavior.hpp"
using namespace std;

// Main Function
int main(void) {
  Board board;
  Turn turn;
  WinChecker winchecker;
  int first_turn;
  string start;
  char play_again;

  // initializes random seed
  srand(time(NULL));

  cout << "HELLO, TYPE \"\e[1mstart\e[0m\" TO START THE GAME" << endl;
  cin >> start;

  if (start == "start" || start == "Start" || start == "START") {
    goto StartGame;
  } else {
    cout << "Invalid Input, Try Again!\n";
    return main();
  }

StartGame:
  // randomizes the first turn
  first_turn = rand() % 2 + 1; // randomizes between 1 or 2
  if (first_turn == 1) {
    goto X_firstTurn;
  }
  else {
    goto O_firstTurn;
  }

X_firstTurn:
  for (int i = 1; i > 0; i++) {
    system("CLS");    
    winchecker.win_check(); 
    turn.x_turn();
    board.print_board();
    turn.x_indexInput();

    if (winchecker.win_check() == 1) {
      board.print_board();
      goto PlayAgain;
    }      

    system("CLS");
    winchecker.win_check(); 
    turn.o_turn();
    board.print_board();
    turn.o_indexInput();

    if (winchecker.win_check() == 1) {
      board.print_board();
      goto PlayAgain;
    }           
}

O_firstTurn:
  for (int i = 1; i > 0; i++) {
    system("CLS");
    winchecker.win_check(); 
    turn.o_turn();
    board.print_board();
    turn.o_indexInput();

    if (winchecker.win_check() == 1) {
      board.print_board();
      goto PlayAgain;
    }        

    system("CLS");
    winchecker.win_check(); 
    turn.x_turn();
    board.print_board();
    turn.x_indexInput();

    if (winchecker.win_check() == 1) {
      board.print_board();
      goto PlayAgain;
    }       
}

PlayAgain:    
  if(FuncPlayAgain() == 1) {
    system("CLS");
    board.reset_board();
    return main();
  }
}

