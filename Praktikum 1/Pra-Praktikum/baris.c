#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value = 0;
            int current_num = 1;
            for (int sum = 0; sum < 2*n - 1; sum++) {
                for (int r = 0; r <= sum; r++) {
                    int c = sum - r;
                    if (r < n && c < n) {
                        if (r == i && c == j) {
                            value = current_num;
                        }
                        current_num++;
                    }
                }
            }
            if(j == 0) printf("%d", value);
            else printf(" %d", value);
        }
        printf("\n");
    }
    
    return 0;
}