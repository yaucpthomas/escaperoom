#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

struct Player{
  std::string name, location;
  int seed;
  std::vector<std::string> inventory;
};

#endif
