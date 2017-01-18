#include "Student.h"
#include "Node.h"
#include <iostream>

using namespace std;

int main() {
  Student* a = new Student(5, "Bob", "Joe");
  Student* b = new Student(49, "Bill", "Jones");
  Node* x = new Node(a);
  Node* y = new Node(b);
  x->setNext(y);
  cout << a->getID();
  cout << x->getStudent()->getID();
  cout << y->getStudent()->getID();
  cout << x->getNext()->getStudent()->getID();
  return 0;
}
