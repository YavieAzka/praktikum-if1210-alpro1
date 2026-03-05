#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n;
    scanf("%d", &n);
    int c = n / 2; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Jarak baris + Jarak kolom == Jarak dari tengah ke tepi
            if (abs(i - c) + abs(j - c) == c) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    
    return 0;
}