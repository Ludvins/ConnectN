
#include "PlayerIO.h"
#include "Player.h"


Player PlayerIO::GeneratePlayer() const {
  char _name[10];
  cout << "Introduce the name of the player. \n";
  cin.getline(_name,10,'\n');
  Player player(_name);
return player;
}

void PlayerIO::PrintPoints(Player player) const {
  cout << "\n" << player.GetName() << " has obteined " << player.GetPoints() << " points in " << player.GetGames() << " won games.\n";
}
