#include "shapes.h"

void Circle::setInfo(int x, int y, int r){
  x_ = x;
  y_ = y;
  r_ = r;
}

double Circle::Area(){
  return 3.14 * r_ * r_;
}
double Circle::Perimeter(){
  return 2 * 3.14 * r_;
}

void Rectangle::setInfo(int x_left, int y_left, int x_right, int y_right)
{
  x_left_ = x_left;
  y_left_ = y_left;
  x_right_ = x_right;
  y_right_ = y_right;
}

double Rectangle::Area(){
  return (x_right_ - x_left_)*(y_left_ - y_right_);
}
double Rectangle::Perimeter(){
  return 2*(x_right_ - x_left_) + 2*(y_left_ - y_right_);
}
