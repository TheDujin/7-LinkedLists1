#include "Student.h"
#include "Node.h"
#include <iostream>

using namespace std;

void addStudent(Node* student);
void printOut(Node* student);
void deleteStudent(Node* student);
void findAverage(Node* student);

int main() {
  //Student* a = new Student(5, "Bob", "Joe");
  //Student* b = new Student(49, "Bill", "Jones");
  //Node* x = new Node(a);
  //Node* y = new Node(b);
  //x->setNext(y);
  //cout << a->getID();
  //cout << x->getStudent()->getID();
  //cout << y->getStudent()->getID();
  //cout << x->getNext()->getStudent()->getID();
  const char[] add = "ADD";
  const char[] print = "PRINT";
  const char[] del = "DELETE";
  const char[] quit = "QUIT";
  const char[] avg = "AVERAGE";

  char input[81];
  
  cout << "Welcome to Linked Lists - Student List!" << endl;
  bool isRunning = true;
  Node* head = new Node(NULL);
  while (isRunning) {
    cout << "Please use the commands ADD, PRINT, DELETE, QUIT, and AVERAGE (case insensitive)." << endl << "?: ";
    cin >> input;
    cin.ignore();
    if (strcmpcase(add, input) == 0) {
      cout << "Adding..." << endl;
      addStudent(head);
    }
    if (strcmpcase(print, input) == 0) {
      cout << "Printing..." << endl;
      printOut(head);
    }
    if (strcmpcase(del, input) == 0) {
      cout << "Deleting..." << endl;
      deleteStudent(head);
    }
    if (strcmpcase(quit, input) == 0) {
      cout << "Quitting" << endl;
      isRunning = false;
    }
    if (strcmpcase(avg, input) == 0) {
      cout << "Calculating..." << endl;
      findAverage(head);
  }
  cout "Thank you for using Linked Lists - Student List!" << endl;


  return 0;
}
