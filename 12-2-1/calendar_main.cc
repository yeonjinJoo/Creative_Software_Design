#include <iostream>
#include <string>
#include "calendar.h"
using namespace std;

int main(void){
  MyCalendar c;
  string type, plus;
  cin >> type;
  while(type != "quit"){
    if(type == "set"){
      cin >> c;
    }
    if(type == "next"){
      cin >> plus;
      if(plus == "day"){
        bool isGood = c.NextDay(1);
        if(!(isGood)){
          cout << "Invalid date" << endl;
        }
        cout << c << endl;
      }
      else{
        int n = stoi(plus);
        bool isGood = c.NextDay(n);
        if(!(isGood)){
          cout << "Invalid date" << endl;
        }
        cout << c << endl;
      }
    }
    cin >> type;
  }
  return 0;
}