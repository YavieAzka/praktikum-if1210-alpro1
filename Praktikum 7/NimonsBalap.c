#include <stdio.h>
#include "listkontigu.h"
#include <stdbool.h>

int main(){
    ListKontigu L;

    readList(&L);
    int n = lastIdx(L);
    //scanf("%d", &n);
    int k; scanf("%d", &k);
    ListKontigu hasil;
    CreateList(&hasil);
    int id = 0;

    for(int i = 0; i <= n - k + 1; i++){
        int max = -1; 
        for(int j = i; j < i + k; j++){
            if(L.contents[j] > max){
                max = L.contents[j];
            }   
        }

        boolean maxgetin = true;
        hasil.contents[id] = max;
        id++;
        
        //printf("#%d\n", id);
    }
    
    printf("[");
    for(int i = 0; i < listLength(hasil); i++){
        if(i == 0){
            printf("%d", hasil.contents[i]);
        }
        else{
            printf(",%d", hasil.contents[i]);
        }
    }
    printf("]\n");
    
}
// gcc NimonsBalap.c listkontigu.c -o balap