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
  vector<node *> queue;
  vector<node> visited;   // already visited nodes (vector)
  node goal = node();    //goal state (default constructor gives  0 1 2 3 4 5 6 7 8)

  int heuristic;

public:
  puzzle(){
    heuristic = 1;
  }
  void set_goalState();  //set the goal state
  void add_nodes(node * input){
    queue.push_back(input);
  };   //set the starting state (for testing)
  void add_visited(node input){
    visited.push_back(input);
  };

  void set_heuristic(int h){
    heuristic = h;
  }


  //returns a vector of nodes (children of the input node)
  vector<node*> create_children(node * input){
    vector<node*> children;
    
   

    if(input->can_createD()){
      node* b = new node(input->data_toVector());
      b->set_parent(input);
      b->set_depth(input->get_depth() + 1);
      b->create_childD();
      children.push_back(b);

    }
    if(input->can_createU()){
      node* b = new node(input->data_toVector());
      b->set_parent(input);
      b->set_depth(input->get_depth() + 1);
      b->create_childU();
      children.push_back(b);
    }
    if(input->can_createR()){
      node* b = new node(input->data_toVector());
      b->set_parent(input);
      b->set_depth(input->get_depth() + 1);
      b->create_childR();
      children.push_back(b);
    }
    if(input->can_createL()){
      node* b = new node(input->data_toVector());
      b->set_parent(input);
      b->set_depth(input->get_depth() + 1);
      b->create_childL();
      children.push_back(b);
    }
    return children;
  }

  // void general_search(problem, QUEUEING-FUNCTION){
  node * general_search(node * input){
  
    //nodes = MAKE-QUEUE(MAKE-NODE(problem.INITIAL-STATE))
      queue.push_back(input);

      //     loop do 
      while(queue.size() > 0){
        // node = REMOVE-FRONT(nodes)  
        node * curnode = queue.at(queue.size() - 1);
        queue.pop_back();

        cout << curnode->depth;

        //  if problem.GOAL-TEST(node.STATE) succeeds then return node
        if(curnode->compare_nodes(goal)){
          cout << endl;
          cout << "ANSWER HAS BEEN FOUND at depth " << curnode->depth <<  endl;
          return curnode;
        }
        // cout << "GETHEREA";
        // curnode->get_parent()->print_node();
        // cout << "Gethereb";



        //nodes = QUEUEING-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
        queueing_function(curnode);
        // cout << endl << queue.size();
        // delete curnode; 
        
      }
      
    //if EMPTY(nodes) then return "failure"
    cout << "FAILURE";
    return nullptr;
  };  



  //pass in node, add children to the queue in order, pass in heuristic assign them heuristic and add them to queue in order 
  // 1 = UCS, 2 = MANHATTAN DISTANCE, 3 = MISPLACED TILES
  void queueing_function(node * input){
    
    vector<node *> children = create_children(input);

    
    // h = 1 and put everything in front
    if(heuristic == 1){
      for(int i = 0; i < children.size(); i++){
        queue.insert(queue.begin(), children.at(i));
        // children.at(i).get_parent()->print_node();
      }
      
    }

    //manhattan distance
    else if(heuristic == 2){

    }

    //misplaced tile heuristic
    else{

    }
  }


};



#endif
