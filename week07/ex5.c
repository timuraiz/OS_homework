#include <stdio.h>
#include <stdlib.h> // in order to use malloc
int main () {
	char **s = malloc(1000 * sizeof(char)); // dynamically allocating memory to avoid segmetation fault
	char foo [] = " Hello World ";
	*s = foo;
	printf ( "s is %s\n" ,s); // there is also mistake but is leads to warning which have no relations with segmentation fault 
	s[0] = foo ;
	printf ( "s [0] is %s\n" ,s[0]) ;
	return (0);
}
