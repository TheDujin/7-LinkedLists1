#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(int newID, char* newFirstName, char* newLastName) {
  ID = newID;
  firstName = newFirstName;
  lastName = newLastName;
}

int Student::getID() {
  return ID;
}

char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}

Student::~Student() {
  delete[] firstName;
  delete[] lastName;
}
