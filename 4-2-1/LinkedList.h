class Person{
public:
  char name[10];
  int age;
  Person *next;
};

class LinkedList{
private:
  Person* head;
public:
  LinkedList();
  void addPerson(char* name, int age);
  void printPerson();
};
