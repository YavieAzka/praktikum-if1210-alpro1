#include <stdio.h>
#include "boolean.h"
#include "line.h"
#include "point.h"

int main(){
    LINE A, B;
    BacaLINE(&A);
    GeserLINE(&A, 2, 3);
    TulisLINE(A);
    //printf("%f", Gradien(A));
}