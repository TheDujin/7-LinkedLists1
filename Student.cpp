#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(int newID) {
  ID = newID;
}

int Student::getID() {
  return ID;
}

Student::~Student() {

}
