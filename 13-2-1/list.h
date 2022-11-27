#include <iostream>
using namespace std;

template <class T>
class Node{
public:
  T data;
  Node<T>* next;
};

template <class T>
class List{
private:
  Node<T> *head;

public:
  List(): head(NULL){};
  ~List(){delete head;};
  List(T* arr, int n_nodes){
    head = new Node<T>();
    head -> data = arr[0];
    head -> next = NULL;

    Node<T>* tail = head;
    for(int i = 1; i < n_nodes; i++){
      Node<T>* new_node = new Node<T>();
      new_node -> data = arr[i];
      new_node -> next = NULL;
      
      tail -> next = new_node;
      tail = tail -> next;
    }
  }

  void insert_at(int idx, const T& data){
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;
    
    Node<T>* tail = head;
    for(int i = 0; i < idx -1; i++){
      tail = tail -> next;
    }
    
    new_node -> next = tail -> next;
    tail -> next = new_node;
    
  }
  void remove_at(int idx){
    Node<T>* tail = head;
    for(int i = 0; i < idx -1; i++){
      tail = tail -> next;
    }
    Node<T>* data = tail -> next;
    
    tail -> next = data -> next;
    delete data;
  }
  void pop_back(){
    Node<T>* tail = head;
    while(tail -> next -> next !=NULL){
      tail = tail -> next;
    }
    Node<T>* data = tail -> next;
    tail -> next = NULL;
    delete data;
  }
  void push_back(const T& data){
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;
    new_node -> next = NULL;
    
    Node<T>* tail = head;
    while(tail -> next != NULL){
      tail = tail -> next;
    }
    tail -> next = new_node;
  }

  void pop_front(){
    Node<T>* tail = head;
    tail = tail -> next;
    
    Node<T>* data = head;

    head = tail;
    delete data;
  }

  void push_front(const T& data){
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;
    new_node -> next = head;
    head = new_node;
  }

  template <class U>
  friend ostream& operator<<(ostream& out, List<U>& rhs){
    Node<U>* tail = rhs.head;
    while(tail -> next != NULL){
      out << tail -> data << ",";
      tail = tail -> next;
    }
    out << tail->data;
    return out;
  }
};