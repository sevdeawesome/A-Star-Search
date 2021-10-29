#include <iostream>
#include <vector>
#include "node.h"
#include "puzzle.h"



using namespace std;

int main(){

   

    vector<int> f{2,3,4,5,1,7,1,3,0};
    node b = node(f);
    b.print_node();
    // node c = b;
    // c.create_childL();
    // c.set_parent(&b);
    // c.print_node();

    // cout << c.depth;

    // c.get_parent()->print_node();

    // vector<node> vec;

    // for(int i = 0; i < 90000000; i++){
    //     vec.push_back(b);
    // }

    // cout << vec.size();

    




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