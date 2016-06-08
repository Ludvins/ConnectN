
#include "Player.h"

Player::Player() :wongames(0), points(0){
  name = new char [20];
  for (int i = 0; i<20; i++) name[i] = '0';
}

Player::Player(char* _name) :wongames(0), points(0){
  name = new char [strlen(_name)+1];
  for (int i = 0; i<strlen(_name)+1; i++){
     name[i] = _name[i];
   }
}

 ostream& operator<< (ostream& os, const Player& p){
  os << p.name << endl << p.wongames << " " << p.points << " ";
  return os;
}

 istream& operator>> (istream& is, Player& p){
   char aux[100];
   is.getline(aux,100,'\n');
   Player p2(aux);
   p = p2;
   is >> p.wongames >> p.points;
   return is;
}

  Player& Player::operator= (const Player& p){
	delete [] name;
    name = new char [strlen(p.name)+1];

    for (int i = 0; i<strlen(p.name)+1; i++){
       name[i] = p.name[i];
    }
   wongames = p.wongames;
   points = p.points;
   return *this;
   }


  int Player::AI(const Board& board) const{
    cout << "AI's Turn." << endl;

    int* value = new int [board.GetCols()];
    for(int i= 0; i < board.GetCols(); i++) value[i] = 0; //Inicialize to 0

    for (int i = 0; i < board.GetCols(); i++){ // Traverse the colums.

      if(board.GetUnit(0,i) == 0){ // If the colum isn't full..
        Board aux(board);
        Board aux2(board); //Creation of 2 auxiliars

        aux.Nextturn();

        aux.Gravity(i); // Oponent places a tokken
        aux2.Gravity(i); // AI places a tokken

        if(aux.IsGameEnded() || aux2.IsGameEnded())
          return i;  //If any of them would win, return that colum.

        int row = 1;
        for(row; board.GetUnit(row,i) == 0 && row < board.GetRows()-1; row++); //Calculate the row where the tokken was placed.

        for(int j = 0; j <= aux.Getlinelenght() -3; j++){ //What whould the opponent obtain.

          if(aux.LookAround(row, i, j+2)){
            value[i] += (j+2)*(j+2);
          }
        }// FOR
        for(int j = 0; j <= aux2.Getlinelenght() -3; j++){  //What would AI obtain.

          if(aux2.LookAround(row, i, j+2)){
            value[i] += (j+2)*(j+2);
          }
        } // FOR
        /*
        for(int k = 0; k < aux2.GetCols(); k++){ //Traverse the columns in the next turn, so you can see how the oponent could take advantage of your choice.

          if(aux2.GetUnit(0,k) == 0){ // If isnt full..

            aux2.Nextturn();
            aux2.Gravity(k);  //Place the tokken
            int row2 = 1;

            for(row2; aux2.GetUnit(row2,k) == 0 && row2 < aux2.GetRows()-1; row2++); // Calculate the row where the tokken was placed.

            for(int j = 0; j <= aux2.Getlinelenght() -3; j++){

              if(aux2.LookAround(row2, i, j+2))
                value[i] -= (j+2); //What whould the opponent obtain.
            } // FOR
          } // IF
        } // FOR */


      } // IF
    } // FOR columns

    int* max2 = new int [board.GetCols()];
    for(int l = 0; l < board.GetCols(); l++) max2[l] = 0;

    int max = 0;
    for(int i = 0; i < board.GetCols(); i++) {

      if( value[i] > value[max])
        max = i; // choose the best option
    } // FOR

    max2[0] = max;

    int j = 1;

    for (int k = 0; k < board.GetCols(); k++){

      if(value[max] == value[k] && k != max){
         max2[j] = k;
         j++;
       }
    }
    srand (time(NULL));
    int c = max2[rand() % j];

    delete [] max2;
    delete [] value;

    return c;
  }
