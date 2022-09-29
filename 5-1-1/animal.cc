#include <iostream>
#include "animal.h"
using namespace std;

Animal::Animal(){}
Animal::Animal(string _name, int _age){
  name = _name;
  age = _age;
}

Zebra::Zebra(string _name, int _age, int _numStripes){
  name = _name;
  age = _age;
  numStripes = _numStripes;
}

void Zebra::printZebra(){
  cout << "Name: " << name << ", Age: " << age << ", Number of stripes: " << numStripes << endl;
}
