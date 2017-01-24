#ifndef TEMP
#define TEMP


#include <iostream>

using namespace std;

class Student {
 public:
  Student(int newID, char* newFirstName, char* newLastName, float newGPA);
  int getID();
  char* getFirstName();
  char* getLastName();
  float getGPA();
  void print();
  ~Student();

 private:
  int ID;
  char* firstName;
  char* lastName;
  float GPA;
};
#endif
