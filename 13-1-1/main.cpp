#include <iostream>
#include "my_container.h"
#include <string>
using namespace std;

int main(void){
  int num;
  cin >> num;
  MyContainer<int> a(num);
  cin >> a;
  cout << a;

  cin >> num;
  MyContainer<double> b(num);
  cin >> b;
  cout << b;

  cin >> num;
  MyContainer<string> c(num);
  cin >> c;
  cout << c;
  
  return 0;
}