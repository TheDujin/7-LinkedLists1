#include <iostream>
#include "Student.h"

using namespace std;
//The constructor. Creates a new Student given the name, ID, and GPA
Student::Student(int newID, char* newFirstName, char* newLastName, float newGPA) {
  ID = newID;
  firstName = newFirstName;
  lastName = newLastName;
  GPA = newGPA;
}
//Getters
int Student::getID() {
  return ID;
}

char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}

float Student::getGPA() {
  return GPA;
}
//Print out the name, ID, and GPA in an orderly fashion
void Student::print() {
  cout << firstName << " " << lastName << ", ID: " << ID << ", GPA: " << GPA << endl;
}
//Destructor. Simply destroys all pointers
Student::~Student() {
  delete [] firstName;
  delete [] lastName;
}
