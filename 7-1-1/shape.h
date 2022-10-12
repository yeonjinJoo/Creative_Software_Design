#include <iostream>

class Shape{
  public: 
    Shape(){};
    Shape(double _width, double _height);
    virtual double getArea() = 0;
    virtual ~Shape(){};

  protected:
    double width, height;
};

class Triangle : public Shape{
  public: 
    Triangle(double _width, double _height);
    virtual double getArea();
};

class Rectangle : public Shape{
  public:
    Rectangle(double _width, double _height);
    virtual double getArea();
};