#include <stdio.h>
#include "barang.h"

int main(){
    Barang daftarBarang[3];
    daftarBarang[0].id = 1;
    strcpy(daftarBarang[0].nama, "Pensil");  
    daftarBarang[0].stok = 100;
    daftarBarang[0].batasMinimum = 20;
    daftarBarang[0].hargaSatuan = 2000;
    
    daftarBarang[1].id = 2;
    strcpy(daftarBarang[1].nama, "Buku Tulis");
    daftarBarang[1].stok = 50;
    daftarBarang[1].batasMinimum = 10;
    daftarBarang[1].hargaSatuan = 5000;
    
    daftarBarang[2].id = 3;
    strcpy(daftarBarang[2].nama, "Penghapus");
    daftarBarang[2].stok = 10;
    daftarBarang[2].batasMinimum = 5;       
    daftarBarang[2].hargaSatuan = 1000;

    printf("Total aset awal: %f\n", hitungTotalAset(daftarBarang, 3));
    prosesTransaksi(&daftarBarang[0], 30, 0); // Pensil keluar 30
    prosesTransaksi(&daftarBarang[1], 40, 0); // Buku Tulis keluar 40

    // Menambah stok Penghapus sebanyak 15
    prosesTransaksi(&daftarBarang[2], 15, 1); // Penghapus masuk 15

    
    printf("Total stok setelah transaksi:\n");
    for(int i = 0; i < 3; i++){ 
        printf("%s: %d\n", daftarBarang[i].nama, daftarBarang[i].stok);
    }

    cekStokKritis(daftarBarang, 3);

    berikanDiskonMassal(daftarBarang, 3, 0.10); // Diskon 10%
    printf("Harga setelah diskon:\n");
    for(int i = 0; i < 3; i++){ 
        printf("%s: %f\n", daftarBarang[i].nama, daftarBarang[i].hargaSatuan);
    }   
}