#include <iostream>
#include <vector>
#include "node.h"
#include "puzzle.h"



using namespace std;

int main(){

   
    
    vector<int> f{1,2,3,4,5,6,0,7,8}; // depth of 2
    vector<int> f1{1,2,3,5,0,6,4,7,8}; // depth of 4
    vector<int> f2{1,3,6,5,0,2,4,7,8}; // depth of 8
    vector<int> f3{1,3,6,5,0,7,4,8,2}; // depth of 12
    vector<int> f4{1,6,7,5,0,3,4,8,2}; //depth 16
    vector<int> f5{7,1,2,4,8,5,6,3,0}; //depth 20
    vector<int> h{0,7,2,4,6,1,3,5,8}; //depth 24


    node*  b = new node(f4);
    puzzle a = puzzle();
    a.set_heuristic(3); 
    node * answer = a.general_search(b);

    
    cout << "ANSWER PRINT NODE:" << endl;

    answer->print_node();
    cout << endl << "DEPTH " << endl << answer->get_depth();
    cout << endl;


    
    // for(int i = 0; i < answer->get_depth(); i++)
    // {
    //     // answer->print_node();
    //     answer = answer->get_parent();
    //     cout << endl  << i << endl;

    // }

    // while(answer->get_parent() != nullptr){
    //     answer->print_node();
    //     answer = answer->get_parent();
    // }
    
    // cout << "Welcome to Sevi's 8-Puzzle Solver!" << endl;
    // cout << "1 to enter your own 8-puzzle, 2 to use a random one."; 
    // cout << endl;
    
    // int puzzletype;
    // cin >> puzzletype;

    // cout << endl;

    // if()


    return 0;
}


    // answer->get_parent()->get_parent()->get_parent()->print_node();

    // node * parent = answer->get_parent()->get_parent();
    // (*parent).print_node();

    // cout << "ANSWER PARENT " << endl;
    // answer->get_parent()->print_node();

    
    // vector<int> h{2,3,4,5,1,7,5,4,0};
    // node c= node(h);
    // c.print_node();

    // cout << endl << endl;

    // cout << c.compare_nodes(b);