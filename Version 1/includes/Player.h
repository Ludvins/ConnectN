#ifndef PLAYER_H
#define PLAYER_H

class Player{
  char name[10];
  int wongames;
  int points;

public:

  Player() :wongames(0), points(0){
    for (int i = 0; i<10; i++){ name[i] = '0';}
  }

  Player(char _name[10]) :wongames(0), points(0){
    for (int i = 0; i<10; i++){ name[i] = _name[i];}
  }

  void Addpoints (int _points){
    points += _points;
  }

  void Addgame(){ wongames++; }

  const char* GetName() const { return name;}

  int GetPoints() const { return points; }
  int GetGames() const { return wongames; }



};

#endif //PLAYER_H
