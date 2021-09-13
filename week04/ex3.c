#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(int argc, char const *argv[]){		
	printf("How many commands do you want to call? - ");
	int n;
	scanf("%d",&n);
	while (n > 0){
		char a[100];
		scanf("%s",a);
		system(a);
		n--;
		
	}
	return 0;
	
}