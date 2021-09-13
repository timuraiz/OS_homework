#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
#include <string.h>



char* input(){

	int size = 15;

  char* writtenSymbols = (char*)malloc(sizeof(char) * size);
  fgets(writtenSymbols,size,stdin);
  writtenSymbols[strcspn(writtenSymbols, "\n")] = 0;
  return writtenSymbols;
}
bool compare(char* a, char* b){
	if (strcmp(a,b) == 0){
		return true;
	}
	else{
		return false;
	}

}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

   
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

   
    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
           
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        
        *(result + idx) = 0;
    }

    return result;
}



int main(int argc, char const *argv[]){		
	

	char* symb = input();
  char exitWord[] = "exit";

  char del = ' ';
  while (!compare(symb,exitWord)){
    char** command = str_split(symb, del);
    int id = fork();
    if (id == 0){
      execvp(command[0],command);
    } 
    free(symb);
    char* symb = input();

  }


	return 0;
	
}