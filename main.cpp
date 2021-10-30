#include <iostream>
#include <vector>
#include "node.h"
#include "puzzle.h"



using namespace std;

int main(){

   

    vector<int> f{1,3,6,5,0,2,4,7,8};
    node*  b = new node(f);
    

    // node * c = new node();


    // node * d = new node();


    // b.set_parent(c);
    // c->set_parent(d);
    // d->set_parent(&b);


    // d->get_parent()->print_node();
    puzzle a = puzzle();

    node * answer = a.general_search(b);

   
    cout << "ANSWER PRINT NODE:" << endl;

    answer->print_node();

    cout << endl;

    answer->get_parent()->get_parent()->get_parent()->print_node();

    // node * parent = answer->get_parent()->get_parent();
    // (*parent).print_node();

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