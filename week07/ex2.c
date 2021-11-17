#include <stdlib.h>
#include <stdio.h>


int main(){

	int N; // size of array

	printf("Write the size of array: ");
	scanf("%d", &N);

	int* array = malloc(N * sizeof(int)); // memory allocating

	for (int i = 0; i < N;++i){   // initializing 
		array[i] = i;
	}
	printf("Array: ");
	for (int i = 0; i < N;++i){   // printing
		printf("%d ", array[i]);
	}
	free(array);
}