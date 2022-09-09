#include <stdio.h>

double cube(const double* pd){
	double x = *pd;
	x = x*x*x;
	return x;
}

int main(void){
	double num;
	scanf("%lf", &num);

	const double* pd = &num;
	double changed = cube(pd);

	printf("%lf\n", changed);

	return 0;
}
