#include <iostream>
using namespace std;

class Animal{
  public:
    Animal(string _name, int _age);
    Animal();

  protected:
    string name;
    int age;
};

class Zebra : public Animal{
  public: 
    Zebra(string _name, int _age, int _numStripes);
    void printZebra();

  protected:
    int numStripes;
};
