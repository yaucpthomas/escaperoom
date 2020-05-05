#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LoadGame.h"
#include "player.h"
#include "puzzle.h"
#include <vector>
using namespace std;

void LoadGame(Player &playler, Puzzle &puzzle){
  string filename;
  ifstream fin;
  cout<<"What's your file name? (Must end with .txt and have no space)\n";
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
    iss >> type;
    switch(type){
      case "location":
        iss >> data;
        player.location = data;
      case "seed":
        iss >> data;
        int seed = stoi(data);
        player.seed = seed;
      case "inventory":
        while(iss >> data){
          player.inventory.push_back(data);
        }
      case "roombtoc":
        iss >> data;
        int roombtoc = stoi(data);
        puzzle.roombtoc = roombtoc;
      case "roomc":
        iss >> data;
        int roomc = stoi(data);
        puzzle.roomc = roomc;
    }
  }

  fin.close();
}
