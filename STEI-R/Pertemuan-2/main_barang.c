#include "barang.h"

int main(){
    Barang b1 = {1, "Pensil", 100, 20, 2000};
    Barang b2 = {2, "Buku Tulis", 10, 10, 5000};
    Barang b3 = {3, "Penghapus", 30, 5, 1000};

    Barang daftarBarang[3] = {b1, b2, b3};

    // prosesTransaksi(&b1, 120, 0);
    // printf("Stok %s sekarang: %d\n", b1.nama, b1.stok);

    // float total = hitungTotalAset(daftarBarang, 3);
    // printf("Total aset: %.2f\n", total);

    //prosesTransaksi(&b2, 45, 0);
    
    berikanDiskonMassal(daftarBarang, 3, 0.2);
    for(int i = 0; i < 3; i++){
        printf("Harga %s setelah diskon: %.2f\n", daftarBarang[i].nama, daftarBarang[i].hargaSatuan);
    }
}