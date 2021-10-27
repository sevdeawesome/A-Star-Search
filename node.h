#ifndef NODE_H
#define NODE_H

using namespace std;

class node {
private:
  int data[3][3];
  node* parent;
  

public:
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
  node create_childL();
  node create_childR();
  node create_childU();
  node create_childD();
  void shuffle();
};



#endif
