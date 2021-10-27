#include <iostream>
#include <vector>
#include "node.h"
#include "puzzle.h"



using namespace std;

int main(){
    //MAIN LOOP

    node a = node();
    // a.print_node();
  

    node b = node();

    // cout << a.compare_nodes(b);
    
    cout << endl << sizeof(a.data[0]) /sizeof(a.data[0][0]);
    // cout  << endl  << a.data[0].length();



    return 0;
}