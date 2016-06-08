#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class Matrix {
  int* data;
  int rows, cols;


public:

  Matrix();
  Matrix(int _rows, int _cols);
  Matrix(const Matrix &m);

  int GetRows() const { return rows; }
  int GetCols() const { return cols; }
  void SetRows(int _rows){ rows = _rows;}
  void SetCols(int _cols) { cols = _cols;}

  int GetUnit(int row, int col) const ;
  int GetUnit(int i) const;

  bool Set(int row, int col, int value);
  bool Set(int i, int _value);

  friend ostream& operator <<(ostream &os, const Matrix &m);
  friend istream& operator >>(istream &is, Matrix &m);

  Matrix& operator= (const Matrix& m);

  ~Matrix();

};
#endif //matrix_H
