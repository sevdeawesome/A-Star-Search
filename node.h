#ifndef NODE_H
#define NODE_H

using namespace std;

class node {
private:
  
  node* parent;
  

public:
  int data[3][3]; 
  node(){
    int x = 0;
    for(int i = 0; i< 3; i++){
      for(int j = 0; j< 3; j++){
        data[i][j] = x;
        x++;
      }
    }
  };

  void print_node(){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j< 3; j++){
        cout << data[i][j];
      }
      cout<< endl;
    }
  };

  

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
