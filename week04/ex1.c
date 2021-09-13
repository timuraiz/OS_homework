#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(int argc, char const *argv[])

{
		int n = getppid();
		int x = fork();
		if (x == 0){
			printf("Hello from child: PID - %d \n",x);

		}
		else{
			printf("Hello from parent: PID - %d \n",n);
		}

		return EXIT_SUCCESS;
	
}