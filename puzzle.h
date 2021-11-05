#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <queue>
#include "node.h"
#include <vector>
#include <cmath> 

using namespace std;

class puzzle {
private:
 
 //queue of nodes to visit (last one is next in line), ordered in rank of heuristic
  vector<node *> queue;
  vector<node *> visited;   // already visited nodes (vector)
  node goal = node();    //goal state (default constructor gives  0 1 2 3 4 5 6 7 8)

  int heuristic;

public:
  puzzle(){
    heuristic = 1;
  }


    // void general_search(problem, QUEUEING-FUNCTION){
  node * general_search(node * input){
    //measure nodes traversed + max queue size for writeup
    int nodes_traversed = 0;
    int max_queue_size = 0;




    //nodes = MAKE-QUEUE(MAKE-NODE(problem.INITIAL-STATE))
      queue.push_back(input);

      //     loop do 
      while(queue.size() > 0){
        // node = REMOVE-FRONT(nodes)  
        node * curnode = queue.at(queue.size() - 1);
        queue.pop_back();

        // cout << " " << curnode->depth << " " << curnode->get_h() <<  " " << queue.size() <<  endl;
         // ! TODO HERE IS THE DEPTH cout
        
        nodes_traversed++;

        if(max_queue_size < queue.size()){
          max_queue_size = queue.size();
        }
        //  if problem.GOAL-TEST(node.STATE) succeeds then return node
        if(curnode->compare_nodes(goal)){
          cout << endl;
          cout << "ANSWER HAS BEEN FOUND AT DEPTH: " << curnode->depth <<endl <<   " HEURISTIC:  " << heuristic << endl << "NODES TRAVERSED :" << nodes_traversed << endl << " MAX QUEUE SIZE: " << max_queue_size << endl;
          return curnode;
        }



        visited.push_back(curnode);
        //nodes = QUEUEING-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
        queueing_function(curnode);
 
        
      }
      
    //if EMPTY(nodes) then return "failure"
    cout << "FAILURE";
    return nullptr;
  };  

  void add_visited(node * input){
    visited.push_back(input);
  };

  void set_heuristic(int h){
    heuristic = h;
  }

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
      for(int i = 0; i < children.size(); i++){
        compute_manhattan(children.at(i));
        // queue.insert(queue.begin(), children.at(i));
        
        int j = 0;
        while(j < queue.size() && queue.at(j)->get_h() > children.at(i)->get_h()){
          j++;
        }
       std::vector<node*>::iterator it = queue.begin() + j;
        queue.insert(it, children.at(i));
        // cout << j << " ; " << queue.size() << " : " << children.at(i)->get_h() << " : " << queue.at(0)->get_h() << " : " << queue.at(queue.size()-1)->get_h() << endl;
      }
    }

    //misplaced tile heuristic
    else{
      for(int i = 0; i < children.size(); i++){
        compute_misplaced(children.at(i));
        // queue.insert(queue.begin(), children.at(i));
        std::vector<node*>::iterator it = queue.begin();
        int j = 0;
        while(j < queue.size() && queue.at(j)->get_h() > children.at(i)->get_h()){
          j++;
          it++;
        }

        queue.insert(it, children.at(i));
      }
    }
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


  //checking for repeated states
  vector<node*> children2;

    for(int i = 0; i < children.size(); i++ ){
      bool is_repeat = false;
        for(int j = 0; j < visited.size();j++){
          if(visited.at(j)->compare_nodes(*children.at(i))){
            is_repeat = true;
          }
        }
        if(is_repeat == false){
          children2.push_back(children.at(i));
        }
    }
    return children2;
  }







  void compute_manhattan(node* input){
    int h = 0;
    for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
            h+= abs(goal.findX(input->data[i][j]) - j) + abs(goal.findY(input->data[i][j]) - i);
          }
      }
    input->set_h(h + input->get_depth());
    
  }

  void compute_misplaced(node* input){
    int h = 0;
    for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
            if(input->data[i][j] != goal.data[i][j]){
              h++;
            }
          }
      }
      
    input->set_h(h + input->get_depth());
  }


};



#endif
