#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define n 5						// number of processes
#define m 3						// number of resourses 


bool *createBoolVec(int size) {			
    bool *vec = malloc(size * sizeof(bool));
    for (int i = 0; i < size; ++i)
        vec[i] = false;
    return vec;
}


int main() {
    


    FILE *fp = fopen("input.txt", "r");		//BEGIN TO READ DATA

    int* existance = malloc(sizeof(m));
    for (int i = 0; i < m&&fp; ++i) {
        fscanf(fp, "%d", &existance[i]);
    }
    fscanf(fp, "/n");

    int *available = malloc(sizeof(m));
    for (int i = 0; i < m&&fp; ++i) {
        fscanf(fp, "%d", &available[i]);
    }

    bool *finish = createBoolVec(n);	// in order to keep track that which proccess has finished working
    fscanf(fp, "/n");

    int allocation[n][m];				
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fp,"%d", &allocation[i][j]);
        }
        fscanf(fp, "/n");
    }
    int requests[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fp,"%d", &requests[i][j]);
        }
        fscanf(fp, "/n");
    }														//END READ DATA


    for (int i = 0; i < n; ++i) {
        int sum_of_row = 0;
        for (int j = 0; j < m; ++j) {
            sum_of_row += requests[i][j];
        }
        if (sum_of_row == 0) {
            for (int j = 0; j < m; ++j) {
                if (available[j] + allocation[i][j] <= existance[j])
                    available[j] = available[j] + allocation[i][j];
            }
            finish[i] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (finish[i] == false) {
            int sum_of_row = 0;
            for (int j = 0; j < m; ++j) {
                sum_of_row += requests[i][j];
            }
            bool temp = true;
            for (int j = 0; j < m && temp; ++j) {
                if (requests[i][j] > available[j]) {
                    temp = false;
                }
            }
            if (temp) {
                for (int j = 0; j < m; ++j) {
                    if (available[j] + allocation[i][j] <= existance[j])
                        available[j] = available[j] + allocation[i][j];
                }
                finish[i] = true;
            }
        }
    }
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        if (finish[i] == false) {
        	ans = false;
            printf("%d ", i);				//Printing the indexes of proccess that are deadlocked
        }
    }
    if (ans)
    	printf("No Deadlock is detected");


}