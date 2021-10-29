#include <iostream>
#include <vector>
#include "node.h"
#include "puzzle.h"



using namespace std;

int main(){

   

    vector<int> f{1,3,6,5,0,7,4,2,8};
    node b = node(f);
    b.print_node();
    puzzle a = puzzle();

    node * answer = a.general_search(b);

   
    cout << "ANSWER PRINT NODE:" << endl;
    answer->print_node();

    // cout << "ANSWER PARENT " << endl;
    // answer->get_parent()->print_node();
    
    // while(answer->get_parent() != nullptr)
    // {
    //     answer->print_node();
    //     cout << "GOT EHERE";
    //     answer = answer->get_parent();
    // }
    

    // vector<int> h{2,3,4,5,1,7,5,4,0};
    // node c= node(h);
    // c.print_node();

    // cout << endl << endl;

    // cout << c.compare_nodes(b);


    return 0;
}