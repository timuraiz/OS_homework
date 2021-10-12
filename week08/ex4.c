#include <unistd.h>  
#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>
#include <sys/resource.h> 

int main() {
  int size = 10 * 1024 * 1024;    
  struct rusage usage;
  int RUSAGE_SELF;

  for (int i = 0; i < 10; i++) {
    void* ptr = malloc(size);             
    memset(ptr, 0, size);                 

    getrusage(RUSAGE_SELF, &usage);       
    printf("%ld KB\n", usage.ru_maxrss);  

    sleep(1);                            

  return 0;
}