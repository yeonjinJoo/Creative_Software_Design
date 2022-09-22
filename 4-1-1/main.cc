#include <iostream>
#include "shapes.h"

using namespace std;
int main(){
  while(1){
    cout << "shape?" << endl;
    char c;
    cin >> c;
    if(c == 'C'){
      int x, y, radius;
      cin >> x >> y >> radius;
      Circle cir;
      cir.setInfo(x, y, radius);
      cout << "area: " << cir.Area() << ", perimeter: " << cir.Perimeter() << endl;
    }
    else if(c == 'R'){
      int x_left, y_left, x_right, y_right;
      cin >> x_left >> y_left >> x_right >> y_right;
      Rectangle rec;
      rec.setInfo(x_left, y_left, x_right, y_right);
      cout << "area: " << rec.Area() << ", perimeter: " << rec.Perimeter() <<endl;
    }
    else if(c == 'Q'){
      break;
    }
  }
}
