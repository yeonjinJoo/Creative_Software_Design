#include <iostream>
using namespace std;

class Canvas{
  public:
    Canvas(const size_t row, const size_t col, char brush); 

    void changeCanvas(int x, int y);

    bool DrawPixel(const int x, const int y);
    void Print() const; 
    void Clear();

  private:
    size_t row, col;
    char brush;
    char ** canvas;
};

class Shape{
  public: 
    Shape();
    Shape(int x, int y, int width, Canvas* can);

    double GetArea(){return 0;};
    int GetPerimeter(){return 0;};
    void Draw(){};

  protected:
    int x, y, width, perimeter;
    double area;
    Canvas* can;
};

class Square : public Shape{
  public: 
    Square(int x_, int y_, int width_, Canvas* can);
    double GetArea();
    int GetPerimeter();
    void Draw(int width);
};

class Rectangle: public Shape{
  private:
    int h;

  public:
    Rectangle(int x_, int y_, int width_, Canvas* can, int h_);
    double GetArea();
    int GetPerimeter();
    void Draw(int width, int height);
};