#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
int main(){

	char s[100] ;


	printf("Write a string that you want to reverse -");
	scanf("%s",s);

	for (int i = strlen(s) - 1; i >= 0;--i){

		 printf("%c",s[i]);
	}


}