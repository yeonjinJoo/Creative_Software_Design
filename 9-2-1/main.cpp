#include <iostream>
#include <string>
#include "message.h"
using namespace std;

int main(void){
  string type, message;
  int number;
  MessageBook mb;
  
  while(1){
    cin >> type;
    if(type.compare("add") == 0){
      cin >> number;
      getline(cin, message);
      mb.AddMessage(number, message.substr(1));
    }
    else if(type.compare("delete") == 0){
      cin >> number;
      mb.DeleteMessage(number);
    }
    else if(type.compare("print") == 0){
      cin >> number;
      cout << mb.GetMessage(number) << endl;
    }
    else if(type.compare("list") == 0){
      mb.GetNumbers();
    }
    else if(type.compare("quit") == 0){
      break;
    }
  }
  return 0;
}