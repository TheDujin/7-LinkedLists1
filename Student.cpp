#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(int newID, char* newFirstName, char* newLastName, float newGPA) {
  ID = newID;
  firstName = newFirstName;
  lastName = newLastName;
  GPA = newGPA;
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

float Student::getGPA() {
  return GPA;
}

void Student::print() {
  cout << firstName << " " << lastName << ", ID: " << ID << ", GPA: " << GPA << endl;
}

Student::~Student() {
  delete[] firstName;
  delete[] lastName;
}
