#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;

class node {
private:
  
  node* parent;
  int depth;   //depth of the node
  int h; //heuristic value

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

  // returns the x coordinate of the blank tile
  int findY(){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        if(data[i][j] == 0){
          return i;
        }
      }
    }

    return 0;
  }

  // returns the y coordinate of the blank tile
  int findX(){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        if(data[i][j] == 0){
          return j;
        }
      }
    }
    return 0;
  }



// OPERATORS - move blank LRDU
  bool can_createL();

  void create_childL(){

    int x = findX();
    int y = findY();
    if(x > 0){
      int temp = data[y][x-1];
      data[y][x-1] = data[y][x];
      data[y][x] = temp;
    }
  };

  void create_childR(){
    int x = findX();
    int y = findY();
    if(x < 2){
      int temp = data[y][x+1];
      data[y][x+1] = data[y][x];
      data[y][x] = temp;
    }
  };
  void create_childD(){
    int x = findX();
    int y = findY();
    if(y < 2){
      int temp = data[y+1][x];
      data[y+1][x] = data[y][x];
      data[y][x] = temp;
    }
  }
  void create_childU(){
    int x = findX();
    int y = findY();
    if(x > 0){
      int temp = data[y-1][x];
      data[y-1][x] = data[y][x];
      data[y][x] = temp;
    }
  }
  
};



#endif
