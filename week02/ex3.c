#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
int main(){

	int n;


	printf("Write the height of tree - ");

	scanf("%d",&n);

	for (int i = 1; i <= n;++i){

		int space  = 2*(n) - 1 - i + 1/2;
		

		for (int j = 0; j < space; ++j){
			printf(" ");
		}

		for (int j = 0; j <2*i - 1;++j){
			
			printf("*");
		}
		printf("\n");
	}


}