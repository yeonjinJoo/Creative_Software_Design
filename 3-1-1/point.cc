#include <stdio.h>

typedef struct{
  int xpos;
  int ypos;
}Point;

Point getScalePoint(Point* p, int s){
  Point changed;
  changed.xpos = p->xpos * s;
  changed.ypos = p->ypos * s;
  return changed;
}

void swapPoints(Point* p1, Point* p2){
  int x = p1 -> xpos;
  int y = p1 -> ypos;
  p1->xpos = p2->xpos;
  p1->ypos = p2->ypos;
  p2->xpos = x;
  p2->ypos = y;
}

int main(void) {
  Point p1, p2;
  int s1, s2;
  scanf("%d %d %d", &p1.xpos, &p1.ypos, &s1);
  scanf("%d %d %d", &p2.xpos, &p2.ypos, &s2);

  Point* pp1 = &p1;
  Point* pp2 = &p2;

  printf("Calling getScalePoint() for (%d, %d)\n", p1.xpos, p1.ypos);
  printf("Calling getScalePoint() for (%d, %d)\n", p2.xpos, p2.ypos);
  
  p1 = getScalePoint(pp1, s1);
  p2 = getScalePoint(pp2, s2);

  printf("Calling swapPoints()\n");
  
  swapPoints(pp1, pp2);

  printf("p1 : %d %d\np2 : %d %d\n", p1.xpos, p1.ypos, p2.xpos, p2.ypos);
  
  return 0;
}