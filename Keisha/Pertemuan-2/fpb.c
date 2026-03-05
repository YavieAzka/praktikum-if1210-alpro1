#include <stdio.h>

int main(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    // cari bilangan terkecil antara a dan b
    int min;
    if(a < b){
        min = a;
    }
    else{
        min = b;
    }

    // cari fpb
    int fpb;
    for(int i = min; i >= 1; i--){
        if(a % i == 0 && b % i == 0){
            fpb = i;
            break;
        }
    }
    printf("%d\n", fpb);
}