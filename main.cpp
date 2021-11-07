#include <iostream>
#include <vector>
#include "node.h"
#include "puzzle.h"
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <stdio.h>     
#include <stdlib.h>    


using namespace std;

int main(){

   
    //create varying  input conditions for running tests
    vector<int> f{1,2,3,4,5,6,0,7,8}; // depth of 2
    vector<int> f1{1,2,3,5,0,6,4,7,8}; // depth of 4
    vector<int> f2{1,3,6,5,0,2,4,7,8}; // depth of 8
    vector<int> f3{1,3,6,5,0,7,4,8,2}; // depth of 12
    vector<int> f4{1,6,7,5,0,3,4,8,2}; //depth 16
    vector<int> f5{7,1,2,4,8,5,6,3,0}; //depth 20
    vector<int> h{0,7,2,4,6,1,3,5,8}; //depth 24

    // node*  b = new node(h);
    // time_t begin, end;
    // time(&begin);
    // puzzle a = puzzle();
    // a.set_heuristic(2); 
    // node * answer = a.general_search(b);

    
    // cout << "ANSWER PRINT NODE:" << endl;

    // answer->print_node();
    // cout << endl << "DEPTH " << endl << answer->get_depth();
    // cout << endl;


    // time(&end);
    // time_t elapsed = end - begin;
    
    // printf("Time measured: %ld seconds.\n", elapsed);

    // cout << endl;



    //     // !HEURISTIC 2
    // time_t begin2, end2;
    // time(&begin2);
    // puzzle a2 = puzzle();
    // a2.set_heuristic(3); 
    // node * answer2 = a2.general_search(b);

    
    // cout << "ANSWER PRINT NODE:" << endl;

    // answer2->print_node();
    // cout << endl << "DEPTH " << endl << answer2->get_depth();
    // cout << endl;

    // time(&end2);
    // time_t elapsed2 = end2 - begin2;
    
    // printf("Time measured: %ld seconds.\n", elapsed2);

    // cout << endl;



    // // !HEURISTIC 3
    // time_t begin3, end3;
    // time(&begin3);
    // puzzle a3 = puzzle();
    // a3.set_heuristic(1); 
    // node * answer3 = a3.general_search(b);

    
    // cout << "ANSWER PRINT NODE:" << endl;

    // answer3->print_node();
    // cout << endl << "DEPTH " << endl << answer3->get_depth();
    // cout << endl;

    // time(&end3);
    // time_t elapsed3 = end3 - begin3;
    
    // printf("Time measured: %ld seconds.\n", elapsed3);

    // cout << endl;

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
    
    cout << "Welcome to Sevi's 8-Puzzle Solver!" << endl;
    cout << "1 to enter your own 8-puzzle, 2 to use a random one."; 
    cout << endl;
    
    int puzzletype;
    cin >> puzzletype;
    cout << puzzletype;
    cout << endl;

    vector<int> input{1,2,3,4,5,6,0,7,8};

    if(puzzletype == 1){
        cout << "Enter your own puzzle. Hit enter after each number." << endl;
        for(int i = 0; i<9; i++){
            cin>> input.at(i);
        }
    }
    if(puzzletype != 1){
        //random 8 puzzle generation
        srand (time(NULL));
       for(int i = 0; i < 90; i++){
           int rand1 = rand() % 8;
           int temp = input.at(rand1);
            input.at(rand1) = input.at(0);
            input.at(0) = temp;
       }
    }

    cout << endl << "Your 8 puzzle: " <<  endl;
    for(int i = 0; i<9; i++){
            cout << input.at(i);
            if(i%3 == 2){
                cout << endl;
            }
    }

    int heuristic;
    cout << "Pick Heuristic (1 for UCS, 2 for Manhattan, 3 for Misplaced Tile" << endl;
    cin >> heuristic;


    node*  b = new node(input);
    puzzle a2 = puzzle();
    a2.set_heuristic(heuristic); 
    node * answer = a2.general_search(b);


    while(answer->get_parent() != nullptr){
            answer->print_node();
            answer = answer->get_parent();
        }
    return 0;
}

