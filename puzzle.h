#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>

struct Puzzle{
  std::string rooma, pencode;
  int roombclock, roomd,roomc,roomb;
  bool roomblock, roomclock, roomdlock, pagerlock;
};

#endif
