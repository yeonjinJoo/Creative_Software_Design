#include <iostream>
#include <vector>
#include <algorithm>
#include "intset.h"
using namespace std;

int main(void){
  IntegerSet s;
  string type;
  int num;

  while(1){
    cin >> type;
    vector<int> n = s.GetAll();
    if(type.compare("add")==0){
      cin >> num;
      if(find(n.begin(), n.end(), num) == n.end()){
        s.AddNumber(num);
      }
      s.PrintAll();
    }
    else if(type.compare("del") == 0){
      cin >> num;
      if(find(n.begin(), n.end(), num) != n.end()){
        s.DeleteNumber(num);
      }
      s.PrintAll();
    }
    else if(type.compare("get") == 0){
      cin >> num;
      if(num < 0 || num >= n.size()){
        cout << -1 << endl;
      }
      else{
        cout << s.GetItem(num) << endl;
      }
    }
    else if(type.compare("quit") == 0){
      break;
    }
  }
  
  return 0;
}