#include <stdio.h>

// ADT
typedef struct
{
    int x;
    int y;
} Titik;


// int a;

/*
type Titik: <   x: integer
                y: integer > 

*/



int main(){
    Titik T;
    scanf("%d", &T.x);
    scanf("%d", &T.y);

    printf("(%d, %d)", T.x, T.y);
}