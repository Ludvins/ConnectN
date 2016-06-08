
#include "Board.h"
#include "Matrix.h"


int Board::GetUnit(int row, int col) const {
      return matrix.GetUnit(row,col);
}

bool Board::Gravity(int col){

  if (matrix.GetUnit(0,col) != 0){
    return false;
  }
  else
  {
    int i = 0;
    for(i; matrix.GetUnit(i+1,col) == 0 && i+1 < GetRows(); i++);
    bool gravity = matrix.Set(i,col,turn%2 + 1);
    end = LookAround(i,col);
    return gravity;
  }
}

bool Board::LookAround(int row, int col){
  for(int i = -1; i <= 1; i++){
    for(int j = -1; j <= 1; j++){
      if((!(i==0 && j==0)) && (GetUnit(row,col) == GetUnit(row+i,col+j))){
          int k = 0, t = 1;
          for(k; GetUnit(row+(k+1)*i,col+(k+1)*j) == GetUnit(row,col) ;k++); //Busca el inicio de la fila.
          for(t; t != linelenght && GetUnit(row+(k*i)-t*i,col+(k*j)-t*j) == GetUnit(row,col); t++); //Recorre toda la fila en sentido contrario.
          if(t==linelenght) return true;
      }
    }
  }
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
