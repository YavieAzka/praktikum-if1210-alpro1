#include <stdio.h>
#include "listkontigu.h"

int main(){
    ListKontigu L;
    CreateList(&L);
    readList(&L);
    int n = lastIdx(L);
    int count = 0;
    for(int i = 0; i <= n - 2; i++){
        for(int j = i + 1; j <= n - 1; j++){
            for(int k = j + 1; k <= n; k++){
                if(L.contents[i] < L.contents[k] && L.contents[k] < L.contents[j]){
                    count++;
                }
            }
        }
    }
    if(count > 0){
        printf("Nyalakan\n");
    }
    else{
        printf("Santai\n");
    }
}

// gcc TandaBahaya.c listkontigu.c -o tanda