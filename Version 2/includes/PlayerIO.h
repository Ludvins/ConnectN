#ifndef PLAYERIO_H
#define PLAYERIO_h

#include "Player.h"
#include <iostream>

using namespace std;

class PlayerIO{

public:
  Player GeneratePlayer() const;
  void PrintPoints(Player player) const ;
};

#endif
