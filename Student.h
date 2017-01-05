#ifndef TEMP
#define TEMP


#include <iostream>

using namespace std;

class Student {
 public:
  Student(int newID);
  int getID();
  ~Student();

 private:
  int ID;
};
#endif
