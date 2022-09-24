#include <cstring>
#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
  head = (Person*)malloc(sizeof(Person));
  head -> next = NULL;
}
void LinkedList::printPerson(){
  Person* p = head;
  while(p -> next != NULL){
    p = p -> next;
    cout << "Name:" << p -> name << ", Age:" << p->age << endl;
  }
}
void LinkedList::addPerson(char* name, int age){
  Person* new_person = (Person*)malloc(sizeof(Person));
  strcpy(new_person -> name, name);
  new_person -> age = age;
  new_person -> next = NULL;

  Person* tail = head;
  while(tail -> next != NULL){
    tail = tail -> next;
  }
  tail -> next = new_person;
}
