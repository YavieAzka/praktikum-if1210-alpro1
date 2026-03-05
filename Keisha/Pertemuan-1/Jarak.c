#include <stdio.h>

int main(){
    float jarak;
    float kecepatan;
    float waktu;

    scanf("%f", &kecepatan);
    scanf("%f", &waktu);

    jarak = kecepatan * waktu;
    printf("%f\n", jarak);

}