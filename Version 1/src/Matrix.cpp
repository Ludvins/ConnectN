

#include "Matrix.h"

  Matrix::Matrix(int _rows, int _cols): rows(_rows), cols(_cols){
  for (int i= 0; i < rows*cols; i++) data[i/cols][i%cols] = 0;
}

  int Matrix::GetUnit(int row, int col) const {
    if(row < rows && row >= 0 && col>= 0 && col < cols) return data[row][col];
    else return 0;
}

  bool Matrix::Set(int row, int col, int value){
    bool set = value >= 1 && value <= 2;
    if (set) data[row][col] = value;
    return set;
  }
