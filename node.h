#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;

class node {
private:
  
  

public:
  node* parent;
  int depth;   //depth of the node
  int h; //heuristic value
  // 3x3 array for numbers -> 0 is blank
  int data[3][3]; 

  // default constructor
  node(){
    depth = 0;
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
    depth = 0;
    int x = 0;
    for(int i = 0; i< 3; i++){
      for(int j = 0; j< 3; j++){
        data[i][j] = input.at(x);
        x++;
      }
    }
  }

void set_parent(node* p){
  parent = p;
}
node* get_parent(){
  return parent;
}
void set_h(int val){
  h = val;
}
void increment_depth(){
  depth++;
}


// print node (for testing)
  void print_node(){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j< 3; j++){
        cout << data[i][j];
      }
      cout<< endl;
    }

    cout<< endl;
    cout<< endl;
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
  bool can_createL(){
    if(findX() > 0){
      return true;
    }
    return false;
  }


  bool can_createR(){
    if(findX() < 2){
      return true;
    }
    return false;
  }

  bool can_createU(){
    if(findY() > 0){
      return true;
    }
    return false;
  }
  bool can_createD(){
    if(findY() < 2){
      return true;
    }
    return false;
  }

  void create_childL(){
    depth++;
    int x = findX();
    int y = findY();
    if(x > 0){
      int temp = data[y][x-1];
      data[y][x-1] = data[y][x];
      data[y][x] = temp;
    }
  };

  void create_childR(){
    depth++;
    int x = findX();
    int y = findY();
    if(x < 2){
      int temp = data[y][x+1];
      data[y][x+1] = data[y][x];
      data[y][x] = temp;
    }
  };
  void create_childD(){
    depth++;
    int x = findX();
    int y = findY();
    if(y < 2){
      int temp = data[y+1][x];
      data[y+1][x] = data[y][x];
      data[y][x] = temp;
    }
  }
  void create_childU(){
    depth++;
    int x = findX();
    int y = findY();
    if(y > 0){
      int temp = data[y-1][x];
      data[y-1][x] = data[y][x];
      data[y][x] = temp;
    }
  }
  
  vector<int> data_toVector(){
    vector<int> vec;
    for(int i = 0; i< 3; i++){
      for(int j = 0; j< 3; j++){
        vec.push_back(data[i][j]);
      }
    }
    return vec;
  }

  
};



#endif
