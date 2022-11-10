#include <iostream>
#include "my_string.h"
#include <string>
using namespace std;

int main(void){
  string type, a1, b1;
  cin >> type;
  if(type.compare("new") == 0){
    cout << "enter a" << endl;
    cin >> a1;
    cout << "enter b" << endl;
    cin >> b1;
  }
  MyString a,b; 
  a = a1;
  b = b1;
  string first; 
  char oper, second;
  
  cin >> first;
  while(first.compare("quit") != 0){
    cin >> oper;
    MyString result;
    if(oper == '*'){
      int num;
      cin >> num;
      if(first.compare("a") == 0){
        result = a * num;
      }
      else if(first.compare("b") == 0){
        result = b * num;
      }
      cout << result;
    }
    else if(oper == '+'){
      cin >> second;
      if(first.compare("a") == 0 && second == 'a'){
        result = a + a;
      }
      else if(first.compare("b") == 0 && second == 'b'){
        result = b + b;
      }
      else if(first.compare("a") == 0 && second == 'b'){
        result = a + b;
      }
      else if(first.compare("b") == 0 && second == 'a'){
        result = b + a;
      }
      cout << result;
    }
    cin >> first;
  }
  return 0;
}