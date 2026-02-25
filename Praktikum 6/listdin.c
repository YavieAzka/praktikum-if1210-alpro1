/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDIN_H
#define LISTDIN_H

#include "Boolean.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
    l.nEff      untuk mengetahui banyaknya elemen
    l.buffer    untuk mengakses seluruh nilai elemen list
    l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
    list kosong: l.nEff = 0
    Definisi elemen pertama : l.buffer[i] dengan i=0
    Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l){
    free(l->buffer);
    l->buffer = NULL;  // Mengatur pointer menjadi NULL untuk menghindari dangling pointer
    l->capacity = 0;   // Menetapkan kapasitas menjadi 0 untuk menandakan list kosong
    l->nEff = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
    return l.nEff;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
    int i = 0;
    return i;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l){
    return l.nEff - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
    return(i >= 0 && i < l.capacity);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i){
    return (i >= 0 && i < l.nEff);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
    return (l.nEff == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
    return (l.nEff == l.capacity);
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
    int n; scanf("%d", &n);
    while(n < 0 || n > l->capacity){
        scanf("%d", &n);
    }
    l->nEff = n;
    for(int i = 0; i < n; i++){
        scanf("%d", &l->buffer[i]);
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
        0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList(ListDin l){
    bool start = true;
    printf("[");
    for(int i = 0; i < l.nEff; i++){
        if(start){
            printf("%d", l.buffer[i]);
            start = false;
        }
        else{
            printf(",%d", l.buffer[i]);
        }
    }
    printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
    di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    ListDin retL;
    CreateListDin(&retL, l1.capacity);
    retL.nEff = l1.nEff;
    if(plus){
        for(int i = 0; i < l1.nEff; i++){
            retL.buffer[i] = l1.buffer[i] + l2.buffer[i];
        }
    }
    else{
        for(int i = 0; i < l1.nEff; i++){
            retL.buffer[i] = l1.buffer[i] - l2.buffer[i];
        }
    }
    return retL;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
    if(l1.nEff == l2.nEff){
        for(int i = 0; i < l1.nEff; i++){
            if(l1.buffer[i] != l2.buffer[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
    for(int i = 0; i < l.nEff; i++){
        if(l.buffer[i] == val){
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
    if(l.nEff > 0){
        *max = l.buffer[0];
        *min = l.buffer[0];
        for(int i = 0; i < listLength(l); i++){
            if(l.buffer[i] > *max){
                *max = l.buffer[i];
            }
            if(l.buffer[i] < (*min)){
                *min = l.buffer[i];
            }
        }
    }
    
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut, lIn.capacity);
    lOut->nEff = lIn.nEff;
    for(int i = 0; i < lIn.nEff; i++){
        lOut->buffer[i] = lIn.buffer[i];
    }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l){
    int sum = 0;
    for(int i = 0; i < l.nEff; i++){
        sum += 
        l.buffer[i];
    }
    return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
    int count = 0;
    for(int i = 0; i < l.nEff; i++){
        if(l.buffer[i] == val){
            count++;
        }
    }
    return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
    if(asc){
        for(int i = 0 ; i < l->nEff - 1 ; i++){
            int Imin = i ;
             // Mencari minimum pada array [j..n-1]
            for(int j = i+1 ; j < l->nEff ; j++){
               if(l->buffer[Imin] > l->buffer[j]){
                  Imin = j ;
               }
               // berdasarkan value   
            }
   
            // Tukar arr[i] dengan arr[Imin]
            int temp = l->buffer[Imin] ;
            l->buffer[Imin] = l->buffer[i] ;
            l->buffer[i] = temp ;
         }
    }
    else{
        for(int i = 0 ;i < l->nEff - 1 ; i++){
            int Imin = i ;
             // Mencari minimum pada array [j..n-1]
            for(int j = i+1; j < l->nEff ; j++){
               if(l->buffer[Imin] < l->buffer[j]){
                  Imin = j ;
               }
               // berdasarkan value   
            }
   
            // Tukar arr[i] dengan arr[Imin]
            int temp = l->buffer[Imin] ;
            l->buffer[Imin] = l->buffer[i] ;
            l->buffer[i] = temp ;
         }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
    algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
    if(l->nEff != l->capacity){
        l->buffer[l->nEff] = val;
        l->nEff++;
    }
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
    if(l->nEff != 0){
        *val = l->buffer[l->nEff - 1];
        l->nEff--;
    }
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
    BUFFER(*l) = (ElType *) realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(ElType));
    CAPACITY(*l) += num;
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
    int newCapacity = CAPACITY(*l) - num;
    if (newCapacity < NEFF(*l)) {
        // Jika kapasitas baru kurang dari nEff, sesuaikan nEff
        NEFF(*l) = newCapacity;
    }
    BUFFER(*l) = realloc(BUFFER(*l), newCapacity * sizeof(ElType));
    CAPACITY(*l) = newCapacity;
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l){
    BUFFER(*l) = realloc(BUFFER(*l), NEFF(*l) * sizeof(ElType));
    CAPACITY(*l) = NEFF(*l);
}
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */

#endif