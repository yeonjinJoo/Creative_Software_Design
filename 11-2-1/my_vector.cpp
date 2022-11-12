#include <iostream>
#include "my_vector.h"
using namespace std;

MyVector::MyVector(){
  length = 0;
  a = NULL;
}
MyVector::~MyVector(){
  delete[] a;
}

MyVector::MyVector(int length){
   this->length = length;
   a = new double[length];
}

MyVector& MyVector::operator=(const MyVector& b){
  delete[] a;
  length = b.length;
  a = new double[length];
  for(int i = 0; i < b.length; i++){
    a[i] = b.a[i];
  }
  return *this;
}
MyVector MyVector::operator+(const MyVector& b){
  MyVector newVec(length);
  for(int i = 0; i < length; i++){
    newVec.a[i] = a[i] + b.a[i];
  }
  return newVec;
}
MyVector MyVector::operator-(const MyVector& b){
  MyVector newVec(length);
  for(int i = 0; i < length; i++){
    newVec.a[i] = a[i] - b.a[i];
  }
  return newVec;
}
MyVector MyVector::operator+(const int b){
  MyVector newVec(length);
  for(int i = 0; i < length; i++){
    newVec.a[i] = a[i] + b;
  }
  return newVec;
}
MyVector MyVector::operator-(const int b){
  MyVector newVec(length);
  for(int i = 0; i < length; i++){
    newVec.a[i] = a[i] - b;
  }
  return newVec;
}
ostream& operator<<(std::ostream& out, MyVector& b){
  for(int i = 0; i < b.length; i++){
    out << b.a[i] << " ";
  }
  return out;
}
istream& operator>>(std::istream& in, MyVector& b){
  for(int i = 0; i < b.length; i++){
    cin >> b.a[i];
  }
  return in;
}