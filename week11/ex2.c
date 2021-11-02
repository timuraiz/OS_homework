#include <dirent.h> 
#include <stdio.h> 

int main(void) {
  FILE *file = fopen("ex2.txt", "w");
  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      fprintf(file, "%s\n", dir->d_name);
    }
    closedir(d);
  }
  fclose(file);
  return(0);
}
