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

void Zebra::printInfo(){
  cout << "Zebra, Name: " << name << ", Age: " << age << ", Number of stripes: " << numStripes << endl;
}

Cat::Cat(string _name, int _age, string _favoriteToy){
  name = _name;
  age = _age;
  favoriteToy = _favoriteToy;
}

void Cat::printInfo(){
  cout << "Cat, Name: " << name << ", Age: " << age << ", Favorite toy: " << favoriteToy << endl;
}
