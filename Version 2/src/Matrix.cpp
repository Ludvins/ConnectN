

#include "Matrix.h"

Matrix::Matrix(){
  rows = cols = 0;
  data = new int[1];
  data[0] = 0;
}

  Matrix::Matrix(int _rows, int _cols): rows(_rows), cols(_cols){
    if(rows== 0 || cols == 0)
      data = 0;
    else{
      int* m = new int [rows*cols];
      for (int i= 0; i < rows*cols; i++)
        m[i] = 0;

      data = &m[0];
    }
  }

  Matrix::Matrix(const Matrix &m){
    operator=(m);
  }

  int Matrix::GetUnit(int row, int col) const {
    if(row < rows && row >= 0 && col>= 0 && col < cols)
      return data[row*cols + col];
    else return 0;
}

  int Matrix::GetUnit(int i) const {
    if(i/cols < rows && i/cols >= 0 && i%cols>= 0 && i%cols < cols)
      return data[i];
    else return 0;
  }

  bool Matrix::Set(int _row, int _col, int _value){
    bool set = _value >= 1 && _value <= 2;

    if (set)
      data[_row*cols + _col] = _value;

    return set;
  }

  bool Matrix::Set(int i, int _value){
    bool set = _value >= 1 && _value <= 2;

    if (set)
      data[i] = _value;

    return set;
  }

  Matrix& Matrix::operator=(const Matrix& m){
    delete [] data;
    rows = m.rows;
    cols = m.cols;
    data = new int[rows*cols];
    
    for (int i = 0; i < rows*cols; i++){
      data[i] = m.data[i];
    }
    return *this;
  }


   ostream& operator <<(ostream &os, const Matrix &m){
    os << m.rows << " " << m.cols<< " " ;
    for(int i = 0; i<m.rows*m.cols; i++){
      os << m.data[i] << " ";
    }
    return os;
  }

   istream& operator >>(istream &is, Matrix &m){

    is >> m.rows >> m.cols;
    m.data = new int [m.rows*m.cols];
    for(int i = 0; i< m.rows*m.cols; i++){
      is >> m.data[i];
    }
    return is;
  }




  Matrix::~Matrix(){
    rows = 0;
    cols = 0;
    delete []data;
  }
