#ifndef TEMP
#define TEMP


#include <iostream>

using namespace std;

class Student {
 public:
  Student(int newID, char* newFirstName, char* newLastName);
  int getID();
  char* getFirstName();
  char* getLastName();
  ~Student();

 private:
  int ID;
  char* firstName;
  char* lastName;
};
#endif
