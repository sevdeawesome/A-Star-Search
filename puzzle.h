#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <queue>
#include "node.h"
#include <vector>

using namespace std;

class puzzle {
private:
 
 //queue of nodes to visit (last one is next in line), ordered in rank of heuristic
  vector<node> queue;
  vector<node> visited;   // already visited nodes (vector)
  node goal = node();    //goal state (default constructor gives  0 1 2 3 4 5 6 7 8)

  int heuristic = 1;

public:
  puzzle();
  void set_goalState();  //set the goal state
  void add_nodes(node input){
    queue.push_back(input);
  };   //set the starting state (for testing)
  void add_visited(node input){
    visited.push_back(input);
  };

  void set_heuristic(int h){
    heuristic = h;
  }


  //returns a vector of nodes (children of the input node)
  vector<node> create_children(node input){
    vector<node> children;
    node a = input; 
    a.set_parent(&input);
    a.increment_depth();

    if(input.can_createD()){
      node b = a;
      b.create_childD();
      children.push_back(b);

    }
    if(input.can_createU()){
      node b = a;
      b.create_childU();
      children.push_back(b);
    }
    if(input.can_createR()){
      node b = a;
      b.create_childR();
      children.push_back(b);
    }
    if(input.can_createL()){
      node b = a;
      b.create_childL();
      children.push_back(b);
    }
    return children;
  }

    // void general_search(problem, QUEUEING-FUNCTION){

    //     nodes = puzzle.MAKE-QUEUE(node())
    //     node NODE = node();
    //     if(nodes.empty() == true){
    //         return "fail";
    //     }
    //     while(nodes.empty() == false ){
    //         NODE = nodes.pop();
    //         if(problem.GOAL-TEST(node.STATE)){
    //             return NODE;
    //             break;
    //         }
    //         nodes = QUEUEING-FUNCTION(nodes, node.EXPAND());
    //     }
    // }
  void general_search(){

  };  //this is the search method that will run loop as pseudocode example



  //pass in new nodes, pass in heuristic assign them heuristic and add them to queue in order 

  // 1 = UCS, 2 = MANHATTAN DISTANCE, 3 = MISPLACED TILES
  void queueing_function(vector<node> new_nodes){
    if(heuristic == 1){
      
    }
  }


};



#endif
