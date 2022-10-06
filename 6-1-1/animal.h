#include <iostream>
using namespace std;

class Animal{
  public:
    Animal(string _name, int _age);
    Animal();
    virtual ~Animal(){};
    virtual void printInfo() = 0;

  protected:
    string name;
    int age;
};

class Zebra : public Animal{
  public: 
    Zebra(string _name, int _age, int _numStripes);
    virtual ~Zebra(){};
    virtual void printInfo();

  protected:
    int numStripes;
};

class Cat: public Animal{
  public:
    Cat(string _name, int _age, string _favoriteToy);
    virtual ~Cat(){};
    virtual void printInfo();

  protected:
    string favoriteToy;
};
