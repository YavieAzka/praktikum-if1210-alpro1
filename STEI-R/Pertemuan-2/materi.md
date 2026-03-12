# Subprogram dalam C

Dalam paradigma pemrograman terstruktur, **Subprogram** adalah blok kode yang dirancang untuk melakukan satu tugas spesifik. Tujuannya adalah memecah program besar (seperti `main()`) menjadi potongan-potongan kecil agar kode lebih rapi, mudah dibaca, menghindari duplikasi (bisa dipanggil berulang kali), dan mudah di-_debug_.

Di dalam bahasa C, **semua subprogram secara teknis disebut sebagai Fungsi (_Function_)**. Berbeda dengan bahasa seperti Pascal yang memisahkan kata kunci `procedure` dan `function`, C memukul rata semuanya. Namun, secara konsep logika, kita tetap membaginya menjadi dua kategori utama:

---

### **1. Prosedur (Fungsi yang Tidak Mengembalikan Nilai)**

Prosedur adalah subprogram yang tugasnya murni melakukan suatu **aksi** (seperti mencetak teks ke layar atau mengubah _state_ data di memori), tanpa memberikan hasil balikan/laporan (nilai) ke pemanggilnya.

- **Ciri Utama di C:** Selalu dideklarasikan dengan tipe data balikan **`void`** (yang berarti "kosong"). Tidak memerlukan instruksi `return` yang membawa angka/data di akhir kodenya.
- **Contoh dari latihan kita:**

```c
void cetakNasabahPrioritas(Rekening daftarRekening[], int jumlahNasabah, double batas) {
    // Hanya melakukan perulangan dan perintah printf().
    // Tidak ada proses melempar hasil kalkulasi ke fungsi main().
}

```

- **Analogi:** Seperti menyuruh OB membersihkan meja. Anda hanya menyuruhnya melakukan tindakan (aksi), dan Anda tidak mengharapkan dia memberikan barang apapun kembali kepada Anda setelah selesai.

### **2. Fungsi (Fungsi yang Mengembalikan Nilai)**

Fungsi adalah subprogram yang menerima _input_ (opsional), memprosesnya, dan **wajib mengembalikan sebuah hasil/output** kepada blok kode yang memanggilnya.

- **Ciri Utama di C:** Dideklarasikan dengan tipe data spesifik seperti `int`, `float`, `double`, atau `char`. Wajib diakhiri dengan instruksi **`return [nilai/variabel];`**.
- **Contoh dari latihan kita:**

```c
double hitungTotalDanaAktif(Rekening daftarRekening[], int jumlahNasabah) {
    double total = 0;
    // ... proses kalkulasi ...
    return total; // Melempar angka hasil penjumlahan kembali ke fungsi main()
}

```

- **Analogi:** Seperti menyuruh akuntan menghitung pajak. Anda memberikan dokumen (input), lalu akuntan tersebut memprosesnya dan memberikan Anda sebuah laporan angka (output / _return value_) untuk Anda gunakan lebih lanjut.

---

### **Anatomi Subprogram dalam C**

Setiap subprogram di C terdiri dari 4 elemen penyusun:

1. **Tipe Kembalian (_Return Type_):** `void`, `int`, `float`, dll. Menentukan apakah ini bertindak sebagai Prosedur atau Fungsi.
2. **Nama Fungsi:** Harus deskriptif (contoh: `tarikTunai`, `hitungTotal`).
3. **Parameter/Argumen:** Variabel di dalam tanda kurung `()`. Ini adalah jalur komunikasi masuk (input) ke dalam subprogram.
4. **Badan Fungsi (_Body_):** Kode logika di dalam kurung kurawal `{ ... }`.

---

### **Konsep Paling Krusial: Parameter Passing**

Ini adalah rahasia utama mengapa subprogram di C sangat tangguh, dan ini menjelaskan mengapa kita menggunakan simbol `&` dan `*` pada latihan perbankan/gudang sebelumnya. Ada dua cara fungsi menerima data:

**A. Pass by Value (Kirim Salinan)**
Fungsi hanya menerima **fotokopi** dari nilai asli. Apapun yang terjadi di dalam fungsi, nilai asli di fungsi `main()` tidak akan berubah.

- _Contoh:_ Pada `hitungTotalDanaAktif(bankArray, 4)`, angka `4` (jumlah nasabah) dikirim sebagai salinan. Jika di dalam fungsi variabel `jumlahNasabah` diubah menjadi `10`, angka `4` di fungsi `main` tetap aman.

**B. Pass by Reference / Pointer (Kirim Alamat Asli)**
Fungsi menerima **kunci gembok / alamat memori** dari variabel asli. Fungsi ini berhak mengubah data aslinya secara permanen.

- _Contoh:_ Pada `tarikTunai(&bankArray[0], 150000)`, kita mengirimkan alamat memori dengan simbol ampersand `&`. Lalu di dalam subprogramnya diterima dengan pointer bintang `*rek`. Akibatnya, saat ada instruksi `rek->saldo -= jumlah;`, saldo nasabah di dalam array `main()` benar-benar terpotong.

---
