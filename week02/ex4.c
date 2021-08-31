#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>


void swap(int* a, int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main(){

	int a,b;


	printf("Write two integers - ");
	scanf("%d %d",&a,&b);

	printf("a = %d, b = %d\n",a,b);	

	swap(&a,&b);

	printf("a = %d, b = %d",a,b);

	


}