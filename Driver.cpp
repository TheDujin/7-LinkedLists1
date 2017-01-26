#include "Student.h"
#include "Node.h"
#include <iostream>
#include <strings.h>
#include <iomanip>

using namespace std;
//The Driver file contains all the necessary functions for running a database based off a Linked List.
void addStudent(Node* student, Node* newStudent);
void printOut(Node* student);
void deleteStudent(Node* student, int targetID);
void findAverage(Node* student, int numStudents, float sum);

int main() {
  //Define command keywords
  const char add[] = "ADD";
  const char print[] = "PRINT";
  const char del[] = "DELETE";
  const char quit[] = "QUIT";
  const char avg[] = "AVERAGE";

  char input[81];
  //Print welcome and set running = true
  cout << "Welcome to Linked Lists - Student List!" << endl;
  bool isRunning = true;
  //Make an empty Node that represents the head. This Node will always remain empty and at the head.
  Node* head = new Node(NULL);
  head->setNext(NULL);
  while (isRunning) {
    //Prompt for input
    cout << "Please use the commands ADD, PRINT, DELETE, QUIT, and AVERAGE (case insensitive)." << endl << "?: ";
    cin >> input;
    cin.ignore();
    //Run different functions depending on what the input is
    if (strcasecmp(add, input) == 0) {
      //Create new Student, put it in a Node, and pass this to addStudent function
      cout << "Adding..." << endl;
      char* firstName = new char[80];
      char* lastName = new char[80];
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
      //Prompt for target ID then pass it to deleteStudent
      cout << "Deleting..." << endl;
      int targetID;
      cout << "What is the ID of the student you would like to delete?" << endl << "ID: ";
      cin >> targetID;
      deleteStudent(head, targetID);
    }
    else if (strcasecmp(quit, input) == 0) {
      cout << "Quitting..." << endl;
      isRunning = false;
    }
    else if (strcasecmp(avg, input) == 0) {
      cout << "Calculating..." << endl;
      findAverage(head, 0, 0);
    }
    else
      cout << "That input is not valid. Please check your spelling and try again." << endl;
  }
  //When the while loop is exited, program is effectively over. Print farewell statement
  cout << "Thank you for using Linked Lists - Student List!" << endl;
  
  return 0;
}


//Adds a student to the Linked List in such a way that the Linked List remains sorted in ascending order by ID
void addStudent(Node* student, Node* newStudent) {
  //Set the next Node for the Node to be added to equal NULL
  newStudent->setNext(NULL);
  //If we are at the end of the List, obviously we must attach the Node to the end
  if (student->getNext() == NULL)
    student->setNext(newStudent);
  //Else, if the ID of the next Node (the one that the current Node we are looking at is attached to)
  //is greater than the new Node's ID, insert here
  else if (student->getNext()->getStudent()->getID() >= newStudent->getStudent()->getID()) {
    Node* temp = student->getNext();
    student->setNext(newStudent);
    newStudent->setNext(temp);
  }
  //Else, look at the next Node.
  else
    addStudent(student->getNext(), newStudent);
}

//For each Node that is not the empty head, print its Student
void printOut(Node* student) {
  if (student->getStudent() == NULL && student->getNext() != NULL)
    printOut(student->getNext());
  else if (student->getStudent() == NULL && student->getNext() == NULL) {
    cout << "There aren't any students to print. Maybe you should add some with the \"ADD\" command?" << endl;
    return;
  }
    
  else {
    student->getStudent()->print();
    if (student->getNext() != NULL)
      printOut(student->getNext());
  }
  return;
}

//Walks through the Linked List and deletes the first instance of a Node with that Student ID
void deleteStudent(Node* student, int targetID) {
  //If the only Node is head, print error statement
  if (student->getStudent() == NULL && student->getNext() == NULL) {
    cout << "There aren't any students to delete. Maybe you should \"ADD\" some first?" << endl;
    return;
  }
  //If we are at the end, we have not found the student. Guess they don't exist?
  else if (student->getNext() == NULL) {
    cout << "A student with that ID could not be found." << endl;
  }
  //If the next Node contains a matching ID, check whether that Node has a next Node
  else if (student->getNext()->getStudent()->getID() == targetID) {
    if (student->getNext()->getNext() == NULL) {
      //If not, delete next Node and set current Node's next to NULL
      delete (student->getNext());
      student->setNext(NULL);
      cout << "Student deleted successfully." << endl;
    }
    else {
      //If so, get next Node's next Node, delete the next Node, and set current Node to the next Node's next Node
      Node* temp = student->getNext()->getNext();
      delete (student->getNext());
      student->setNext(temp);
      cout << "Student deleted successfully." << endl;
    }
  }
  else {
    //Otherwise, check the next Node
    deleteStudent(student->getNext(), targetID);
  }
}

//Find average. Store the number of students counted and the total of their GPA's, and at the end divide GPA/students
void findAverage(Node* student, int numStudents, float sum) {
  //If we are not at the end, ++ numstudents and add to the GPA total
  if (student->getStudent() != NULL) {
    sum += student->getStudent()->getGPA();
    numStudents++;
  }
  //If we are at then end, return the total GPA divided by the number of students
  if (student->getNext() == NULL) {
    //If there was at least one student, divide as normal. Otherwise, return error message
    if (numStudents > 0)
      cout << "The average GPA is " << sum / numStudents << endl;
    else
      cout << "There aren't any students in the linked list. Maybe you should add some with the command \"ADD\"?" << endl;
  }
  //If the next Node is not NULL, recursively run findAverage with the new total student and total GPA
  else
    findAverage(student->getNext(), numStudents, sum);
}
