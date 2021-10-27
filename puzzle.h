#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <queue>
#include "node.h"
#include <vector>

using namespace std;

class puzzle {
private:
  queue<node> nodes;
  vector<node> visited;
  node goal = node();

public:
  puzzle();
  void queue_children();
  void breadth_first();
  void set_goalState();
  void set_initialState();
};



#endif
