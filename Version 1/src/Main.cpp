
#include "Matrix.h"
#include "Board.h"
#include "Player.h"
#include "PlayerIO.h"
#include "BoardIO.h"


int main(){

//Generar tablero
  BoardIO boardIO;
  Board board = boardIO.GenerateBoard();

//Generar jugadores.
  PlayerIO playerIO;
  Player player1 = playerIO.GeneratePlayer();
  Player player2 = playerIO.GeneratePlayer();
  Player *players[2];
  players[0] = &player1;
  players[1] = &player2;

  boardIO.PrintBoard(board);

  while(board.WannaKeepPlaying()){

  cout << "\n\n\t Turn number:  " << board.GetTurn() <<"\n";

  //Pedir pieza y Colocar pieza
    if(board.Gravity(boardIO.Request())){
    //Pintar tablero.
    boardIO.PrintBoard(board);
    if (board.IsGameEnded() || board.BoardIsFull()){ //Comprobar si ha terminado por algun motivo.
       boardIO.GameIsEnded();                       // Mensaje de que la partida ha terminado
       board.SetKeepPlaying(boardIO.Keepplaying()); //Preguntar si se sigue queriendo jugar
       if(board.IsGameEnded()){
          players[board.GetTurn()%2]->Addpoints(board.Getlinelenght());
          players[board.GetTurn()%2]->Addgame();
        }
        playerIO.PrintPoints(player1);
        playerIO.PrintPoints(player2);
        if(board.WannaKeepPlaying()) {
          board.ResetBoard();
        }
      }
    board.Nextturn();
    }
  }
  return 0;

}
