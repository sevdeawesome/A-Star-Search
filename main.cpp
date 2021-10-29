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
    
    // cout << endl << sizeof(a.data[0]) /sizeof(a.data[0][0]);
    // cout  << endl  << a.data[0].length();

    vector<int> f{0,3,4,5,1,7,1,3,2};

    node c = node(f);

    c.print_node();

    c.create_childD();
    cout << endl << "DOWN CHILD" << endl;
    c.print_node();


    // c1.create_childU();
    // cout << endl;
    // c1.print_node();

    // void general_search(problem, QUEUEING-FUNCTION){
    //     nodes = MAKE-QUEUE(MAKE-NODE(problem.INITIAL-STATE))
    //     loop do
    //     if EMPTY(nodes) then return
    //         "failure"
    //         node = REMOVE-FRONT(nodes)
    //     if
    //         problem.GOAL-TEST(node.STATE) succeeds then return node
    //         nodes = QUEUEING-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
    // }

    // void general_search(problem, QUEUEING-FUNCTION){

    //     nodes = puzzle.MAKE-QUEUE(node())
    //     node NODE = node();
    //     if(nodes.empty() == true){
    //         return "fail";
    //     }
    //     while(nodes.empty() == false ){
    //         NODE = nodes.pop();
    //         if(problem.GOAL-TEST(node.STATE)){
    //             return NODE;
    //             break;
    //         }
    //         nodes = QUEUEING-FUNCTION(nodes, node.EXPAND());
    //     }
    // }


    return 0;
}