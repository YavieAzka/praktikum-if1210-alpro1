#include <stdio.h>

int main() {
    int n, i, j, c;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        c = 1; 
        for(int k = n - i - 2; k >= 0; k--){
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("%d", c);
            if (j < i) {
                printf(" ");
            }
            c = c * (i - j) / (j + 1);
        }
        printf("\n"); 
    }
    return 0;
}