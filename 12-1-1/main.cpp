#include <iostream>
#include "my_clock.h"
using namespace std;

int main(void){
  MyClock mc;
  string type;
  int plus;
  char colon;
  cin >> type;
  while(type != "quit"){
    if(type == "set"){
      cin >> mc;
    }
    if(type == "tick"){
      cin >> plus;
      mc.Tick(plus);
      cout << mc << endl;
    }
    cin >> type;
  }
  return 0;
}