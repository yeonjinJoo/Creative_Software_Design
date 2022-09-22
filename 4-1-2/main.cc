#include <iostream>
#include "accounts.h"

using namespace std;
int main(){
  AccountManager am;
  while(1){
    cout << "Job?" << endl;
    char c;
    int ID, balance;
    cin >> c;
    if(c == 'N'){
      int n = am.getN();
      if(n < 10){
        Account a; 
        a.setInfo(n);
        am.save(a);
        cout << "Success!\n";
        am.increaseN();
        am.check(n);
      }
      else{
        cout << "Failure!" << endl;
      }
    }
    else if(c == 'D'){
      cin >> ID >> balance;
      int isGood = am.deposit(ID, balance);
      if(isGood == 1){
        cout << "Success!\n";
        am.check(ID);
      }
      else{
        cout << "Failure!" << endl;
      }
    }
    else if(c == 'W'){
      cin >> ID >> balance;
      int isGood = am.withdraw(ID, balance);
      if(isGood == 1){
        cout << "Success!\n";
      }
      else{
        cout << "Failure!\n";
      }
      am.check(ID);
    }
    else if(c == 'T'){
      int ID1;
      cin >> ID >> ID1 >> balance;
      int isGood = am.transfer(ID, ID1, balance);
      if(isGood ==1 ){
        cout << "Success!\n";
      }
      else{
        cout << "Failure!\n";
      }
      if(ID < ID1){
          am.check(ID);
          am.check(ID1);
      }
      else{
        am.check(ID1);
        am.check(ID);
      }
    }
    else if(c == 'Q'){
      break;
    }
  }
  return 0;
}
