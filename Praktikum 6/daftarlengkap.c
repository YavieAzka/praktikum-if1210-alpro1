#include <stdio.h>
#include "Boolean.h"
#include "liststatik.h"

int main(){
    int n, m;
    ListStatik L1, L2, L3;
    CreateListStatik(&L1);
    CreateListStatik(&L2);
    CreateListStatik(&L3);
    scanf("%d", &n);
    if(n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d", &L1.contents[i]);
        }
        
    }
    scanf("%d", &m);
    if(m != 0){
        for(int i = 0; i < m; i++){
            scanf("%d", &L2.contents[i]);
        }
    }
    //printf("%d %d", n, m);
    if(n == 0){
        //printf("#");
        printList(L2);
        printf("\n");
        return 0;
    }
    if(m == 0){
        printList(L1);
        printf("\n");
        return 0;
    }
    else{
        int val;
        int i = 0;
        while(L1.contents[0] != MARK && L2.contents[0] != MARK){
            if(L1.contents[0] < L2.contents[0]){
                L3.contents[i] = L1.contents[0];
                deleteFirst(&L1, &val);
            }
            else{
                L3.contents[i] = L2.contents[0];
                deleteFirst(&L2, &val);
            }
            i++;
        }
        if(isEmpty(L1)){
            while(!(isEmpty(L2))){
                L3.contents[i] = L2.contents[0];
                deleteFirst(&L2, &val);
                i++;
            }
        }
        if(isEmpty(L2)){
            while(!(isEmpty(L1))){
                L3.contents[i] = L1.contents[0];
                deleteFirst(&L1, &val);
                i++;
            }
        }
        printList(L3);
        printf("\n");
    }
    
    
    return 0;
}