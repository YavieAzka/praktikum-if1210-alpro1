#include <stdio.h>

int main(){
    int n, count;
    scanf("%d", &n);
    count = (n + 1)/2;
    for(int i = 1; i <= (n + 1)/2; i++){
        for(int j = 1; j <= n; j++){
            if(j == count || j == n - count + 1){
                printf("*");
                
            }
            else{
                printf(".");
            }
        }
        count--;
        printf("\n");
    }
    count += 2;
    for(int i = ((n + 1)/2) + 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j == count || j == n - count + 1){
                printf("*");
                
            }
            else{
                printf(".");
            }
        }
        count++;
        printf("\n");
    }
}