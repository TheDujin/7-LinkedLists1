#include "Student.h"
#include "Node.h"
#include <iostream>

int main() {
  Student* a = new Student(5);
  Student* b = new Student(49);
  Node* x = new Node(a);
  Node* y = new Node(b);
  x->setNext(y);
  cout << a->getID();
  cout << x->getStudent()->getID();
  cout << y->getStudent()->getID();
  cout << x->getNext()->getStudent()->getID();
  return 0;
}
