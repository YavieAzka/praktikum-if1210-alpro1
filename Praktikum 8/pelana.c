#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"


int main(){
    Matrix M;
    int col, row;
    scanf("%d %d", &row, &col);
    createMatrix(row, col, &M);
    readMatrix(&M, row, col);
    int count = 0;
    for(int i = 0; i < M.rowEff; i++){
        for(int j = 0; j < M.colEff; j++){
            int x = M.mem[i][j];
            bool pelana = true;
            // kolom
            for(int k = 0; k < M.colEff; k++){
                if(x > M.mem[i][k]){
                    pelana = false;
                }
            }
            //baris
            for(int k = 0; k < M.colEff; k++){
                if(x < M.mem[k][j]){
                    pelana = false;
                    break;
                }
            }
            if(pelana){
                printf("(%d,%d,%d)\n", i, j, x);
                count++;
            }
            
        }

    }
    printf("%d\n", count);
    return 0;
}
// gcc pelana.c matrix.c -o pelana
// min baris
// max kolom