#ifndef PUZZLE_H
#define PUZZLE_H

using namespace std;

class puzzle {
private:
//   vector<Vertex> vertices;
public:
  puzzle();
  void queue_children();
  void breadth_first();
};



#endif
