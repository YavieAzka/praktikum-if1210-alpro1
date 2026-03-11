/**
 * Sistem Manajemen Transaksi Perbankan
 * * Asumsi:
 * - Data array of struct "Rekening" sudah diinisialisasi di fungsi main().
 * - Fokus murni pada logika transaksional, mutasi saldo, dan validasi status.
 */

#include <stdio.h>
#include <string.h>

#define MAX_NASABAH 100

// Struktur data untuk menyimpan informasi rekening nasabah
typedef struct {
    int nomorRekening;
    char namaPemilik[50];
    double saldo;
    int statusAktif; // 1 = Aktif (Bisa transaksi), 0 = Diblokir (Tidak bisa transaksi)
} Rekening;

/**
 * 1. Prosedur untuk melakukan penarikan uang dari rekening.
 * * ATURAN LOGIKA (Validasi Berlapis):
 * - Cek apakah rekening aktif. Jika statusAktif == 0, cetak: "Transaksi Gagal: Rekening diblokir."
 * - Cek apakah saldo mencukupi. Saldo minimal setelah penarikan tidak boleh kurang dari 50000.
 * (Artinya, saldo yang ditarik tidak boleh membuat sisa saldo < 50000).
 * Jika kurang, cetak: "Transaksi Gagal: Saldo tidak mencukupi."
 * - Jika semua syarat terpenuhi, kurangi saldo dan cetak: "Penarikan berhasil. Sisa saldo: [saldo]"
 * @param
 *  @rek: pointer ke struktur Rekening yang melakukan penarikan
 * @jumlah: nominal uang yang ditarik
 */
void tarikTunai(Rekening *rek, double jumlah){
    if(rek->statusAktif == 0){
        printf("Transaksi Gagal: Rekening diblokir.\n");
        
    }
    else{
        if(rek->saldo - jumlah < 50000){
            printf("Transaksi Gagal: Saldo tidak mencukupi.\n");
        }
        else{
            rek->saldo = rek->saldo - jumlah;
            printf("Penarikan berhasil. Sisa saldo: %f\n", rek->saldo);
        }
    }
}

/**
 * 2. Fungsi untuk mentransfer dana antar dua rekening.
 * Ini melatih interaksi DUA pointer sekaligus.
 * * ATURAN LOGIKA:
 * - Baik rekening pengirim maupun penerima HARUS dalam keadaan aktif (statusAktif == 1).
 * - Terapkan aturan saldo minimal yang sama seperti tarikTunai untuk pengirim (sisa saldo >= 50000).
 * - Jika validasi gagal, fungsi mengembalikan nilai 0 (Gagal) dan tidak ada saldo yang berubah.
 * - Jika validasi berhasil, kurangi saldo pengirim, tambah saldo penerima, dan kembalikan nilai 1 (Berhasil).
 * * @pengirim: pointer ke rekening yang mengirim uang
 * @penerima: pointer ke rekening yang menerima uang
 * @jumlah: nominal uang yang ditransfer
 * @return: 1 jika transfer sukses, 0 jika gagal
 */
int transferDana(Rekening *pengirim, Rekening *penerima, double jumlah){
    if(pengirim->statusAktif == 1 && penerima->statusAktif == 1){
        if(pengirim->saldo - jumlah < 50000){
            printf("Transaksi Gagal: Saldo tidak mencukupi.\n");
            return 0;
        }
        else{
            pengirim->saldo = pengirim->saldo - jumlah;
            penerima->saldo = penerima->saldo + jumlah;
            printf("Transaksi Berhasil!\n");
            return 1;
        }
    }
    else{
        return 0;
    }
}

/**
 * 3. Prosedur untuk mencari dan mencetak nasabah "Prioritas".
 * Melatih proses filtering pada array of struct.
 * * ATURAN LOGIKA:
 * - Telusuri semua data nasabah dalam array.
 * - Nasabah disebut "Prioritas" jika saldo mereka LEBIH DARI ATAU SAMA DENGAN batasPrioritas
 * DAN rekening mereka dalam keadaan Aktif.
 * - Cetak nasabah yang memenuhi syarat dengan format:
 * "Prioritas: [namaPemilik] - Saldo: [saldo]"
 * * @daftarRekening: array of struct Rekening
 * @jumlahNasabah: total nasabah di dalam array
 * @batasPrioritas: nominal batas saldo untuk menjadi prioritas
 */
void cetakNasabahPrioritas(Rekening daftarRekening[], int jumlahNasabah, double batasPrioritas){
    for (int i = 0; i < jumlahNasabah; i++){
        if(daftarRekening[i].saldo >= batasPrioritas && daftarRekening[i].statusAktif == 1){
            printf("Prioritas: %s - Saldo: %f\n", daftarRekening[i].namaPemilik, daftarRekening[i].saldo);
        }
    }
}

/**
 * 4. Fungsi untuk menghitung Total Dana Pihak Ketiga (Akumulasi Bersyarat).
 * Melatih pola accumulator dengan kondisi tertentu.
 * * ATURAN LOGIKA:
 * - Bank ingin tahu berapa total uang riil yang bisa diputar.
 * - Jumlahkan saldo HANYA dari rekening yang statusnya Aktif (statusAktif == 1).
 * - Rekening yang diblokir tidak dihitung ke dalam total.
 * * @daftarRekening: array of struct Rekening
 * @jumlahNasabah: total nasabah di dalam array
 * @return: total akumulasi saldo dari rekening aktif
 */
double hitungTotalDanaAktif(Rekening daftarRekening[], int jumlahNasabah){
    double total = 0;
    for(int i = 0; i < jumlahNasabah; i++){
        if(daftarRekening[i].statusAktif == 1){
            total += daftarRekening[i].saldo;
        }
    }

    return total;
}