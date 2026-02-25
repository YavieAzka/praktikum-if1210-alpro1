#include <stdio.h>

int main(){
    int a, b, c;
    int count = 0;
    for(a = 0; a <= 6; a++){
        for(b = 0; b <= 7; b++){
            for(c = 0; c <= 8; c++){
                if(a + b + c == 18){
                    count++;
                }
            }
        }
    }
    printf("%d", count);
}