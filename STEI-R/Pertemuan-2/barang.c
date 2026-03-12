#include "barang.h"

/**
 * 1. Prosedur untuk memproses perubahan jumlah stok barang.
 * * ATURAN LOGIKA:
 * - Jika jenisTransaksi == 1 (Barang Masuk / Restock), maka stok bertambah.
 * - Jika jenisTransaksi == 0 (Barang Keluar / Terjual), maka stok berkurang.
 * - VALIDASI: Stok tidak boleh bernilai negatif! Jika jumlah barang yang keluar 
 * melebihi ketersediaan stok saat ini, maka stok dikosongkan (menjadi 0) 
 * dan cetak pesan peringatan ke layar: "Peringatan: Stok [NamaBarang] tidak mencukupi!"
 * * @b: pointer ke struktur Barang yang akan diubah
 * @jumlah: kuantitas barang yang ditransaksikan
 * @jenisTransaksi: 1 untuk masuk, 0 untuk keluar
 */
void prosesTransaksi(Barang *b, int jumlah, int jenisTransaksi){
    if(jenisTransaksi == 1){
        b->stok = b->stok + jumlah;
    }
    if(jenisTransaksi == 0){
        if(b->stok < jumlah){
            b->stok = 0;
            printf("Peringatan: Stok %s tidak mencukupi!\n", b->nama);
        }
        else{
            b->stok = b->stok - jumlah;
        }
    }
}

/**
 * 2. Fungsi untuk menghitung total nilai uang (aset) dari seluruh barang di gudang.
 * * ATURAN LOGIKA:
 * - Nilai aset 1 jenis barang = stok * hargaSatuan
 * - Jumlahkan nilai aset dari seluruh barang yang ada di dalam array.
 * * @daftarBarang: array of struct Barang
 * @jumlahBarang: total macam barang di dalam array
 * @return: total nilai aset keseluruhan (float)
 */
float hitungTotalAset(Barang daftarBarang[], int jumlahBarang){
    float total = 0;
    for(int i = 0; i < jumlahBarang; i++){
        total += daftarBarang[i].stok * daftarBarang[i].hargaSatuan;
    }
    return total;
}

/**
 * 3. Prosedur untuk melakukan inspeksi barang yang hampir habis.
 * * ATURAN LOGIKA:
 * - Lakukan perulangan pada seluruh daftar barang.
 * - Sebuah barang disebut "KRITIS" jika (stok <= batasMinimum).
 * - Jika kritis, cetak ke layar dengan format: 
 * "ID-[ID] [NamaBarang] - Sisa Stok: [stok] (KRITIS!)"
 * * @daftarBarang: array of struct Barang
 * @jumlahBarang: total macam barang di dalam array
 */
void cekStokKritis(Barang daftarBarang[], int jumlahBarang){
    for(int i = 0; i < jumlahBarang; i++){
        if(daftarBarang[i].stok <= daftarBarang[i].batasMinimum){
            printf("ID-%d %s - Sisa Stok: %d (KRITIS!)\n", daftarBarang[i].id, daftarBarang[i].nama, daftarBarang[i].stok);
        }
    }
}

/**
 * 4. Prosedur untuk memotong harga jual semua barang (Diskon Cuci Gudang).
 * * ATURAN LOGIKA:
 * - Harga satuan setiap barang dalam array dikurangi sebesar persentase diskon.
 * - Contoh: Jika persentaseDiskon adalah 0.15 (berarti 15%) dan harga awal 1000,
 * maka harga baru menjadi 850.
 * * @daftarBarang: array of struct Barang
 * @jumlahBarang: total macam barang di dalam array
 * @persentaseDiskon: nilai desimal diskon (0.0 hingga 1.0)
 */
void berikanDiskonMassal(Barang daftarBarang[], int jumlahBarang, float persentaseDiskon){
    for(int i = 0; i < jumlahBarang; i++){
        daftarBarang[i].hargaSatuan = daftarBarang[i].hargaSatuan * (1 - persentaseDiskon);
    }

}