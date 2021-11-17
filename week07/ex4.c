#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

void* my_realloc(void* ptr, int size , int old_size){

	void* new_arr = malloc(size);

	if  (ptr && size > 0){
		int new_size = MIN(size, old_size);
		memcpy(new_arr, ptr,new_size);
			
	}
	else{
		if (size == 0){
			free(new_arr);
		}
	}
	return new_arr;
}


int main(){

	int* ptr1 = malloc(5 * sizeof(int));
	for (int i = 0; i < 5; ++i){
		ptr1[i] = 2;
	} 

	int* ptr2 = my_realloc(ptr1, 0 * sizeof(int), 5 * sizeof(int));

	for (int i = 0; i < 10; ++i){
		printf("%d ", ptr2[i]);
	} 
}