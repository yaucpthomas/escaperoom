#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Player{
  string name, location, inventory[10];
  int seed;
};

void StartNewGame(Player& player);

int main()
{
  //To determine whether player is new or not
  Player player;
  string command;
  cout<<"Hello there. New player or load old game files?\n"
      <<"Type \"NewPlayer\" for New Player or \"LoadGame\" to Load Game Files\n";
  cin>>command;
  //Check the command is valid or not
  while (command != "NewPlayer" && command != "LoadGame" ){
    cout<<"\nInvalid Command! Type Again\n"
        <<"Type \"NewPlayer\" for New Player or \"LoadGame\" to Load Game Files\n";
    cin>>command;
  }

  if (command == "NewPlayer"){
    StartNewGame(player);
  }
  else {

  }

}

void StartNewGame(Player& player){
  cout<<"What's your name?\n";
  string temp;
  cin>>temp;
  player.name = temp;

  cout<<"Type your favourite number (Must be positive integer)\n";
  int seed;
  cin>>seed;
  player.seed = seed;
}
