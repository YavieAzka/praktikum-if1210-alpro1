#include "boolean.h"
#include <stdio.h>
#ifndef LIST_STATIK_H
#define LIST_STATIK_H

/* Kamus Umum */
#define MaxCapacity 100
#define IdxMin 1
#define ElUndef -999 /* Elemen tak terdefinisi */

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef int ElType;

typedef struct
	{
		ElType TI [MaxCapacity+1]; /* memori tempat penyimpan elemen (container) */
		int Neff; /* banyaknya elemen efektif */
	} TabInt;

/* Indeks yang digunakan [IdxMin..MaxCapacity] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Tabel penuh: T.Neff = MaxCapacity 
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyList (TabInt *T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxCapacity */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length (TabInt T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T);
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen pertama */
/* Jika list kosong, return -1 */

IdxType GetLastIdx (TabInt T);
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen terakhir */
/* Jika list kosong, return -1 */

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmtAt (TabInt T, IdxType i);
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi), i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Jika list kosong, return ElUndef */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */

void SetEl (TabInt *T, IdxType i, ElType v);
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

void SetNeff (TabInt *T, IdxType N);
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i);
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi), i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid untuk ukuran tabel yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEff (TabInt T, IdxType i);
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi), i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel yaitu antara indeks pertama dan indeks Neff */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void ShowAll (TabInt T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : elemen tabel ditulis berderet ke kanan */
/* Tampilkan tabel dalam bentuk [<Elemen-1>,<Elemen-2>,<Elemen-3>,..<Elemen-Neff>], seperti [1,2,3], dan diakhiri newline */
/* Jika T kosong : Hanya menulis "Tabel kosong" dan diakhiri newline */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan dan pengurangan */
TabInt PlusTab (TabInt T1, TabInt T2);
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */

TabInt MinusTab (TabInt T1, TabInt T2);
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType IdxMinTab (TabInt T);
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai minimum pada tabel */

/* ********** PENGGABUNGAN TABEL ********** */
TabInt ConcatTable (TabInt T1, TabInt T2);
/* Prekondisi : Tabel T1 dan T2 sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan hasil penggabungan dua buah tabel, T2 ditaruh di belakang T1 */

#endif