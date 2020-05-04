#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "player.h"
#include "LoadGame.h"
#include <thread>
#include <chrono>
using namespace std;

void StartNewGame(Player& player);
void StartScene();

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
    StartScene();
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

  cout<<"That's it! The Game will begin shortly........\n";
  this_thread::sleep_for (chrono::seconds(1));
  cout<<".\n";
  this_thread::sleep_for (chrono::seconds(1));
  cout<<".\n";
  this_thread::sleep_for (chrono::seconds(1));
  cout<<".\n";
  this_thread::sleep_for (chrono::seconds(1));
  cout<<".\n\n\n";
  this_thread::sleep_for (chrono::seconds(2));

}

void StartScene(){
  cout<<"(Door knocked)\n"
      <<"Who’s there?\n"
      <<"Oleg. Oleg Penkovsky. Джордж Кисевальтер (countersign)\n"
      <<"Come in first, my pal. (Door opens) Things go right and we're gonna leave as soon...\n"
      <<"Popov, you bastard. Caught him right now!\n"
      <<"Wait, what? Not Oleg?? (How come KGB knows the sign...)\n"
      <<"Man, you’re so damn bold, huh? How dare you betray your own country? (Pager rings) Sir, we got em. We’ll return now. (Hang up the call) Bring him to the car and give him the taste of pain.\n"
      <<"No god! Please no!!! NOOO… (Fainted by head hit)\n"
      <<"\n[Press enter to continue]\n";
  cin.ignore();

}
