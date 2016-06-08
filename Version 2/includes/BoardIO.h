#ifndef BOARDIO_H
#define BOARDIO_H

#include "Board.h"
#include <iostream>
#include <fstream>
#include "Player.h"
#include <stdlib.h>     /* atoi */

using namespace std;

class BoardIO{

public:

  Board GenerateBoard () const;
  void PrintBoard (const Board& board, ostream& os = cout) const;
  void RequestInfo() const;
  int Request(Board& board,const Player& player1, const Player& player2) const;
  void GameIsEnded () const ;
  bool Keepplaying () const;

  bool SaveGame(const char* filename, const Board& board,const Player& player1, const Player& player2) const;
  bool LoadGame(const char* filename, Board& board, Player& player1, Player& player2);



};

#endif //BOARDIO_H
