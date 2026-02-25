#include <stdio.h>
#include "tester.h"
int main(){
    init();
    FILE *fa = fopen("file_a.txt", "r");
    FILE *fb = fopen("file_b.txt", "r");
    int idA, pisangA, idB, pisangB;
    fscanf(fa, "%d %d", &idA, &pisangA);
    fscanf(fb, "%d %d",&idB, &pisangB);
    while(idA != -1 && idB != -1){
        if(idA < idB){
            printf("%d %d\n", idA, pisangA);
            fscanf(fa, "%d %d", &idA, &pisangA);
        }
        else{
            printf("%d %d\n", idB, pisangB);
            fscanf(fb, "%d %d", &idB, &pisangB);
        }
    }
    if(idA == -1){
        while(idB != -1){
            printf("%d %d\n", idB, pisangB);
            fscanf(fb, "%d %d", &idB, &pisangB);
        }
        
    }
    else if(idB == -1){
        while(idA != -1){
            printf("%d %d\n", idA, pisangA);
            fscanf(fa, "%d %d", &idA, &pisangA);
        }
    }
    return 0;
}