#include <iostream>
#include "shape.h"
using namespace std;

int main(void){
  Shape* shapes[10];
  char type;
  int i = 0;
  double width, height;

  cin >> type;
  while(1){
    if(type == '0'){
      break;
    }
    cin >> width >> height;
    if(type == 'r'){
      shapes[i] = new Rectangle(width, height);
    }
    else if(type == 't'){
      shapes[i] = new Triangle(width, height);
    }
    i++;
    cin >> type;
  }

  for(int j = 0; j < i; j++){
    cout << shapes[j] -> getArea() << endl;
    delete shapes[j];
  }
}
