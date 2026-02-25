#include <stdio.h>
#include "listdin.h"

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}

int main(){
    ListDin L, L2;
    CreateListDin(&L, 100001);
    CreateListDin(&L2, 100001);
    readList(&L);
    
    for(int i = 0; i < L.nEff - 1; i++){
        L2.buffer[i] = (L.buffer[i] - L.buffer[i + 1]);
        if(L2.buffer[i] < 0){
            L2.buffer[i] = L2.buffer[i] * (-1);
        }
        //printf("%d\n", L2.buffer[i]);
    }
    L2.nEff = L.nEff - 1;
    int k = gcd(L2.buffer[0], L2.buffer[1]);
    for(int i = 2; i < L2.nEff; i++){
        k = gcd(k, L2.buffer[i]);
    }
    printf("%d\n", k);
    dealocateList(&L);
}