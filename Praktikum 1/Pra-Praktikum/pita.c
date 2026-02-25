#include <stdio.h>
int main(){
    int a, b, m;
    scanf("%d", &a);
    scanf("%d", &b);
    if(a > b){
        m = a;
    }
    else{
        m = b;
    }
    for(int i = m; i > 0; i--){
        if(a % i == 0 && b % i == 0){
            printf("%d\n", i);
            i = 0;
        }
    }
    return 0;
}