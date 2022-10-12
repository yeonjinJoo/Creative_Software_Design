#include <iostream>
#include "shape.h"

Shape::Shape(double _width, double _height){
  width = _width;
  height = _height;
}

Triangle::Triangle(double _width, double _height){
  width = _width;
  height = _height;
}

double Triangle::getArea(){
  return width * height / 2;
}

Rectangle::Rectangle(double _width, double _height){
  width = _width;
  height = _height;
}

double Rectangle::getArea(){
  return width * height;
}
