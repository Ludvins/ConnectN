#ifndef BOARD_H
#define BOARD_H

#include "Matrix.h"
#include <iostream>


using namespace std;

class Board {
   Matrix matrix;
   int linelenght;
   int turn;
   bool end;
   bool keepplaying;
   int tokkens;

public:

  Board(int _rows = 0, int _cols = 0, int _linelenght = 0, int _tokkens = 0) :matrix(_rows, _cols), linelenght(_linelenght), turn(0), end(false), keepplaying(true), tokkens(_tokkens)  {  }
  Board(const Board& board);

  int GetRows() const {return matrix.GetRows();}
  int GetCols() const {return matrix.GetCols();}
  int GetTokens() const {return tokkens;}
  Matrix GetMatrix() const {return matrix;}
  int Getlinelenght() const {return linelenght;}

  int GetUnit(int row, int col) const;

  bool IsGameEnded() const { return end; }
  int GetTurn() const { return turn;}
  bool WannaKeepPlaying() const { return keepplaying; }

  void SetTokkens(int _tokkens);
  void Nextturn (){ turn++; }

  bool Gravity(int col);
  bool LookAround(int row, int col, int _linelenght);


  void SetKeepPlaying (bool keep);
  void ResetBoard();
  bool BoardIsFull() const ;

  friend ostream& operator<<(ostream &os, const Board &board);
  friend istream& operator>>(istream &is, Board &board);

  Board& operator= (const Board& b);



};
  #endif //BOARD_H
