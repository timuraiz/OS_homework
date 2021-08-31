#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){

	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;

	printf("MAX INT - %d\n",a);
	printf("MAX DOUBLE - %lf\n",b);
	printf("MAX FLOAT - %f\n",c);


}