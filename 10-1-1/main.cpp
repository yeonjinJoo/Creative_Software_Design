#include <iostream>
#include <vector>
#include <string>
#include "sorted.h"
using namespace std;

int main(void){
  string type;
  SortedArray sa;
  cin >> type;
  while(1){
    if(type.compare("add") == 0){
      cin.ignore();
      string nums;
      getline(cin, nums);
      auto n = nums.find(" ");
      while(n != string::npos){
        sa.AddNumber(stoi(nums.substr(0, n)));
        nums = nums.substr(n+1);
        n = nums.find(" ");
      }
      sa.AddNumber(stoi(nums));
    }
    else if(type.compare("ascend") == 0){
      vector<int> asc = sa.GetSortedAscending();
      for(auto i = asc.begin(); i != asc.end(); i++){
        cout << *i << " ";
      }
      cout << "\n";
    }
    else if(type.compare("descend") == 0){
      vector<int> desc = sa.GetSortedDescending();
      for(auto i = desc.begin(); i != desc.end(); i++){
        cout << *i << " ";
      }
      cout << "\n";
    }
    else if(type.compare("max") == 0){
      cout << sa.GetMax() << endl;
    }
    else if(type.compare("min") == 0){
      cout << sa.GetMin() << endl;
    }
    else if(type.compare("quit") == 0){
      break;
    }
    cin >> type;
  }
  return 0;
}