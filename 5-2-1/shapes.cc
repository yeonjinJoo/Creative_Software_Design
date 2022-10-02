#include <iostream>
#include <cstring>
#include "shapes.h"
using namespace std;

void Canvas::Print() const{
  for(int i = 0; i < row+1; i++){
    for(int j = 0; j < col+1; j++){
      cout << canvas[i][j];
    }
    cout << "\n";
  }
}

void Canvas::Clear(){
  for(int i = 0; i < row+1; i++){
    free(canvas[i]);
  }
  free(canvas);
}

void Canvas::changeCanvas(int x, int y){
  canvas[y][x] = brush;
}

bool Canvas::DrawPixel(const int x, const int y){
  if(x >= 0 &&  x < col && y >= 0 &&  y < row){
    return true;
  }
  else{
    return false;
  }
}

Shape::Shape(){}

Shape::Shape(int x, int y, int width, Canvas*  can){
  this->x = x;
  this->y = y;
  this->width = width;
  this->can = can;
}

Square::Square(int x_, int y_, int width_, Canvas* can) : Shape(x_,y_,width_,can){}

double Square::GetArea(){
  return width*width;
}

int Square::GetPerimeter(){
  return 4*width;
}

void Square::Draw(int width){
  for(int i = y; i < y + width; i++){
    for(int j = x; j < x + width; j++){
      bool good = can -> DrawPixel(j, i);
      if(good){
        can -> changeCanvas(j+1, i+1);
      }
    }
  }
}

Rectangle::Rectangle(int x_, int y_, int width_, Canvas* can, int h_) : Shape(x_, y_, width_, can), h(h_){}

double Rectangle::GetArea(){
  return width*h;
}

int  Rectangle::GetPerimeter(){
  return 2*(width + h);
}

void Rectangle::Draw(int width, int height){
  for(int i = y; i < y + height; i++){
    for(int j = x; j < x + width; j++){
      bool good = can -> DrawPixel(j, i);
      if(good){
        can -> changeCanvas(j+1, i+1);
      }
    }
  }
}

Canvas::Canvas(const size_t row, const size_t col, char brush){
  //canvas 초기화 
  this->row = row;
  this->col = col;
  this->brush = brush;
  canvas = (char**)malloc((row+1)*sizeof(char*));
  for(int i = 0; i < row+1; i++){
    canvas[i] = (char*)malloc((col+1)*sizeof(char));
  }
  for(int i = 0; i < row+1; i++){
    for(int j = 0; j < col+1; j++){
      if(i == 0){
        if(j == 0){
          canvas[i][j] = ' ';
        }
        else{
          char cc = j -1 + '0';
          canvas[i][j] = cc;
        }
      }
      else{
        if(j == 0){
          char cc = i - 1 + '0';
          canvas[i][j] = cc;
        }
        else{
          canvas[i][j] = '.';
        }
      }
    }
  }
}