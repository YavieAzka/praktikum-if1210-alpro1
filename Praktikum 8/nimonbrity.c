#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"
int main(){
    int n;
    scanf("%d", &n);
    Matrix m;
    createMatrix(n, n ,&m);
    readMatrix(&m, n, n);

    int brt[101];
    for(int i = 0; i < 101; i++){
        brt[i] = 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && m.mem[i][j] == 1){
                brt[i]++;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     printf("@%d\n", brt[i]);
    // }
    bool famousAvail = false;
    int count = 0;
    for(int i = 0; i < n; i++){
        
        if(brt[i] == 0){
            //printf("#%d\n", i);
            bool famous = true;
            for(int j = 0; j < n; j++){
                if(m.mem[j][i] == 0){
                    famous = false;
                }
            }
            if(famous){
                famousAvail = true;
                printf("%d\n", i);
            }
        }
    }
    if(!famousAvail){
        printf("-1\n");
    }
}
// gcc nimonbrity.c matriks.c -o nimon