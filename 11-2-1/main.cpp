#include <iostream>
#include <string>
#include "my_vector.h"
using namespace std;

MyVector add(string& i, string& j, MyVector& a, MyVector& b){
  MyVector first, second, result;
  first = (i == "a") ? a:b;
  second = (j == "a") ? a:b;
  result = first + second;
  return result;
}
MyVector minus_get(string& i, string& j, MyVector& a, MyVector& b){
  MyVector first, second, result;
  first = (i == "a") ? a:b;
  second = (j == "a") ? a:b;
  result = first - second;
  return result;
}

int main(void){
  string type;
  MyVector a, b;
  int length;
  cin >> type;
  if(type.compare("new")==0){
    cin >> length;
    a = MyVector(length);
    b = MyVector(length);
    cout << "enter a" << endl;
    cin >> a;
    cout << "enter b" << endl;
    cin >> b;
  }

  string i;
  cin >> i; 
  while(i.compare("quit")!=0){
    char oper;
    string j;
    MyVector result;
    cin >> oper >> j;
    if(oper == '+'){
      if((j=="a") || (j == "b")){
        result = add(i, j, a, b);
      }
      else{
        int k = stoi(j);
        result = (i == "a") ? (a + k) : (b + k);
      }
    }
    else if(oper == '-'){
      if((j=="a") || (j == "b")){
        result = minus_get(i, j, a, b);
      }
      else{
        int k = stoi(j);
        result = (i == "a") ? (a - k) : (b - k);
      }
    }
    cout << result << endl;
    cin >> i;
  }
  return 0;
}