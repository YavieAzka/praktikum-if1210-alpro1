#ifndef LISTKONTIGU_H
#define LISTKONTIGU_H

#include "Boolean.h" 
#include <stdbool.h>
#include <stdio.h>

/* Kamus Umum */
#define CAPACITY 100    /* Kapasitas penyimpanan */
#define IDX_MIN 0       /* Indeks minimum array fisik */
#define IDX_UNDEF -1    /* Indeks tak terdefinisi */
#define MARK -9999      /* Nilai elemen tak terdefinisi/penanda slot kosong */

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen List */

/* List Kontigu varian alt-1b */
typedef struct {
    ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListKontigu;
/* Indeks fisik yang valid untuk array adalah [0..CAPACITY-1] */
/* Jika l adalah ListKontigu, cara deklarasi dan akses: */
/* Deklarasi : l : ListKontigu */
/* Akses fisik: ELMT(l, i) untuk mengakses elemen array pada indeks fisik i */
/* Definisi List:
    List kosong: semua elemen fisik bernilai MARK.
    Elemen list valid: blok kontigu elemen fisik non-MARK.
    Indeks logis: 0..listLength(l)-1.
    Indeks fisik efektif: firstIdx(l)..lastIdx(l) (inklusif).
*/
/* ********** SELEKTOR FISIK ********** */
#define ELMT(l, i) (l).contents[(i)]
/* Macro ELMT digunakan untuk mengakses elemen pada indeks FISIK i dari array. */
/* Perhatian: Indeks fisik i belum tentu sama dengan indeks logis elemen list. */
/* Gunakan fungsi getElmt/setElmt untuk akses berdasarkan indeks logis. */


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong */
void CreateList(ListKontigu *l) {
    /* I.S. l sembarang */
    /* F.S. Terbentuk ListKontigu l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen fisik ListKontigu l dengan MARK */
    int i;
    for (i = 0; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

/* ********** SELEKTOR  ********** */

/* *** Pencari Indeks Fisik Batas Efektif *** */
int firstIdx(ListKontigu l) {
    /* Prekondisi : List l boleh kosong */
    /* Mengirimkan indeks fisik elemen valid pertama dalam list l, */
    /* atau IDX_UNDEF jika l kosong */
    int i = 0;
    while (i < CAPACITY && ELMT(l, i) == MARK) {
        i++;
    }
    if (i == CAPACITY) {
        return IDX_UNDEF;
    } else {
        return i;
    }
}

int lastIdx(ListKontigu l) {
    /* Prekondisi : List l boleh kosong */
    /* Mengirimkan indeks fisik elemen valid terakhir dalam list l, */
    /* atau IDX_UNDEF jika l kosong */
    int i = CAPACITY - 1;
    while (i >= 0 && ELMT(l, i) == MARK) {
        i--;
    }
    return i;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListKontigu l) {
    /* Mengirimkan true jika List l kosong (tidak memiliki elemen efektif) */
    return (firstIdx(l) == IDX_UNDEF);
}

/* *** Banyaknya elemen *** */
int listLength(ListKontigu l) {
    /* Mengirimkan banyaknya elemen efektif ListKontigu */
    /* Mengirimkan nol jika List kosong */
    if (isEmpty(l)) {
        return 0;
    } else {
        return lastIdx(l) - firstIdx(l) + 1;
    }
}

/* *** Test List penuh *** */
boolean isFull(ListKontigu l) {
    /* Mengirimkan true jika List l penuh (jumlah elemen efektif == CAPACITY) */
    return (listLength(l) == CAPACITY);
}


ElType getElmt(ListKontigu l, int i) {
    /* Prekondisi : List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
    /* Mengirimkan elemen List yang ke-i (indeks logis) */
    return ELMT(l, firstIdx(l) + i);
}

/* *** Mengubah elemen berdasarkan indeks logis *** */
void setElmt(ListKontigu *l, int i, ElType val) {
    /* I.S. List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
    /* F.S. Elemen List yang ke-i secara logis bernilai val */
    ELMT(*l, firstIdx(*l) + i) = val;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(int i) {
    /* Mengirimkan true jika i adalah indeks fisik yang valid untuk array  */
    /* yaitu antara IDX_MIN dan CAPACITY-1 */
    return (i >= IDX_MIN && i < CAPACITY);
}

boolean isIdxEff(ListKontigu l, int i) {
    /* Mengirimkan true jika i adalah indeks fisik yang efektif (valid secara fisik */
    /* dan merupakan bagian dari elemen list yang valid). */
    /* yaitu i >= firstIdx(l) dan i <= lastIdx(l). */
    /* Mengembalikan false jika l kosong. */
    int first = firstIdx(l);
    int last = lastIdx(l);
    
    if (first == IDX_UNDEF) {
        return false;
    } else {
        return (i >= first && i <= last);
    }
}



/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListKontigu *l) {
    /* I.S. l sembarang */
    /* F.S. ListKontigu l terdefinisi  */
    /* Proses: membaca banyaknya elemen l dan mengisi nilainya secara kontigu dalam list, seluruh elemen fisik lain di luar blok efektif di-set MARK.  */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
    /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
    /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
    /*    Jika n = 0; hanya terbentuk List kosong */
    
    int n;
    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY);
    
    CreateList(l); // Inisialisasi list dengan MARK
    
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &ELMT(*l, i));
    }
}

void printList(ListKontigu l) {
    /* Proses : Menuliskan isi list efektif dengan traversal. */
    /* List ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma". */
    /* Tanpa tambahan karakter di depan, di tengah, atau di belakang. */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] (e adalah elemen pada indeks logis) */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    
    printf("[");
    if (!isEmpty(l)) {
        int i;
        int len = listLength(l);
        
        for (i = 0; i < len; i++) {
            printf("%d", getElmt(l, i));
            if (i < len - 1) {
                printf(",");
            }
        }
    }
    printf("]");
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListKontigu l1, ListKontigu l2) {
    /* Mengirimkan true jika l1 sama dengan l2 */
    /* yaitu jika panjangnya sama dan elemen pada indeks logis yang sama juga sama */
    
    if (listLength(l1) != listLength(l2)) {
        return false;
    } else {
        int i = 0;
        int len = listLength(l1);
        boolean equal = true;
        
        while (i < len && equal) {
            if (getElmt(l1, i) != getElmt(l2, i)) {
                equal = false;
            }
            i++;
        }
        
        return equal;
    }
}

/* ********** SEARCHING ********** */
/* *** Mencari elemen berdasarkan nilai *** */
int indexOf(ListKontigu l, ElType val) {
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks LOGIS (0..length-1) elemen pertama yang bernilai val */
    /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
    
    if (isEmpty(l)) {
        return IDX_UNDEF;
    } else {
        int i = 0;
        int len = listLength(l);
        boolean found = false;
        
        while (i < len && !found) {
            if (getElmt(l, i) == val) {
                found = true;
            } else {
                i++;
            }
        }
        
        if (found) {
            return i;
        } else {
            return IDX_UNDEF;
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListKontigu lIn, ListKontigu *lOut) {
    /* I.S. lIn terdefinisi, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (elemen efektif disalin, */
    /*      dimulai dari indeks fisik 0 di lOut, sisanya MARK). */
    
    CreateList(lOut); // Inisialisasi lOut dengan MARK
    
    if (!isEmpty(lIn)) {
        int i;
        int len = listLength(lIn);
        
        for (i = 0; i < len; i++) {
            ELMT(*lOut, i) = getElmt(lIn, i);
        }
    }
}

void shiftBlock(ListKontigu *l, int startPhys, int endPhys, int delta) {
    /* I.S. List l terdefinisi, ada cukup ruang MARK di arah pergeseran */
    /* F.S. Elemen fisik dari startPhys hingga endPhys digeser ke kanan (delta > 0) */
    /* atau ke kiri (delta < 0), elemen yang kosong dijadikan MARK. */
    
    int i;
    
    if (delta > 0) { // Geser kanan
        for (i = endPhys; i >= startPhys; i--) {
            ELMT(*l, i + delta) = ELMT(*l, i);
        }
        // Set MARK untuk posisi yang ditinggalkan
        for (i = startPhys; i < startPhys + delta; i++) {
            ELMT(*l, i) = MARK;
        }
    } else if (delta < 0) { // Geser kiri
        for (i = startPhys; i <= endPhys; i++) {
            ELMT(*l, i + delta) = ELMT(*l, i);
        }
        // Set MARK untuk posisi yang ditinggalkan
        for (i = endPhys + delta + 1; i <= endPhys; i++) {
            ELMT(*l, i) = MARK;
        }
    }
}

/* ********** PENAMBAHAN ELEMEN ********** */
/* *** Menambahkan elemen berdasarkan nilai *** */
void insertFirst(ListKontigu *l, ElType val) {
    /* Menambahkan val sebagai elemen pertama List l (indeks logis 0) */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val menjadi elemen pertama l, list mungkin bergeser secara fisik. */
    /* Proses:
       1. Jika list kosong, tempatkan val di indeks fisik 0.
       2. Jika tidak kosong dan ada ruang di indeks fisik firstIdx(l)-1, tempatkan val di sana.
       3. Jika tidak kosong dan tidak ada ruang di kiri (firstIdx=0) tapi ada ruang di kanan,
          geser semua elemen efektif [firstIdx..lastIdx] ke kanan satu posisi,
          lalu tempatkan val di firstIdx fisik yang lama. */
    
    if (isEmpty(*l)) {
        // List kosong, tempatkan val di indeks fisik 0
        ELMT(*l, 0) = val;
    } else {
        int first = firstIdx(*l);
        
        if (first > 0) {
            // Ada ruang di kiri, tempatkan val di firstIdx-1
            ELMT(*l, first - 1) = val;
        } else {
            // Tidak ada ruang di kiri (firstIdx=0), geser semua elemen ke kanan
            int last = lastIdx(*l);
            shiftBlock(l, first, last, 1);
            ELMT(*l, first) = val;
        }
    }
}

void insertLast(ListKontigu *l, ElType val) {
    /* Menambahkan val sebagai elemen terakhir List l (indeks logis length) */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val menjadi elemen terakhir l, list mungkin bergeser secara fisik. */
    /* Proses: Mirip insertFirst, tapi di ujung kanan (lastIdx).
       1. Jika list kosong, tempatkan val di indeks fisik 0.
       2. Jika tidak kosong dan ada ruang di indeks fisik lastIdx(l)+1, tempatkan val di sana.
       3. Jika tidak kosong dan tidak ada ruang di kanan  tapi ada ruang di kiri,
          geser semua elemen efektif [firstIdx..lastIdx] ke kiri satu posisi,
          lalu tempatkan val di lastIdx fisik yang lama. */
    
    if (isEmpty(*l)) {
        // List kosong, tempatkan val di indeks fisik 0
        ELMT(*l, 0) = val;
    } else {
        int last = lastIdx(*l);
        
        if (last < CAPACITY - 1) {
            // Ada ruang di kanan, tempatkan val di lastIdx+1
            ELMT(*l, last + 1) = val;
        } else {
            // Tidak ada ruang di kanan (lastIdx=CAPACITY-1), geser semua elemen ke kiri
            int first = firstIdx(*l);
            if (first > 0) { // Pastikan ada ruang di kiri
                shiftBlock(l, first, last, -1);
                ELMT(*l, last) = val;
            }
        }
    }
}

void insertAt(ListKontigu *l, ElType val, int i) {
    /* Menambahkan val sebagai elemen pada indeks logis ke-i */
    /* I.S. List l tidak penuh, mungkin kosong. */
    /*      Jika l tidak kosong, i adalah indeks logis yang valid untuk penambahan (0..listLength(l)). */
    /* F.S. val disisipkan pada indeks logis ke-i, elemen setelahnya digeser. List mungkin bergeser secara fisik. */
    /* Proses:
       1. Jika list kosong (i harus 0), sama seperti insertFirst/Last.
       2. Jika 0 < i < listLength(l):
          a. Tentukan indeks fisik target: physTarget = firstIdx(l) + i.
          b. Cek ruang: Prioritaskan menggeser ke kanan jika ada ruang setelah lastIdx.
             Geser elemen dari physTarget hingga lastIdx ke kanan satu posisi.
          c. Jika tidak ada ruang kanan, coba geser ke kiri jika ada ruang sebelum firstIdx.
             Geser elemen dari firstIdx hingga physTarget-1 ke kiri satu posisi.
             physTarget sekarang menjadi physTarget-1.
          d. Tempatkan val di ELMT(*l, physTarget). */
    
    if (isEmpty(*l)) {
        // List kosong (i harus 0), sama seperti insertFirst/Last
        ELMT(*l, 0) = val;
    } else if (i == 0) {
        // Menambahkan di awal
        insertFirst(l, val);
    } else if (i == listLength(*l)) {
        // Menambahkan di akhir
        insertLast(l, val);
    } else {
        // 0 < i < listLength(l)
        int first = firstIdx(*l);
        int last = lastIdx(*l);
        int physTarget = first + i;
        
        if (last < CAPACITY - 1) {
            // Ada ruang di kanan, geser elemen dari physTarget hingga lastIdx ke kanan
            shiftBlock(l, physTarget, last, 1);
            ELMT(*l, physTarget) = val;
        } else if (first > 0) {
            // Tidak ada ruang di kanan, tapi ada ruang di kiri
            // Geser elemen dari firstIdx hingga physTarget-1 ke kiri
            shiftBlock(l, first, physTarget - 1, -1);
            ELMT(*l, physTarget - 1) = val;
        }
    }
}

/* ********** PENGHAPUSAN ELEMEN ********** */
void deleteFirst(ListKontigu *l, ElType *val) {
    /* Menghapus elemen pertama List l (indeks logis 0) */
    /* I.S. List l tidak kosong */
    /* F.S. val adalah nilai elemen pertama l sebelum dihapus. */
    /*      Elemen pertama fisik (di firstIdx) di-set menjadi MARK. */
    
    int first = firstIdx(*l);
    *val = ELMT(*l, first);
    ELMT(*l, first) = MARK;
}

void deleteLast(ListKontigu *l, ElType *val) {
    /* Menghapus elemen terakhir list (indeks logis length-1) */
    /* I.S. List l tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum dihapus. */
    /*      Elemen terakhir fisik (di lastIdx) di-set menjadi MARK. */
    
    int last = lastIdx(*l);
    *val = ELMT(*l, last);
    ELMT(*l, last) = MARK;
}

void deleteAt(ListKontigu *l, int i, ElType *val) {
    /* Menghapus elemen pada indeks logis ke-i */
    /* I.S. List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
    /* F.S. val adalah nilai elemen pada indeks logis i sebelum dihapus. */
    /*      Elemen pada indeks logis i dihapus dari list, elemen setelahnya digeser ke kiri */
    /*      secara fisik untuk menjaga kontiguitas blok. */
    /* 
        Jika 0 < i < listLength(l)-1:
          a. Tentukan indeks fisik target: physTarget = firstIdx(l) + i.
          b. Simpan ELMT(l, physTarget) ke val.
          c. Geser elemen dari physTarget+1 hingga lastIdx(l) ke kiri satu posisi.
          d. Set ELMT(*l, lastIdx(l)) = MARK (posisi fisik terakhir yang lama). */
    
    if (i == 0) {
        // Hapus elemen pertama
        deleteFirst(l, val);
    } else if (i == listLength(*l) - 1) {
        // Hapus elemen terakhir
        deleteLast(l, val);
    } else {
        // 0 < i < listLength(l)-1
        int first = firstIdx(*l);
        int last = lastIdx(*l);
        int physTarget = first + i;
        
        // Simpan nilai yang akan dihapus
        *val = ELMT(*l, physTarget);
        
        // Geser elemen dari physTarget+1 hingga lastIdx ke kiri satu posisi
        shiftBlock(l, physTarget + 1, last, -1);
    }
}

/* ********** OPERASI PENGGABUNGAN ********** */
void concat(ListKontigu l1, ListKontigu l2, ListKontigu *l3) {
    /* I.S. l1 dan l2 terdefinisi, boleh kosong. l3 sembarang. */
    /* F.S. l3 adalah hasil penggabungan elemen efektif l1 dan l2. */
    /*      Elemen l1 disalin terlebih dahulu, diikuti elemen l2. */
    /*      Hasilnya ditempatkan di l3 mulai dari indeks fisik 0. */
    /*      Jika total elemen > CAPACITY, hanya elemen yang muat yang disalin. */
    
    CreateList(l3); // Inisialisasi l3 dengan MARK
    
    int i = 0;
    int j = 0;
    int len1 = listLength(l1);
    int len2 = listLength(l2);
    
    // Salin elemen l1
    while (i < len1 && i < CAPACITY) {
        ELMT(*l3, i) = getElmt(l1, i);
        i++;
    }
    
    // Salin elemen l2
    while (i < CAPACITY && j < len2) {
        ELMT(*l3, i) = getElmt(l2, j);
        i++;
        j++;
    }
}

#endif