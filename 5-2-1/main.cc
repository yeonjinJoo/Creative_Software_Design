#include <iostream>
#include "shapes.h"
using namespace std;

int main(void){
  int canvas_width, canvas_height, x, y, width;
  char brush;
  cin >> canvas_width >> canvas_height;
  string s;
  cin >> s;
  while(1){
    if(s.compare("rect")==0){
      int height;
      cin >> x >> y >> width >> height >> brush;
      Canvas* c = new Canvas(canvas_width, canvas_height, brush);
      Rectangle* r = new Rectangle(x, y, width, c, height);
      cout << "Area: " << r->GetArea() << endl;
      cout << "Perimeter: " << r->GetPerimeter() << endl;
      
      r->Draw(width, height);
      c->Print();

      c -> Clear();
      delete c, r;
    }
    else if(s.compare("square")==0){
      cin >> x >> y >> width >> brush;
      Canvas* c = new Canvas(canvas_width, canvas_height, brush);
      Square* sq = new Square(x, y, width, c);
      cout << "Area: " << sq->GetArea() << endl;
      cout << "Perimeter: " << sq->GetPerimeter() << endl;

      sq->Draw(width);
      c->Print();

      c -> Clear();
      delete c, sq;
    }
    else if(s.compare("quit")==0){
      break;
    }
    cin >> s;
  }

  return 0;
}
