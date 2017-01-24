#include "Student.h"
#include "Node.h"
#include <iostream>
#include <strings.h>
#include <iomanip>

using namespace std;

void addStudent(Node* student, Node* newStudent);
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
  const char add[] = "ADD";
  const char print[] = "PRINT";
  const char del[] = "DELETE";
  const char quit[] = "QUIT";
  const char avg[] = "AVERAGE";

  char input[81];
  
  cout << "Welcome to Linked Lists - Student List!" << endl;
  bool isRunning = true;
  Node* head = new Node(NULL);
  head->setNext(NULL);
  while (isRunning) {
    cout << "Please use the commands ADD, PRINT, DELETE, QUIT, and AVERAGE (case insensitive)." << endl << "?: ";
    cin >> input;
    cin.ignore();
    if (strcasecmp(add, input) == 0) {
      cout << "Adding..." << endl;
      char firstName[80], lastName[80];
      int ID;
      float GPA;
      cout << "Please enter the first name of the student." << endl << "First name: ";
      cin >> firstName;
      cout << "Please enter the last name of the student." << endl << "Last name: ";
      cin >> lastName;
      cout << "Please enter the student ID." << endl << "Student ID: ";
      cin >> ID;
      cout << "Please enter the student\'s GPA (between 0 and 10, exclusive)." << endl << "Student\'s GPA: ";
      cin >> GPA;
      cin.ignore();
      cout << setprecision(2) << fixed << endl;
      
      addStudent(head, new Node(new Student(ID, firstName, lastName, GPA)));
    }
    else if (strcasecmp(print, input) == 0) {
      cout << "Printing..." << endl;
      printOut(head);
    }
    else if (strcasecmp(del, input) == 0) {
      cout << "Deleting..." << endl;
      deleteStudent(head);
    }
    else if (strcasecmp(quit, input) == 0) {
      cout << "Quitting" << endl;
      isRunning = false;
    }
    else if (strcasecmp(avg, input) == 0) {
      cout << "Calculating..." << endl;
      findAverage(head);
    }
    else
      cout << "That input is not valid. Please check your spelling and try again." << endl;
  }
  cout << "Thank you for using Linked Lists - Student List!" << endl;
  
  return 0;
}



void addStudent(Node* student, Node* newStudent) {
  newStudent->setNext(NULL);
  if (student->getStudent() == NULL) {
    if (student->getNext() == NULL) {
      student->setNext(newStudent);
      return;
    }
    else if (student->getNext()->getStudent()->getID() >= newStudent->getStudent()->getID()) {
      Node* temp = student->getNext();
      newStudent->setNext(temp);
      student->setNext(newStudent);
    }
    else {
      addStudent(student->getNext(), newStudent);
    }
  }
  else {
    if (student->getNext() == NULL) {
      student->setNext(newStudent);
      return;
    }
    else if (student->getStudent()->getID() <= newStudent->getStudent()->getID()
	     && student->getNext()->getStudent()->getID() >= newStudent->getStudent()->getID()) {
      Node* temp = student->getNext();
      newStudent->setNext(temp);
      student->setNext(newStudent);
      return;
    }
    else {
      addStudent(student->getNext(), newStudent);
    }
  }
}


void printOut(Node* student) {
  if (student->getStudent() == NULL && student->getNext() != NULL)
    printOut(student->getNext());
  else if (student->getStudent() == NULL && student->getNext() == NULL)
    return;
  
  else {
    student->getStudent()->print();
    if (student->getNext() != NULL)
      printOut(student->getNext());
  }
  return;
}


void deleteStudent(Node* student) {
  return;
}


 void findAverage(Node* student) {
   return;
}
