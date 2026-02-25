#include <stdio.h>
#include "time.h"

int main(){
    int n;
    scanf("%d", &n);
    TIME maxTime, minTime;
    CreateTime(&maxTime, 0, 0, 0);
    CreateTime(&minTime, 0, 0, 0);
    maxTime.HH = 0; maxTime.MM = 0; maxTime.SS = 0;
    minTime.HH = 23; minTime.MM = 59; minTime.SS = 59;
    for(int i = 1; i <= n; i++){
        printf("[%d]\n", i);
        TIME T1, T2, temp;
        CreateTime(&T1, 0, 0, 0);
        CreateTime(&T1, 0, 0, 0);
        BacaTIME(&T1);
        BacaTIME(&T2);
        long d;
        if(TGT(T1, T2)){
            //printf("#ookawaikoto\n");
            temp = T1;
            T1 = T2;
            T2 = temp;
        }
        d = Durasi(T1, T2);
        if(TGT(T2, maxTime)){
            maxTime = T2;
        }
        if(TLT(T1, minTime)){
            minTime = T1;
        }
        printf("%ld\n", d);
    }
    TulisTIME(minTime);
    printf("\n");
    TulisTIME(maxTime);
    printf("\n");
}