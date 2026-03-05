# **Percabangan dan Perulangan Pada Bahasa C**

## **Bagian 1: Percabangan (Control Flow)**

Secara _default_, program C dieksekusi secara berurutan dari atas ke bawah. Percabangan memungkinkan program untuk "membuat keputusan" dan memilih jalur eksekusi yang berbeda berdasarkan suatu kondisi logika (benar/salah).

### **1. Pernyataan `if`**

Digunakan untuk mengeksekusi sebuah blok kode **hanya jika** kondisinya bernilai benar (_true_ / bernilai bukan 0).

```c
int nilai = 85;
if (nilai >= 75) {
    printf("Selamat, Anda Lulus!\n");
}

```

### **2. Pernyataan `if-else`**

Menyediakan dua jalur: satu jalur jika kondisi benar, dan jalur alternatif jika kondisi salah (_false_ / bernilai 0).

```c
int umur = 16;
if (umur >= 17) {
    printf("Bisa membuat KTP.\n");
} else {
    printf("Belum cukup umur untuk KTP.\n");
}

```

### **3. Pernyataan `if, else-if. else`**

Digunakan ketika ada lebih dari dua kemungkinan kondisi yang harus dievaluasi secara berurutan.

```c
int nilai = 75;
if (nilai >= 85) {
    printf("Grade A\n");
} else if (nilai >= 70) {
    printf("Grade B\n");
} else {
    printf("Grade C\n");
}

```

### **4. Pernyataan `switch-case`**

Alternatif yang lebih rapi dari `if-else if` jika kita hanya membandingkan satu variabel dengan nilai-nilai spesifik (biasanya menu atau karakter).

```c
int hari = 3;
switch(hari) {
    case 1:
        printf("Senin\n");
        break; // Penting agar tidak bablas ke case selanjutnya!
    case 2:
        printf("Selasa\n");
        break;
    case 3:
        printf("Rabu\n");
        break;
    default:
        printf("Hari tidak valid\n");
}

```

---

## **Bagian 2: Perulangan (Looping / Iteration)**

Perulangan digunakan untuk menjalankan blok kode yang sama berkali-kali selama kondisi tertentu terpenuhi. Ini mencegah pemrogram menulis kode yang berulang-ulang (_copy-paste_).

### **Tabel Perbandingan Jenis Perulangan**

| Jenis          | Kapan Sebaiknya Digunakan?                                                                                  | Posisi Pengecekan Kondisi | Eksekusi Minimal |
| -------------- | ----------------------------------------------------------------------------------------------------------- | ------------------------- | ---------------- |
| **`for`**      | Saat **jumlah iterasi sudah diketahui** pasti (misal: cetak angka 1-10).                                    | Di Awal                   | 0 kali           |
| **`while`**    | Saat jumlah iterasi **belum pasti**, bergantung pada kondisi logika.                                        | Di Awal                   | 0 kali           |
| **`do-while`** | Saat program **wajib menjalankan kode minimal satu kali** (misal: menampilkan menu), baru mengecek kondisi. | Di Akhir                  | **1 kali**       |

### **1. Perulangan `for`**

Sintaksnya mengumpulkan tiga bagian utama dalam satu baris: inisialisasi, kondisi, dan _increment/decrement_.

```c
// Cetak angka 1 sampai 5
for (int i = 1; i <= 5; i++) {
    printf("Angka: %d\n", i);
}

```

### **2. Perulangan `while`**

Hanya mengevaluasi kondisi. Variabel pengontrol (_counter_) biasanya diinisialisasi sebelum _loop_ dan diperbarui di dalam _loop_.

```c
int i = 1;
while (i <= 5) {
    printf("Angka: %d\n", i);
    i++; // Jangan lupa increment agar tidak infinite loop!
}

```

### **3. Perulangan `do-while`**

Mirip dengan `while`, namun eksekusi kode dilakukan terlebih dahulu sebelum kondisi dievaluasi.

```c
int pilihan;
do {
    printf("Pilih angka (tekan 0 untuk keluar): ");
    scanf("%d", &pilihan);
} while (pilihan != 0);

```

---

## **Bagian 3: Pernyataan Loncatan (Jump Statements)**

- **`break`**: Menghentikan perulangan sepenuhnya secara paksa dan keluar dari blok _loop_. (Seperti yang kamu pakai di soal FPB sebelumnya).
- **`continue`**: Melewati (skip) sisa kode pada iterasi saat ini, dan langsung melompat ke iterasi berikutnya.

```c
for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue; // Angka 3 akan di-skip
    }
    printf("%d ", i); // Output: 1 2 4 5
}

```
