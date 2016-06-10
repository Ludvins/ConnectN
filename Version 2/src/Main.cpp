
#include "Matrix.h"
#include "Board.h"
#include "Player.h"
#include "PlayerIO.h"
#include "BoardIO.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){

  BoardIO boardIO;
  PlayerIO playerIO;
  Board board;
  Player player1;
  Player player2;

  if(argc > 1){
    if(!boardIO.LoadGame(argv[1], board, player1, player2)) return 0;

  }else{

    board = boardIO.GenerateBoard();
    player1 = playerIO.GeneratePlayer();
    player2 = playerIO.GeneratePlayer();

  }
  //Create an array of Players.
  Player *players[2];
  players[0] = &player1;
  players[1] = &player2;

  boardIO.RequestInfo(); //Output of Game's Manage Info.

  boardIO.PrintBoard(board);

  while(board.WannaKeepPlaying()){

    board.Nextturn();

    int sel = 0;

    cout << "Turno de " << players[board.GetTurn()%2]->GetName();
    board.GetTurn()%2 == 0 ? cout << " (X)." : cout << " (0).";
    cout << endl;

    if(players[board.GetTurn()%2]->GetAI()) { //If the current player is AI.

      for(int i = 1; i <= board.GetTokens(); i++){ // Place a token.

        board.Gravity(players[board.GetTurn()%2]->AI(board));
      }
    }else{

      sel = boardIO.Request(board, player1, player2); //Ask for the tokken and place it.
      if(sel == -1) return 0;

    }
    if(sel == 0){

      boardIO.PrintBoard(board);

      if (board.IsGameEnded() || board.BoardIsFull()){ //Check if the game has ended.
        boardIO.GameIsEnded();                       //Output of a message.

        if(board.IsGameEnded()){ //If the game ended because someone won.

            cout << players[board.GetTurn()%2]->GetName() << " won the game." << endl;
            players[board.GetTurn()%2]->Addpoints(board.Getlinelenght()*((board.GetCols()*board.GetRows()-board.GetTurn()))); //Add Points
            players[board.GetTurn()%2]->Addgame(); // Add games.

          }

        board.SetKeepPlaying(boardIO.Keepplaying()); //Ask for keep playing.


        playerIO.PrintPoints(player1); //Output game results.
        playerIO.PrintPoints(player2);

        if(board.WannaKeepPlaying()) { //If players want to keep playing, reset the board.

          board.ResetBoard();

          boardIO.PrintBoard(board);

          if(players[0] == &player1){ //Each turn a diferent player starts the game.

             players[0] = &player2;
             players[1] = &player1;

          }else{

             players[0] = &player1;
             players[1] = &player2;
          }

        } // IF WannaKeepPlaying

      } // IF Game ended.
    } // IF
  } // WHILE

  return 0;

}
