#include <iostream>
#include "Student.h"
using namespace std;

class Node {
 public:
  Node(Student* newData);
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newNext);
  ~Node();
  
 private:
  Student* data;
  Node* next;
};
