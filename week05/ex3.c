#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int timer_for_sleep=0;
typedef  struct{
  int* arra;
  int size;
}array;
void *adding(void *args){
  while(1){
    if (timer_for_sleep % 2 == 0){
    array* arr = (array*)args;
    int size = arr->size;
    int* temp_arr = arr->arra;
    for (int i = 0; i <size; ++i){
      temp_arr[i%size] = i%1000;
      printf("\nAdding element %d\n",i%1000);

    }
   
  }
   else{
      printf("\nAdding element is sleeping\n");
    }
    
    timer_for_sleep++;

  
  
}
  
    return NULL;
}
void *erase(void *args){

  while (1){
   if (timer_for_sleep % 2 != 0){
    
    array* arr = (array*)args;
    int size = arr->size;
    int* temp_arr = arr->arra;
    for (int i = 0; i <size; ++i){
      temp_arr[i%size] = 0;
      printf("\nRemoving element by index %d\n",i%size);

    }
  
  else{
      printf("\nErasing element is sleeping\n");
    }

  timer_for_sleep++;

else{
      printf("\nErasing element is sleeping\n");
    }
timer_for_sleep++;
}
  

    return NULL;
}

int main(){
    pthread_t th_1, th_2;
    int size = 30;
    int* mass = malloc(size);
    array* temp_arr;
    temp_arr->arra = mass;
    temp_arr->size = size;
    pthread_create(&th_1, NULL, adding, temp_arr);
    pthread_create(&th_2, NULL, erase, temp_arr);
    
    
    pthread_join(th_1, NULL);
    pthread_join(th_2, NULL);


   
    
    return 0;
}