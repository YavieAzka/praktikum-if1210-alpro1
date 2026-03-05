#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if(n == 1){
        printf("0\n");
    }
    else if(n == 2){
        printf("1\n");
    }
    else{
        int a,b, current;
        a = 1;
        b = 0;

        printf("%d %d ", b, a);
        for(int i = 3; i <= n; i++){
            current = a + b;
            printf("%d ", current);
            /*
            a = current;
            b = a;
            */
            b = a;
            a = current;
        }
    }
}