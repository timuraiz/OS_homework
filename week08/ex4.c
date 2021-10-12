#include <unistd.h>  
#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>
#include <sys/resource.h> 

int main() {
  int size = 10 * 1024 * 1024;    // 10 MB size
  struct rusage usage;
  int RUSAGE_SELF;

  for (int i = 0; i < 10; i++) {
    void* ptr = malloc(size);             // allocating 10 MB memory
    memset(ptr, 0, size);                 // filling it with '0'

    getrusage(RUSAGE_SELF, &usage);       // retrieving information about memory usage
    printf("%ld KB\n", usage.ru_maxrss);  // printing 

    sleep(1);                             // sleep for 1 sec at each iteration
  }

  return 0;
}