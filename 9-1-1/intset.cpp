#include <iostream>
#include "intset.h"
#include <vector>
#include <algorithm>
using namespace std;

IntegerSet::IntegerSet(){
  
}

void IntegerSet::AddNumber(int num){
  numbers_.push_back(num);
}

void IntegerSet::DeleteNumber(int num){
  numbers_.erase(remove(numbers_.begin(), numbers_.end(), num), numbers_.end());
}

int IntegerSet::GetItem(int pos){
  return numbers_[pos];
}

void IntegerSet::PrintAll(){
  for(int i = 0; i <numbers_.size(); i++){
    cout << numbers_[i] << " ";
  }
  cout << "\n";
}

std::vector<int> IntegerSet::GetAll(){
  return numbers_;
}