#include <iostream>
#include "my_string.h"
#include <string>
using namespace std;

MyString& MyString::operator=(const string& str){
  this->str = str;
  return *this;
}

MyString& MyString::operator=(const MyString& b){
  str = b.str;
  return *this;
}

MyString MyString::operator+(const MyString& b){
  MyString c;
  c.str = str + b.str;
  return c;
}

MyString MyString::operator*(const int b){
  string sum = "";
  for(int i = 0; i < b; i++){
    sum += str;
  }
  MyString c;
  c.str = sum;
  return c;
}

ostream& operator<<(ostream& out, MyString& my_string){
  out << my_string.str << endl;
  return out;
}

istream& operator>>(istream& in, MyString& my_string){
  in >> my_string.str;
  return in;
}