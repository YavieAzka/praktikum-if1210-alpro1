#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

/* Tulis kode disini jika perlu */

int main() {
    init();
    /* Tulis kode dibawa ini */
    // TODO: baca file input.txt
    // TODO: tulis kode untuk algoritma utama
    // TODO: close file input.txt
    FILE *f = fopen("input.txt", "r");
    int id, success, value;
    fscanf(f, "%d %d %d", &id, &success, &value);
    int total = 0;
    int berhasil =  0;
    int valuetot = 0;
    while(id != -1){
        total++;
        if(success == 1){
            berhasil++;
            valuetot += value;
        }
        fscanf(f, "%d %d %d", &id, &success, &value);
    }
    printf("Total Misi: %d\n", total);
    printf("Misi Berhasil: %d\n", berhasil);
    printf("Total Nilai Misi: %d\n", valuetot);
    return 0;
}