#include <stdio.h>

void rotateLeft(int* pa, int* pb, int* pc){
	int temp = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = temp;
}

void rotateRight(int* pa, int* pb, int* pc){
	int temp = *pa;
	*pa = *pc;
	*pc = *pb;
	*pb = temp;
}

int main(void){
	int a = 10;
	int b = 20; 
	int c = 30;

	while(1){
		printf("%d:%d:%d\n", a,b,c);
		char dir;
		scanf(" %c", &dir);

		if(dir == 'L'){
			rotateLeft(&a, &b, &c);
		}
		else if(dir == 'R'){
			rotateRight(&a, &b, &c);
		}
		else if(dir == 'E'){
			break;
		}
		else{
			printf("Error: Wrong input!\n");
			break;
		}
	}
	return 0;
}
