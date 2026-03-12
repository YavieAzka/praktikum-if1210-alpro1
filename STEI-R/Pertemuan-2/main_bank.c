#include "bank.h"

int main(){
    Rekening r1;
    strcpy(r1.namaPemilik, "Budi");
    r1.nomorRekening = 12345;
    r1.saldo = 100000;
    r1.statusAktif = 1;

    Rekening r2;
    strcpy(r2.namaPemilik, "Ani");
    r2.nomorRekening = 23456;
    r2.saldo = 150000;
    r2.statusAktif = 1;

    Rekening r3;
    strcpy(r3.namaPemilik, "Cici");
    r3.nomorRekening = 34567;
    r3.saldo = 200000;
    r3.statusAktif = 0;

    Rekening arrayRekening[3] = {r1, r2, r3};

    //cetakNasabahPrioritas(arrayRekening, 3, 150000);
    printf("Total dana aktif: %.2f\n", hitungTotalDanaAktif(arrayRekening, 3));

}