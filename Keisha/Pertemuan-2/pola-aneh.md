### **Pola Aneh**

---

**Deskripsi Soal:**
Buatlah sebuah program yang menerima sebuah bilangan bulat ganjil `N`. Program harus mencetak sebuah pola belah ketupat kosong berukuran `N x N` menggunakan karakter bintang (`*`) sebagai garis tepi belah ketupatnya, dan karakter titik (`.`) sebagai latar belakangnya. Titik sudut belah ketupat harus menyentuh bagian tengah dari keempat sisi batas matriks `N x N`.

**Format Masukan (Input):**
Satu baris berisi sebuah bilangan bulat ganjil positif `N` (misalnya 3, 5, 7, 9, dst.) yang merepresentasikan lebar dan tinggi pola.

**Format Keluaran (Output):**
Cetak `N` baris yang masing-masing berisi `N` karakter penyusun pola belah ketupat sesuai dengan deskripsi.

---

### **Contoh Kasus Uji**

**Contoh Masukan 1:**

```text
5

```

**Contoh Keluaran 1:**

```text
..*..
.*.*.
*...*
.*.*.
..*..

```

**Contoh Masukan 2:**

```text
7

```

**Contoh Keluaran 2:**

```text
...*...
..*.*..
.*...*.
*.....*
.*...*.
..*.*..
...*...

```

HINT: Hitung nilai tengah dari ukuran. Bintang terletak ketika (jarak kolom sekarang dengan nilai tengah + jarak baris sekarang dengan nilai tengah) = nilai tengah
