#ifndef BOARD_H
#define BOARD_H

#include "Matrix.h"
#include <iostream>

class Board {
   Matrix matrix;
   int linelenght;
   int turn;
   bool end;
   bool keepplaying;

public:

  Board(int _rows, int _cols, int _linelenght) :matrix(_rows, _cols), linelenght(_linelenght), turn(0), end(false), keepplaying(true) {  }

  int GetRows() const {return matrix.GetRows();}
  int GetCols() const {return matrix.GetCols();}
  int Getlinelenght() const {return linelenght;}
  bool IsGameEnded() const { return end; }
  int GetTurn() const { return turn;}
  bool WannaKeepPlaying() const { return keepplaying; }

  int GetUnit(int row, int col) const ;
  void Nextturn (){ turn++; }

  bool Gravity(int col);
  bool LookAround(int row, int col);


  void SetKeepPlaying (bool keep);
  void ResetBoard();
  bool BoardIsFull() const ;

};
  #endif //BOARD_H
