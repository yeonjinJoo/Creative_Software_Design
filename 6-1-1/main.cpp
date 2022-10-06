#include <iostream>
#include "animal.h"
using namespace std;

int main(void){
  Animal* animals[10];
  char type;
  string name, favoriteToy;
  int age, numStripes;
  int i = 0;
  while(1){
    cin >> type;
    if(type == '0'){
      break;	    
    }
    else if(type == 'z'){
      cin >> name >>age >> numStripes;
      animals[i] = new Zebra(name, age, numStripes);
    }
    else if(type == 'c'){
      cin >> name >> age >> favoriteToy;
      animals[i] = new Cat(name, age, favoriteToy);
    }
    i++;
  }
  for(int j = 0; j < i; j++){
    animals[j] -> printInfo();
    delete animals[j];
  }
  return 0;
}