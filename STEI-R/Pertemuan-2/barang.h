#ifndef BARANG_H
#define BARANG_H
/**
 * Sistem Simulasi Transaksi Gudang
 * * Asumsi: 
 * Data Array of Struct "Barang" sudah diinisialisasi di fungsi main().
 * Tidak perlu ada proses membaca file atau memotong string (strtok).
 * Fokus pada manipulasi angka dan logika kondisional.
 */

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 50

// Struktur data untuk menyimpan informasi barang di gudang
typedef struct {
    int id;
    char nama[50];
    int stok;
    int batasMinimum;  // Batas peringatan jika stok menipis
    float hargaSatuan;
} Barang;

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
void prosesTransaksi(Barang *b, int jumlah, int jenisTransaksi);

/**
 * 2. Fungsi untuk menghitung total nilai uang (aset) dari seluruh barang di gudang.
 * * ATURAN LOGIKA:
 * - Nilai aset 1 jenis barang = stok * hargaSatuan
 * - Jumlahkan nilai aset dari seluruh barang yang ada di dalam array.
 * * @daftarBarang: array of struct Barang
 * @jumlahBarang: total macam barang di dalam array
 * @return: total nilai aset keseluruhan (float)
 */
float hitungTotalAset(Barang daftarBarang[], int jumlahBarang);

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
void cekStokKritis(Barang daftarBarang[], int jumlahBarang);

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
void berikanDiskonMassal(Barang daftarBarang[], int jumlahBarang, float persentaseDiskon);
#endif