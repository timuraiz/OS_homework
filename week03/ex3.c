#include <stdio.h>
#include <stdlib.h>


void bubble(int* mass, int N){

    int tmp;
    int noSwap;

    for (int i = N - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                tmp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }
    
}
void show(int* a, int n){

    for (int i = 0; i < n;++i){
        printf("%d ",a[i]);
    }
}
int main(){
    int a[] = {4,2,41,7};
    bubble(a,4);
    show(a,4);
}