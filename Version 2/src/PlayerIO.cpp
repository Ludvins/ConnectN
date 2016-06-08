
#include "PlayerIO.h"
#include "Player.h"


Player PlayerIO::GeneratePlayer() const {
  char _name[100];
  cout << "Introduce the name of the player." << endl;
  cin.getline(_name,100,'\n');
  Player player(_name);
return player;
}

void PlayerIO::PrintPoints(Player player) const {
  cout << endl << player.GetName() << " has obtained " << player.GetPoints() << " points in " << player.GetGames() << " won games." << endl;
}
