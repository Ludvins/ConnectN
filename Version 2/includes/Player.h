#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Player{
  char* name;
  int wongames;
  int points;
  bool isAI;

public:

  Player();
  Player(char* _name);

  void Addpoints (int _points){points += _points;}

  void Addgame(){ wongames++; }

  const char* GetName() const { return name;}

  bool GetAI() const { return isAI;}
  int GetPoints() const { return points; }
  int GetGames() const { return wongames; }

  friend ostream& operator<< (ostream& os, const Player& p);
  friend istream& operator>> (istream& is, Player& p);

  Player& operator= (const Player& p);

  bool operator== (const Player& p);

  int AI(const Board& board) const;

};

#endif //PLAYER_H
