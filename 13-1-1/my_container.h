#ifndef __MY_CONTAINER_H__
#define __MY_CONTAINER_H__

#include <iostream>
using namespace std;

template <class T>
class MyContainer{
public:
  MyContainer(int size){
    obj_arr = new T[size];
    n_elements = size;
  }
  ~MyContainer(){
    this->clear();
  }
  void clear(){
    delete[] obj_arr;
  }
  int size(){
    return n_elements;
  }

  template <class U>
  friend istream& operator>> (istream &in, MyContainer<U> &b);
  template <class U>
  friend ostream& operator<<(ostream &out, MyContainer<U> &b);

protected:
  T* obj_arr = NULL;
  int n_elements;
};

template<class T>
istream& operator>> (istream &in, MyContainer<T> &b){
  for(int i = 0; i < b.n_elements; i++){
    in >> b.obj_arr[i];
  }
  return in;
}

template<class T>
ostream& operator<<(ostream &out, MyContainer<T> &b){
  for(int i = 0; i < b.n_elements; i++){
    out << b.obj_arr[i] << " ";
  }
  out << "\n";
  return out;
}

#endif //__MY_CONTAINER_H__