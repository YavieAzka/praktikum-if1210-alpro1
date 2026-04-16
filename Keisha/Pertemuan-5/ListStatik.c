#include "ListStatik.h"
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
void MakeEmptyList (TabInt *T){
    T->Neff = 0;
    for(int i = 1; i <= MaxCapacity; i++){
        T->TI[i] = ElUndef;
    }
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxCapacity */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length (TabInt T){
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
    return MaxCapacity;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
    if(IsEmpty(T)){
        return -1;
    }
    return IdxMin;
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen pertama */
/* Jika list kosong, return -1 */

IdxType GetLastIdx (TabInt T){
    if(IsEmpty(T)){
        return -1;
    }
    return T.Neff;
    /*
    [-999,1,2,3,4,5,6]
    */
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen terakhir */
/* Jika list kosong, return -1 */

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmtAt (TabInt T, IdxType i){
    if(IsEmpty(T)){
        return ElUndef;
    }
    else{
        return T.TI[i];
    }
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi), i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Jika list kosong, return ElUndef */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout){

    for(int i = 1; i <= GetLastIdx(Tin); i++){
        Tout->TI[i] = Tin.TI[i];
    }
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */

void SetEl (TabInt *T, IdxType i, ElType v){
    T->TI[i] = v;
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

void SetNeff (TabInt *T, IdxType N){
    T->Neff = N;
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi) */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
    return (i >= 0 && i <= 100);
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi), i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid untuk ukuran tabel yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEff (TabInt T, IdxType i){
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}
/* Prekondisi : Tabel T sembarang (bisa kosong atau bisa terisi), i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel yaitu antara indeks pertama dan indeks Neff */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
    return (T.Neff == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
    return (T.Neff == MaxCapacity);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void ShowAll (TabInt T){
    if(IsEmpty(T)){
        printf("Tabel kosong\n");
    }
    for(int i = 1; i <= GetLastIdx(T); i++){
        if(i == 1){
            printf("[%d", T.TI[i]);
        }
        else if(i == GetLastIdx(T)){
            printf(",%d]\n", T.TI[i]);
        }
        else{
            printf(",%d", T.TI[i]);
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : elemen tabel ditulis berderet ke kanan */
/* Tampilkan tabel dalam bentuk [<Elemen-1>,<Elemen-2>,<Elemen-3>,..<Elemen-Neff>], seperti [1,2,3], dan diakhiri newline */
/* Jika T kosong : Hanya menulis "Tabel kosong" dan diakhiri newline */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan dan pengurangan */
TabInt PlusTab (TabInt T1, TabInt T2){
    TabInt result;
    MakeEmptyList(&result);
    for(int i = 1; i <= GetLastIdx(T1); i++){
        result.TI[i] = T1.TI[i] + T2.TI[i];
    }
    result.Neff = T1.Neff;
    return result;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */

TabInt MinusTab (TabInt T1, TabInt T2){
    TabInt result;
    MakeEmptyList(&result);
    for(int i = 1; i <= GetLastIdx(T1); i++){
        result.TI[i] = T1.TI[i] - T2.TI[i];
    }
    result.Neff = T1.Neff;
    return result;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
    int max = -1000;
    for(int i = 1; i <= GetLastIdx(T); i++){
        if(T.TI[i] > max){
            max = T.TI[i];
        }
    }
    return max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin (TabInt T){
    int min = 1000;
    for(int i = 1; i <= GetLastIdx(T); i++){
        if(T.TI[i] < min){
            min = T.TI[i];
        }
    }
    return min;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
    int max = -1000;
    int idx = -1;
    for(int i = 1; i <= GetLastIdx(T); i++){
        if(T.TI[i] > max){
            max = T.TI[i];
            idx = i;
        }
    }
    return idx;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType IdxMinTab (TabInt T){
    int min = 1000;
    int idx = -1;
    for(int i = 1; i <= GetLastIdx(T); i++){
        if(T.TI[i] < min){
            min = T.TI[i];
            idx = i;
        }
    }
    return idx;
}
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai minimum pada tabel */

/* ********** PENGGABUNGAN TABEL ********** */
TabInt ConcatTable (TabInt T1, TabInt T2){
    TabInt result;
    MakeEmptyList(&result);
    int result_lastIdx;
    for(int i = 1; i <= GetLastIdx(T1); i++){
        result.TI[i] = T1.TI[i];
        
    }
    result_lastIdx = GetLastIdx(T1) + 1;
    for(int i = 1; i <= GetLastIdx(T2); i++){
        result.TI[result_lastIdx] = T2.TI[i];
        result_lastIdx++;
    }
    result.Neff = T1.Neff + T2.Neff;
    return result;
}
/* Prekondisi : Tabel T1 dan T2 sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan hasil penggabungan dua buah tabel, T2 ditaruh di belakang T1 */
