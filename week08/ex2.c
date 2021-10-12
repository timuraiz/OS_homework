#include <unistd.h>  
#include <stdlib.h>  
#include <string.h>  

int main() {
  int size = 10 * 1024 * 1024;    

  for (int i = 0; i < 10; i++) {
    void* ptr = malloc(size);     
    memset(ptr, 0, size);         
    sleep(1);                     
  }

  return 0;
}