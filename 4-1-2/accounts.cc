#include "accounts.h"
#include <iostream>

void Account::setInfo(int ID){
  ID_ = ID;
}
int Account::getID(){
  return ID_;
}
int Account::getBalance(){
  return balance_;
}
void Account::setBalance(int balance){
  balance_ = balance;
}

void AccountManager::save(Account a){
  arr[n] = a;
}
void AccountManager::increaseN(){
  n++;
}
int AccountManager::getN(){
  return n;
}
int AccountManager::deposit(int ID, int amount){
  for(int i = 0; i <  n; i++){
    if(i == ID){
      int after = arr[i].getBalance() + amount;
      if(after <= 1000000){
        arr[i].setBalance(after);
        return 1;
      }
    }
  }
  return 0;
}
int AccountManager::withdraw(int ID, int amount){
  for(int i = 0; i < n; i++){
    if(i == ID){
      int after = arr[i].getBalance() - amount;
      if(after >= 0){
        arr[i].setBalance(after);
        return 1;
      }
    }
  }
  return 0;
}
int AccountManager::transfer(int ID1, int ID2, int amount){
  int a = withdraw(ID1, amount);
  int b = deposit(ID2, amount);
  if(a == 1 && b == 1){
    return 1;
  }
  else if(a == 1 && b == 0){
    deposit(ID1, amount);
  }
  else if(a == 0 && b == 1){
    withdraw(ID2, amount);
  }
  return 0;
}
void AccountManager::check(int ID){
  for(int i = 0; i < n; i++){
    if(i == ID){
      std::cout << "Balance of user " << ID <<": " << arr[i].getBalance() << std::endl;
    }
  }
}
