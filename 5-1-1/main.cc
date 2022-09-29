#include <iostream>
#include "animal.h"
using namespace std;

int main(void){
  Zebra* zebras[10];
  string name;
  int age, numStripes;
  int i = 0;
  while(1){
    cin >> name;
    if(name == "0"){
      break;	    
    }
    cin >> age >> numStripes;   
    zebras[i] = new Zebra(name, age, numStripes);
    i++;
  }
  for(int j = 0; j < i; j++){
    zebras[j] -> printZebra();
  }
  
  return 0;
}
