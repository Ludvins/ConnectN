#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
  int data[20][20];
  int rows, cols;


public:

  Matrix(int _rows, int _cols);

  int GetRows() const { return rows; }
  int GetCols() const { return cols; }

  int GetUnit(int row, int col) const ;
  bool Set(int row, int col, int value);

};
#endif //matrix_H
