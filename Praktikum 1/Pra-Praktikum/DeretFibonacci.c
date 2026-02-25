#include <stdio.h>

int main(){
    int n, sum;
    scanf("%d", &n);
    sum = 0;
    int f0, f1, c;
    f0 = 0;
    f1 = 1;
    for(int i = 0; i < n; i++){
        if(i == 0){
            printf("%d", f0);   
        }
        else if(i == 1){
            printf(" %d", f1);
            
        }
        else{
            c = f0 + f1;
            printf(" %d", c);
            
            f0 = f1;
            f1 = c;
        }
        
    }
    printf("\n");
    return 0;
}