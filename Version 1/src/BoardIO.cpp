

#include "BoardIO.h"
#include "Board.h"


  Board BoardIO::GenerateBoard () const {
    int row, col, line;
    cout << "Introduce the number of rows, columns and tokens to align -> ";
    cin >> row >> col >> line;
    Board board(row, col, line);
    cin.ignore();
    return board;
  }
  void BoardIO::PrintBoard (Board board) const {
    cout << "\n\n";
    for(int i = 0; i < board.GetCols(); i++){
      cout << i << " ";
    } cout << "\n";
    for (int i = 0; i < board.GetRows()*board.GetCols(); i++) {
      if (i%board.GetCols() == 0) cout << "\n";
      if(board.GetUnit(i/board.GetCols(), i%board.GetCols()) == 0) cout << "  ";
      else {
        if(board.GetUnit(i/board.GetCols(), i%board.GetCols()) == 1) cout << "X ";
        else if(board.GetUnit(i/board.GetCols(), i%board.GetCols()) == 2) cout << "O ";
      }
    }
  }

  int BoardIO::Request() const{
    int col;
    cout << "\nIn which column do you want to place the token? ";
    cin >> col;
    return col;
  }

  void BoardIO::GameIsEnded () const{
    cout << "\n\nThe game has ended.;\n\n";
  }

  bool BoardIO::Keepplaying () const{
    char answer;
    cout << "\nDo you want to keep playing? Y/N   ";
    cin >> answer;
    if(answer == 'Y')  return true;
    else return false;
  }
