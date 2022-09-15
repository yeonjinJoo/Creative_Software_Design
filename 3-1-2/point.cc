#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
  int xpos;
  int ypos;
}Point;

double distance(Point p1, Point p2){
  int x = p1.xpos - p2.xpos;
  int y = p1.ypos - p2.ypos;
  double distance = sqrt(x*x + y*y);
  return distance;
}

void getShortest(const Point* points, int n, Point* minP){
  double mind = distance(points[0], points[1]);
  minP[0] = points[0];
  minP[1] = points[1];
  
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
      double compare = distance(points[i], points[j]);
      if(compare < mind){
        mind = compare;
        minP[0] = points[i];
        minP[1] = points[j];
      }
    }
  }
}
void getLongest(const Point* points, int n, Point* maxP){
  int maxd = distance(points[0], points[1]);
  maxP[0] = points[0];
  maxP[1] = points[1];

  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
      double compare = distance(points[i], points[j]);
      if(compare > maxd){
        maxd = compare;
        maxP[0] = points[i];
        maxP[1] = points[j];
      }
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  Point* pp = (Point*)malloc(n*sizeof(Point));

  Point* minP = (Point*)malloc(2*sizeof(Point));
  Point* maxP = (Point*)malloc(2*sizeof(Point));
  
  for(int i = 0; i < n; i++){
    scanf("%d %d", &pp[i].xpos, &pp[i].ypos);
  }

  getShortest(pp, n, minP);
  getLongest(pp, n, maxP);

  printf("longest: (%d,%d) (%d,%d)\n", maxP[0].xpos, maxP[0].ypos, maxP[1].xpos, maxP[1].ypos);
  
  printf("shortest: (%d,%d) (%d,%d)\n", minP[0].xpos, minP[0].ypos, minP[1].xpos, minP[1].ypos);

  free(pp);
  free(minP);
  free(maxP);
  
  return 0;
}