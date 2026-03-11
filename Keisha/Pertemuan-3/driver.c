#include <stdio.h>
#include "bank.h"

int main(){
    Rekening rek;
    rek.statusAktif = 1;    
    rek.saldo = 90000;
    rek.nomorRekening = 12345;
    strcpy(rek.namaPemilik, "Budi");

    printf("TES FUNGSI HEADER\n");
    printf("Saldo awal: %f\n", rek.saldo);
    tarikTunai(&rek, 60000);
    printf("Saldo setelah penarikan: %f\n", rek.saldo);

    Rekening rek2;
    rek2.statusAktif = 1;
    rek2.saldo = 200000;
    rek2.nomorRekening = 121212;
    strcpy(rek2.namaPemilik, "Andi");

    // transferDana(&rek2, &rek, 50000);
    // printf("Saldo Andi setelah transfer: %f\n", rek2.saldo);
    // printf("Saldo Budi setelah menerima transfer: %f\n", rek.saldo);

    // pengecekan nasabah prioritas
    Rekening daftarRekening[3];
    daftarRekening[0] = rek;            
    daftarRekening[1] = rek2;
    daftarRekening[2].statusAktif = 1;
    daftarRekening[2].saldo = 150000;
    strcpy(daftarRekening[2].namaPemilik, "Citra");
    cetakNasabahPrioritas(daftarRekening, 3, 100000);

    printf("Total Dana Aktif: %f\n", hitungTotalDanaAktif(daftarRekening, 3));
}