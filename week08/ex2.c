#include <unistd.h>  // for sleep()
#include <stdlib.h>  // for malloc()
#include <string.h>  // for memset()

int main() {
  int size = 10 * 1024 * 1024;    // 10 MB size

  for (int i = 0; i < 10; i++) {
    void* ptr = malloc(size);     // allocating 10 MB memory
    memset(ptr, 0, size);         // filling it with '0'
    sleep(1);                     // sleep for 1 sec at each iteration
  }

  return 0;
}