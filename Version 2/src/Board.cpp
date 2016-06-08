
#include "Board.h"

Board::Board(const Board& b){
  operator=(b);
}

int Board::GetUnit(int row, int col) const {
      return matrix.GetUnit(row,col);
}

void Board::SetTokkens(int _tokkens){
  tokkens = _tokkens;
}

bool Board::Gravity(int col){
  if ((matrix.GetUnit(0,col) != 0) || !(col >= 0 && col < matrix.GetCols()))
    return false;
  else{

    int i = 0;
    for(i; matrix.GetUnit(i+1,col) == 0 && i+1 < GetRows(); i++);

    bool gravity = matrix.Set(i,col,turn%2 + 1);
    end = LookAround(i,col,linelenght);
    return gravity;
  }
}

bool Board::LookAround(int row, int col, int _linelenght){
  for(int i = -1; i <= 1; i++){

    for(int j = -1; j <= 1; j++){

        if(!(i==0 && j==0) && (GetUnit(row,col) == GetUnit(row+i,col+j))){
      // cout << "There is a coincidente at  " << row << " " << col << " with  " << row+i << " " << col+j << endl;
          int k = 0, t = 1;

          for(k; GetUnit(row+(k+1)*i,col+(k+1)*j) == GetUnit(row,col) ;k++); //This loop looks for the first tokken of the row.

          for(t; t != _linelenght && GetUnit(row+(k*i)-t*i,col+(k*j)-t*j) == GetUnit(row,col); t++); //This loop looks for the las tokken of the row.

          if(t==_linelenght) return true;

        } // IF
    } //FOR
  } // FOR
  return false;
}

void Board::SetKeepPlaying (bool keep){
  keepplaying = keep;
}
void Board::ResetBoard() {
  turn = 0;
  end = false;
  keepplaying = true;
  matrix = Matrix(GetRows(),GetCols());
}

bool Board::BoardIsFull() const {
  bool full = true;;
  for (int i = 0; i< GetCols(); i++) {
    if(GetUnit(0,i) == 0) full = false;
  }
  return full;
}

 ostream& operator<<(ostream &os, const Board &board){
  os << board.matrix;
  os << board.linelenght << " "  << board.turn << " " << board.end << " " << board.keepplaying << " " << board.tokkens << " ";
  return os;
}

 istream& operator>>(istream &is, Board &board){

  is >> board.matrix;
  is >>  board.linelenght >> board.turn  >> board.end >> board.keepplaying >> board.tokkens;
  return is;
}

  Board& Board::operator= (const Board &b){
    matrix = b.matrix;
    linelenght = b.linelenght;
    turn = b.turn;
    end = b.end;
    keepplaying = b.keepplaying;
    tokkens = b.tokkens;

    return *this;
  }
