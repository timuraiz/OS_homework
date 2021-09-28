#include <stdio.h>
#include <stdlib.h>

void show(int* arrival,int* burst, int* wait_t,int* tat, int* ct,int size){

    int** array = (int**)malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++)
        array[i] = (int*)malloc(sizeof(int*) * 5);
    for (int j = 0; j < 5;++j ){
        for(int i = 0; i < size;++i){
            if (j == 0) {
                array[i][j] = arrival[i];
            }
            if(j == 1){
                array[i][j] = burst[i];
            }
            if(j == 2){
                array[i][j] = wait_t[i];
            }
            if(j == 3){
                array[i][j] = tat[i];
            }
            if (j == 4){
                array[i][j] = ct[i];
            }
        }
    }
    printf("\tAR\tBT\tWT\tTAT\tCT\n");
    for(int i = 0; i < size; ++i ){
        printf("P#%d\t",i+1);
        for(int j = 0; j < 5; ++j){
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    double avg_tat = 0;
    for (int i = 0; i < size; ++i){
        avg_tat+=tat[i];
    }
    avg_tat/=size;
    double avg_wt = 0;
    for(int i = 0; i < size; ++i){
        avg_wt+=wait_t[i];
    }
    avg_wt/=size;
    printf("Average Turnaround time: %f\n", avg_tat);
    printf("Average waiting time: %f\n", avg_wt);




}

void bubble_sort(int* a,int size,int* b){
    for (int i = 0; i < size; ++i ){
        for(int j = 0; j < size-1;++j){
            if (a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }

}

int* wating_time(int* arrival, int* burst, int size){
    int prev_burst = 0;
    int* wt = malloc(sizeof(int));
    for (int i = 0; i < size;++i){
        if (i == 0){
            wt[i] = 0;

        }
        else{
            wt[i] = arrival[0] + prev_burst - arrival[i];
        }
        prev_burst+=burst[i];
    }
    return wt;

}

int* tat(int* wt, int* brust, int size){
    int* tat = malloc(sizeof(int));
    for (int i = 0; i < size; ++i){
        tat[i] = wt[i] + brust[i];
    }
    return tat;
}

int* ct(int* tat, int* arrival, int size){
    int* ct  = malloc(sizeof(int));
    for (int i = 0; i < size; ++i){
        ct[i] = tat[i] + arrival[i];
    }
    return ct;
}

void sjb(int* a, int* b,int size){

    for (int i = 0; i < size; ++i ){
        for(int j = 0; j < size-1;++j){
            if (a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
            else{
                if  ((a[j] == a[j+1]) && (b[j] > b[j+1])){
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    temp = b[j];
                    b[j] = b[j+1];
                    b[j+1] = temp;
                }
            }
        }
    }


    int common_bt = b[0];

    for (int i = 1; i < size - 1; ++i){
        if (b[i] <= b[i + 1]){
            common_bt+=b[i];
        }
        else{
            if (a[i + 1] <= common_bt){
                int temp = a[i + 1];
                a[i+1] = a[i];
                a[i] = temp;
                temp = b[i + 1];
                b[i+1] = b[i];
                b[i] = temp;
                common_bt+=b[i];
            }
        }
    }
}

void roundr(int* arrival, int* burst,int* wt,int quantum,int size){
    int* rem_bt = malloc(sizeof (int));
    for(int i = 0; i < size;++i){
        rem_bt[i] = burst[i];
    }
    int T = arrival[0];
    int undone = 1;
    while (undone){
        undone = 0;
        for (int i = 0; i < size; ++i){
            if (rem_bt[i] > quantum){
                T+=quantum;
                rem_bt[i]-=quantum;
                undone = 1;
            }
            else{
                T+=rem_bt[i];
                wt[i] = T - burst[i] - arrival[i];
                rem_bt[i] = 0;
            }

        }
    }

}


int main()
{
  
    int size;
    printf("Type the number of processes: ");
    scanf("%d",&size);
   
    int* burst_times = malloc(sizeof(int));
    int* arrival_times = malloc(sizeof(int));

    for (int i = 0; i < size; ++i){
        scanf("%d",&arrival_times[i]);
        scanf("%d",&burst_times[i]);
    }



   bubble_sort(arrival_times,size,burst_times);
   int* wait_t = malloc(sizeof (int));
   int quantum = 3;
   roundr(arrival_times,burst_times,wait_t,quantum,size);
   int* tat_arr = tat(wait_t, burst_times, size);
   int* ct_arr = ct(tat_arr,arrival_times,size);
   show(arrival_times,burst_times,wait_t,tat_arr,ct_arr,size);





}
