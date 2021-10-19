#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int arr[m][2];
    for (int i = 0; i < m; ++i) {          //read from input
        scanf("%d", &arr[i][0]);
        scanf("%d", &arr[i][1]);
    }
    int clock = 0;                         //initializing virtual memory and array with r_bist
    int r_bist[n];
    int virtual_mem[n][2];
    for (int i = 0; i < n; ++i) {
        virtual_mem[i][0] = -1;
        virtual_mem[i][1] = 0;

        r_bist[i] = 0;
    }
    int hits = 0, miss = 0;               //initializing hits and miss variables
    for (int i = 0; i < m; ++i) {
        int page_id = arr[i][1];
        int page_clock = arr[i][0];
        bool isInserted = false;
        int took = -1;
        for (int j = 0; j < n; ++j) {    //firstly I made shift bits to the right in each page and at the beginning of each I put accordingly bit from r_bist array
            if (clock < page_clock) {
                virtual_mem[j][1] = (virtual_mem[j][1] >> 1) | (r_bist[j] << 7);
                r_bist[j] = 0;           // put there zero cause it was alredy used
            }
        }
        for (int j = 0; j < n; ++j) {    // findig place for page in vir_mem. If there are no places to stay, we should remove one of already existing pages.
            if (virtual_mem[j][0] == -1 || virtual_mem[j][0] == page_id) {
                if (virtual_mem[j][0] == -1) {
                    printf("%d\n", 0);
                    miss += 1;

                } else {
                    printf("%d\n", 1);
                    hits += 1;
                }
                virtual_mem[j][0] = page_id;
                isInserted = true;
                took = j;
                r_bist[j] = 1;
                break;
            }
        }
        long long int min_cnt = 99999999999999;          // firstly we need to find page with minimum counter or if pages have same counters we need compare their id in vim_mem and replace new page with the minimum id
        int min_frame_id = n + 1;
        int index = -1;
        for (int j = 0; j < n && !isInserted; ++j) {    //finding there
            if ((virtual_mem[j][1] < min_cnt) || (virtual_mem[j][1] == min_cnt && min_frame_id > virtual_mem[j][0])) {
                min_cnt = virtual_mem[j][1];
                min_frame_id = virtual_mem[j][0];
                index = j;
            }
        }
        if (!isInserted) {                              //inserting there
            virtual_mem[index][0] = page_id;
            virtual_mem[index][1] = 0;
            printf("%d\n", 0);
            isInserted = true;
            miss += 1;
            r_bist[index] = 1;
        }
        clock = page_clock;                             //reseting clock cycle
    }
    float res = hits / (float) miss;                    //getting hits/miss ratio
    printf("%f", res);

}





