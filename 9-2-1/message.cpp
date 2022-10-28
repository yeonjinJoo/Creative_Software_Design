#include "message.h"
#include <vector>, <map>, <iostream>
using namespace std;

string e = "";

void MessageBook::AddMessage(int number, const string& message){
  if(messages_.find(number) != messages_.end()){
    messages_[number] = message;
  }
  else{
    messages_.insert({number, message});
  }
}

void MessageBook::DeleteMessage(int number){
  if(messages_.find(number) != messages_.end()){
    messages_.erase(number);
  }
}

void MessageBook::GetNumbers(){
  map<int, string>::iterator it;
  for(it = messages_.begin(); it != messages_.end(); it++){
    cout << it -> first << ": " << it -> second << endl;
  }
}

const string& MessageBook::GetMessage(int number){
  if(messages_.find(number) != messages_.end()){
    return messages_[number];
  }
  return e;
}