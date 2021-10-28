#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;

class node {
private:
  
  node* parent;
  

public:

  // 3x3 array for numbers -> 0 is blank
  int data[3][3]; 

  // default constructor
  node(){
    int x = 0;
    for(int i = 0; i< 3; i++){
      for(int j = 0; j< 3; j++){
        data[i][j] = x;
        x++;
      }
    }
  };

// constructor w/ 9 inputs as vector
  node(vector<int> input){
    int x = 0;
    for(int i = 0; i< 3; i++){
      for(int j = 0; j< 3; j++){
        data[i][j] = input.at(x);
        x++;
      }
    }
  }

// print node (for testing)
  void print_node(){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j< 3; j++){
        cout << data[i][j];
      }
      cout<< endl;
    }
  };

  
// returns if node is equal to input node
  bool compare_nodes(node a){
    bool same = true;
    for(int i = 3; i < 3; i++){
      for(int j = 3; j < 3; j++){
        if(a.data[i][j] != data[i][j]){
          same = false;
        }
      }
    }
    return same;
  };


  node create_childL();
  node create_childR();
  node create_childU();
  node create_childD();
  


  void shuffle(){
    // for(int i = 0; i < sizeof(data[0]);i++)
    
  }
};



#endif
