#include <stdio.h>

void tantangan(){
    int n; scanf("%d", &n);
    if(n*5 + 7 != 46){
        trap();
    }
    else if(n <= 5){
        trap();
    }
    else if(n >= 9){
        trap();
    }
    else{
        printf("Benar!\n");
    }
}

