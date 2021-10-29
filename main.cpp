#include <iostream>
#include <vector>
#include "node.h"
#include "puzzle.h"



using namespace std;

int main(){

    node b = node();

   

    vector<int> f{2,3,4,5,1,7,1,3,0};

    cout << f.size();

    for (auto i = f.begin(); i != f.end(); ++i)
        cout << *i << " ";
  

    cout << f.size();





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