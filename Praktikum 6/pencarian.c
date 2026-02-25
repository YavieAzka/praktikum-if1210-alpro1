#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listdin.h"
#include "Boolean.h"

int main(){
    int n; scanf("%d", &n);
    ListDin L, temp, sum, duration;
    CreateListDin(&sum, 100);
    CreateListDin(&temp, 100);
    CreateListDin(&L, 100);
    CreateListDin(&duration, 100);
    duration.nEff = 5;
    sum.nEff = 5;
    temp.nEff = 5;
    L.nEff = 5;
    for(int i = 0; i < 5; i++){
        sum.buffer[i] = 0;
        temp.buffer[i] = 0;
        duration.buffer[i] = 0;
    }
    //printList(j);
    

    for(int i = 0; i < n; i++){
        
        scanf("%d %d %d %d %d", &L.buffer[0], &L.buffer[1], &L.buffer[2], &L.buffer[3], &L.buffer[4], &L.buffer[5]);
        for(int i = 0; i < 5; i++){
            sum.buffer[i] = L.buffer[i] - temp.buffer[i];
        }
        if(i != 0){
            duration = plusMinusList(sum, duration, 1);
        }
        copyList(L, &temp);
        
        // printf("duration total: ");printList(duration);
        // printf("\n");
        // printf("temp: "); printList(temp);
        // printf("\n");
    
    }
    float min = 99999; int ans;
    for(int i = 0; i < 5; i++){
        float f;
        f = (float)duration.buffer[i]/n;
        if(f < min){
            ans = i;
            //printf("CHECKED!\n");
            min = f;
        }
        
    }
    if(ans == 0){
        printf("Kebin\n");
    }
    
    if(ans == 1){
        printf("Stewart\n");
    }
    
    if(ans == 2){
        printf("Pop\n");
    }
    
    if(ans == 3){
        printf("Luiy\n");
    }
    
    if(ans == 4){
        printf("Toto\n");
    }
    dealocateList(&sum);
    dealocateList(&temp);
    dealocateList(&L);
}
// gcc pencarian.c listdin.c -o pencarian