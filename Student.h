#ifndef TEMP
#define TEMP


#include <iostream>

using namespace std;
//Declare all the getters and the print function.
class Student {
 public:
  Student(int newID, char* newFirstName, char* newLastName, float newGPA);
  int getID();
  char* getFirstName();
  char* getLastName();
  float getGPA();
  void print();
  ~Student();
  //The members of each Student, all private
 private:
  int ID;
  char* firstName;
  char* lastName;
  float GPA;
};
#endif
