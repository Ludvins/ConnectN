#ifndef BOARDIO_H
#define BOARDIO_H

#include "Board.h"
#include <iostream>

using namespace std;

class BoardIO{

public:

  Board GenerateBoard () const;
  void PrintBoard (Board board) const;
  int Request() const;
  void GameIsEnded () const ;
  bool Keepplaying () const;

};

#endif
