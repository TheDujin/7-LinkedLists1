#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;


Node::Node(Student* newData) {
  data = newData;
  next = NULL;
}

Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return data;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}

Node::~Node() {
  delete data;
  next = NULL;
}
