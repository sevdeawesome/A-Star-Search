#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <queue>
#include "node.h"
#include <vector>

using namespace std;

class puzzle {
private:
  queue<node> nodes;  //queue of nodes to visit
  vector<node> visited;   // already visited nodes (vector)
  node goal = node();    //goal state (default constructor gives  0 1 2 3 4 5 6 7 8)

public:
  puzzle();
  void queue_children();
  void set_goalState();  //set the goal state
  void set_initialState();   //set the starting state (for testing)

  void general_search();  //this is the search method that will run loop as pseudocode example
};



#endif
