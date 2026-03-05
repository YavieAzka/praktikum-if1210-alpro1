#include <stdio.h>
// PROGRAM KELILING LINGKARAN
// {Program untuk menghitung keliling sebuah lingkaran}


int main(){
    // KAMUS
    const float PI = 3.14159;
    float R;
    float Kel;

    // ALGORITMA
    scanf("%f", &R);
    Kel = 2 * PI * R;
    printf("%f\n", Kel);

    return 0;
}