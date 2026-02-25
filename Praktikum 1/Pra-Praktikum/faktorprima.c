#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int div = 2;
    int start = 0;
    while(n > 1){
        int count = 0;
        while(n % div == 0){
            n = n / div;
            count++;
        }
        if(start == 0){
            if(count == 1){
                printf("%d", div);
                start = 1;
            }
            if (count > 1){
                printf("%d^%d", div, count);
                start = 1;
            }
            
        }
        else{
            if(count == 1){
                printf(" * %d", div);
            }
            if (count > 1){
                printf(" * %d^%d", div, count);
            }
        }
        div++;
    }
    printf("\n");
    return 0;
}