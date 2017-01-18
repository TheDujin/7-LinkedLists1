//Josh Howell Node
//Nodes that organize themselves for a linked list that will be
//used for a student list

using namespace std;

class Student;

class Node{ 
 public:
  Node(Student* student);
  ~Node();
  Node* getNext(); //returns the next node 
  Student* getStudent(); //returns the student the node points to
  void setNext(Node* node); //sets the pointer to the next node
  void push_back(Student* student); //adds a new node to the end of the list that the current node is in
  Node* end(); 
  void wipe();
 protected:
    Student* data;
    Node* pointer;
};
      
