

#include "BoardIO.h"

  Board BoardIO::GenerateBoard () const {
    int row, col, line, tokkens;
    cout << "Introduce the number of rows, columns, tokens to align and the ammount of tokkens you want to insert each turn -> ";
    cin >> row >> col >> line >> tokkens;
    Board board(row, col, line, tokkens);
    cin.ignore();
    return board;
  }
  void BoardIO::PrintBoard (const Board& board, ostream& os) const {
    os << endl << endl <<"╔";

    for(int i = 0; i < board.GetCols(); i++){
      os << "══";
    } os << "╗" << endl << "║";

    for(int i = 0; i < board.GetCols(); i++){
      os << i << " ";
    } os << "║"<< endl << "╠";

    for(int i = 0; i < board.GetCols(); i++){
      os << "══";
    } os << "╣" << endl << "║";

    for (int i = 0; i < board.GetRows()*board.GetCols(); i++) {

      if (i%board.GetCols() == 0 && i != 0)
        os << "║"<<endl<<"║";
      if(board.GetUnit(i/board.GetCols(), i%board.GetCols()) == 0)
        os << "  ";
      else {
        if(board.GetUnit(i/board.GetCols(), i%board.GetCols()) == 1)
          os << "X ";
        else
          if(board.GetUnit(i/board.GetCols(), i%board.GetCols()) == 2)
            os << "O ";
      }
    }
    os << "║"<<endl<<"╚";
    for(int i = 0; i < board.GetCols(); i++){
      os << "══";
    } os << "╝" << endl << endl;
  }

  void BoardIO::RequestInfo() const {
    cout << endl <<"You can use this sort of commands to manage the game:"<< endl <<"\tIN X - To insert a tokken on the colum (You can use IN X Y.. to insert more than one token at once)."<< endl <<"\tSAVE filename - To save the game into the file."<< endl <<"\tEXIT - To exit the game." << endl;
  }

  int BoardIO::Request(Board& board,const Player& player1, const Player& player2) const{
    cout << "COMMAND :►  ";

    char selection[20];
    cin.getline(selection,20,'\n');
    cout.flush();

    if(selection[0] == 'I' || selection[0] == 'i'){

      for(int i = 0; i != board.GetTokens(); i++){
        if(!board.Gravity(atoi(selection+(3+(2*i))))) {
          cout << endl << "Not a valid Colum." << endl;
          return -2;
        }//IF
      }//FOR

      return 0;
    } // IF
    else{

      if(selection[0] == 'S' || selection[0] == 's'){

        SaveGame(selection+5, board, player1, player2);
        return -2;
      }//IF

    } // ELSE
    return -1;
  }

  void BoardIO::GameIsEnded () const{
    cout << endl << endl << "The game has ended." << endl << endl;
  }

  bool BoardIO::Keepplaying () const{
    char answer;
    cout << endl << "Do you want to keep playing? Y/N   ";
    cin >> answer;
    return (answer == 'Y' || answer == 'y');
  }

  bool BoardIO::SaveGame(const char* filename, const Board& board,const Player& player1, const Player& player2) const{
    ofstream f(filename,ofstream::out);
    if(f) {
      f << board << player1 << player2;
    }else{
      cerr << "File couldn't be opened" << endl;
      f.setstate(ios::failbit);
    }
    f.close();
    return f;
  }

  bool BoardIO::LoadGame(const char* filename, Board& board, Player& player1, Player& player2){
    ifstream f(filename,ifstream::in);
    if(f){
      f >> board >> player1 >> player2;
    }else{
      cerr << "File couldnt be opened" << endl;
      f.setstate(ios::failbit);
    }
    f.close();
    return f;
  }
