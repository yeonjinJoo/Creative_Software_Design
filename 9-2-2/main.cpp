#include <iostream>
#include <string>
#include <set>
#include "setfunc.h"
using namespace std;

int main(void){
  string line;

  while(1){
    getline(cin, line);
    if(line.compare("0") == 0){
      break;
    }
    size_t pos = GetOperator(line);
    set<int> set0 = parseSet(line.substr(0, pos -1));
    set<int> set1 = parseSet(line.substr(pos+2));
    char oper = line[pos];
    if(oper == '+'){
      printSet(getUnion(set0, set1));
    }
    else if(oper == '-'){
      printSet(getDifference(set0, set1));
    }
    else if(oper == '*'){
      printSet(getIntersection(set0, set1));
    }
  }
  return 0;
}