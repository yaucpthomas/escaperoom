#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "LoadGame.h"
#include "player.h"
#include "puzzle.h"
#include <vector>
using namespace std;
//It reads the file input and load the game status to main
//Input: player,puzzle, filename
//The function pass by player and puzzle data structure to transfer data to the main
//It also pass by filename to automatically save game with the same file again without typing the name again
void LoadGame(Player &player, Puzzle &puzzle, string &filename){
  ifstream fin;
  cout<<"What's your file name? (Must end with .txt and have no space)\n";
  cin>>filename;
  fin.open(filename.c_str());
  //Test whether the file opened successfully or not
  while(fin.fail()){
    cout<<"Error opening file "<<filename<<" !\n"
        <<"Please enter a new file name:\n";
    cin>>filename;
    fin.open(filename.c_str());
  }
  //Read lines in the file
  string line, type, data;
  while(getline(fin,line)){
    istringstream iss(line);
    //Every words in a line and sort accordingly
    iss >> type;
    if (type == "location"){
        iss >> data;
        player.location = data;
    }
    else if (type == "inventory"){
        while(iss >> data){
          replace(data.begin(), data.end(), '_', ' ');
          player.inventory.push_back(data);
        }
    }
    else if (type == "roomb"){
        iss >> data;
        int roomb = stoi(data);
        puzzle.roomb = roomb;
    }
    else if (type == "lookat"){
      while(iss >> data){
        replace(data.begin(), data.end(), '_', ' ');
        player.lookat.push_back(data);
      }
    }
    else if (type == "firststage"){
      iss >> data;
      if (data == "1"){
        player.firststage = true;
      }
      else {
        player.firststage = false;
      }
    }
    else if (type == "secondstage"){
      iss >> data;
      if (data == "1"){
        player.secondstage = true;
      }
      else {
        player.secondstage = false;
      }
    }
    else if (type == "roomblock"){
      iss >> data;
      if (data == "1"){
        puzzle.roomblock = true;
      }
      else {
        puzzle.roomblock = false;
      }
    }
    else if (type == "roomclock"){
      iss >> data;
      if (data == "1"){
        puzzle.roomclock = true;
      }
      else {
        puzzle.roomclock = false;
      }
    }
    else if (type == "roomdlock"){
      iss >> data;
      if (data == "1"){
        puzzle.roomdlock = true;
      }
      else {
        puzzle.roomdlock = false;
      }
    }
    else if (type == "pagerlock"){
      iss >> data;
      if (data == "1"){
        puzzle.pagerlock = true;
      }
      else {
        puzzle.pagerlock = false;
      }
    }
  }
  //Initialise those with fixed passcodes
  puzzle.pencode = "oleg";
  puzzle.rooma = "kramer";
  puzzle.roombclock = 161059;
  puzzle.roomd = 810364;
  puzzle.roomc = 896424;
  cout<<"Loaded your game progress!\n"<<endl;
  fin.close();
}
