#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"


int main(){
    int n, m, k, x;
    scanf("%d %d %d %d", &n, &m, &k, &x);
    Matrix M;
    createMatrix(n, m, &M);
    readMatrix(&M, n, m);
    Matrix K;
    createMatrix(k, k, &K);
    int count = 0;
    for(int i = 0; i <= n - k; i++){
        for(int j = 0; j <= m - k; j++){

            // i -> i + k
            // j -> j + k
            int sum = 0;
            for(int l = i; l < i + k; l++){
                for(int m = j; m < j + k; m++){
                    sum += M.mem[l][m];
                }
            }
            if(sum <= x){
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
// gcc submatrix.c matrix.c -o sub