#include <iostream>
#include <string>
#include <set>
#include "setfunc.h"
using namespace std;

set<int> parseSet(const string& str){
  set<int> s;
  string copy;
  copy = str.substr(2, str.size()-2);
  auto i = copy.find_first_of(" ");
  while(i != string::npos){
    s.insert(stoi(copy.substr(0, i)));
    copy = copy.substr(i+1);
    i = copy.find_first_of(" ");
  }
  return s;
}

void printSet(const set<int>& s){
  cout << "{ ";
  for(auto i = s.begin(); i != s.end(); i++){
    cout << *i << " ";
  }
  cout << "}" << endl;
}

set<int> getIntersection(const set<int>& set0, const set<int>& set1){
  set<int> intersect;
  for(auto i = set0.begin(); i != set0.end(); i++){
    for(auto j = set1.begin(); j != set1.end(); j++){
      if((*i) == (*j)){
        intersect.insert(*i);
      }
    }
  }
  return intersect;
}

set<int> getUnion(const set<int>& set0, const set<int>& set1){
  set<int> united(set0);
  for(auto j = set1.begin(); j != set1.end(); j++){
    united.insert(*j);
  }
  return united;
}

set<int> getDifference(const set<int>& set0, const set<int>& set1){
  set<int> diff(set0);
  for(auto i = set0.begin(); i != set0.end(); i++){
    for(auto j = set1.begin(); j != set1.end(); j++){
      if((*i) == (*j)){
        diff.erase(*i);
      }
    }
  }
  return diff;
}

size_t GetOperator(const string& str){
  auto op_pos = str.find_first_of("+");
  if(op_pos == string::npos){
    op_pos = str.find_first_of("*");
  }
  if(op_pos == string::npos){
    auto temp = str.find_first_of("-");
    while(temp != string::npos && str.at(temp + 1) != ' '){
      temp = str.find_first_of("-", temp + 1);
    }
    op_pos = temp;
  }
  return op_pos;
}