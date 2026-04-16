#include "GnomeTracker.h"
/**
 * Rentang indeks yang digunakan adalah [0 .. CAPACITY-1]
 * Jika L adalah List bernama GnomeTrack:
 *   - L.contents[i] mengakses Gnome ke-i
 *   - L.nEff menyatakan jumlah elemen yang valid
 * 
 * Definisi:
 *   - List kosong: L.nEff = 0
 *   - Elemen pertama: L.contents[0]
 *   - Elemen terakhir: L.contents[L.nEff - 1]
 */

/* ********** KONSTRUKTOR ********** */
/**
 * I.S. sembarang
 * F.S. Terbentuk list kosong dengan jumlah elemen efektif 0
 */
void createTracker(GnomeTrack *L){
    L->nEff = 0;
}

/* ********** SELEKTOR ********** */
/**
 * Mengembalikan banyaknya elemen efektif
 */
int length(GnomeTrack L){
    return L.nEff;
    /*
    [1,2,3]
    */
}

/**
 * Mengembalikan kapasitas maksimum list
 */
int maximumCap(){
    return CAPACITY;
}

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen pertama
 */
IdxType getFirstIdx(GnomeTrack L){
    return 0;
}

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen terakhir
 */
IdxType getLastIdx(GnomeTrack L){
    return L.nEff - 1;
}

/**
 * Mengembalikan Gnome pada indeks ke-i
 * Prekondisi: i adalah indeks efektif yang valid
 */
Gnome getElmt(GnomeTrack L, IdxType i){
    return L.contents[i];
}

/* ********** SETTER ********** */
/**
 * Mengubah elemen pada indeks i menjadi nilai val
 */
void setElmt(GnomeTrack *L, IdxType i, Gnome val){
    L->contents[i] = val;
}

/**
 * Mengatur nilai jumlah elemen efektif menjadi N
 */
void setLength(GnomeTrack *L, int N){
    L->nEff = N;
}

/* ********** Validasi INDEKS ********** */
/**
 * Mengembalikan true jika indeks berada dalam rentang kapasitas [0..CAPACITY-1]
 */
boolean isIdxValid(IdxType i){
    return (i <= CAPACITY - 1 && i >= 0);
}

/**
 * Mengembalikan true jika indeks adalah indeks efektif [0..nEff-1]
 */
boolean isIdxEff(GnomeTrack L, IdxType i){
    return (i >= 0 && i < L.nEff - 1);
}

/* ********** TEST KOSONG/PENUH ********** */
/**
 * Mengembalikan true jika list kosong
 */
boolean isEmpty(GnomeTrack L){
    return (L.nEff == 0);
}

/**
 * Mengembalikan true jika list penuh
 */
boolean isFull(GnomeTrack L){
    return (getLastIdx(L) == CAPACITY);
}

/* ********** Operasi Dasar ********** */
/**
 * Menyisipkan Gnome pada indeks tertentu
 * Semua elemen setelah indeks digeser ke kanan
 */
void insertAt(GnomeTrack *L, Gnome g, IdxType idx){
    /*
    [1,2,3,4,5]
     0 1 2 3 4 5
     insert 6 at index 2

    */
    // GESER
    for(int i = getLastIdx(*L) + 1; i > idx; i--){
        L->contents[i] = L->contents[i - 1];
    }
    L->contents[idx] = g;
    L->nEff++;
    /*
    [1,2,3,4,5]
     0 1 2 3 4 5
     insert 6 at index 2

    [1,2,3,4,5,5]
    [1,2,3,4,4,5]
    [1,2,3,3,4,5]
    [1,2,6,3,4,5]
    */
}

/**
 * Menambahkan Gnome ke posisi pertama dalam list
 * Semua elemen yang ada digeser ke kanan
 */
void insertFirst(GnomeTrack *L, Gnome g){
    for(int i = getLastIdx(*L) + 1; i >= 1; i--){
        L->contents[i] = L->contents[i - 1];
    }
    L->contents[0] = g;
    L->nEff++;
}

/**
 * Menambahkan Gnome ke posisi terakhir dalam list
 */
void insertLast(GnomeTrack *L, Gnome g){
    L->contents[L->nEff] = g;
    L->nEff++;
}

/**
 * Menghapus Gnome pada indeks tertentu
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *g
 */
void deleteAt(GnomeTrack *L, IdxType idx, Gnome *g){
    /*
    [1,2,6,3,4,5] -> [1,2,3,4,5]
    delete index 2:
    [1,2,6,3,4,5]
    [1,2,3,3,4,5]
    [1,2,3,4,4,5]
    [1,2,3,4,5,5]
    [1,2,3,4,5]
    */
   *g = L->contents[idx];
    for(int i = idx; i < getLastIdx(*L); i++){
        L->contents[i] = L->contents[i + 1];
    }
    L->nEff--;
   
}

/**
 * Menghapus Gnome pada indeks pertama (0)
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *g
 */
void deleteFirst(GnomeTrack *L, Gnome *g){
    *g = L->contents[0];
    for(int i = 0; i < getLastIdx(*L); i++){
        L->contents[i] = L->contents[i + 1];
    }
    L->nEff--;
}

/**
 * Menghapus Gnome pada indeks terakhir
 * Elemen terakhir disimpan pada *g
 */
void deleteLast(GnomeTrack *L, Gnome *g){
    *g = L->contents[getLastIdx(*L)];
    L->nEff--;
}

/**
 * Mengembalikan indeks Gnome berdasarkan ID
 * Jika tidak ditemukan, mengembalikan IDX_UNDEF
 */
IdxType indexOf(GnomeTrack L, int id){
    for(int i = 0; i <= getLastIdx(L); i++){
        if(L.contents[i].id == id){
            return i;
        }
    }
    return IDX_UNDEF;
}

/* ********** Utilitas dan Output ********** */
/**
 * Menampilkan seluruh isi list GnomeTrack
 * Format:
 * Gnome Entry-<index>: 
 * ID=xxx 
 * NAME=xxx 
 * HEIGHT=xxx.xx (2 angka di belakang koma)
 * TYPE=xxx 
 * FRIENDLY=Yes/No
 */
/* Setiap tampilan elemen dipisahkan dengan baris kosong */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void printAllGnome(GnomeTrack L){
    if(isEmpty(L)){
        printf("List kosong\n");
    }
    else{
        for(int i = 0; i <= getLastIdx(L); i++){
            printf("Gnome Entry-%d\n", i);
            printf("ID=%d\n",L.contents[i].id);
            /*
            Lanjutin untuk atribut lain...
            */
        }
    }
}

/**
 * Menghapus seluruh Gnome yang tidak ramah (isFriendly == false)
 * Setiap Gnome yang dihapus akan dicetak namanya ke layar
 * Format output: "DELETED: <nama_gnome>"
 * I.S. L terdefinisi
 * F.S. Semua Gnome tidak ramah dihapus dari list dan ditampilkan namanya
 */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void deleteUnfriendly(GnomeTrack *L){
    if(isEmpty(*L)){
        printf("List kosong\n");
    }
    /*
    [1,2,3,4,5]
    delete index 1: [1,3,4,5]
    */
    else{
        for(int i = 0; i <= getLastIdx(*L); i++){
            if(L->contents[i].isFriendly == false){
                Gnome temp;
                deleteAt(L, i, &temp);
                printf("DELETED: %s", temp.name);
                i--;
            }
        }
    }
}

/**
 * Menampilkan hanya Gnome dengan height >= minHeight
 * format penampilan sama seperti printAllGnome
 */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void filterByHeight(GnomeTrack L, float minHeight){
    if(isEmpty(L)){
        printf("List kosong\n");
    }
    else{
        int idx = 0;
        for(int i = 0; i <= getLastIdx(L); i++){
            if(L.contents[i].height >= minHeight){
                printf("Gnome Entry-%d\n", idx);
                printf("ID=%d\n",L.contents[i].id);
                /*
                Lanjutin untuk atribut lain...
                */
                idx++;
            }
            
        }
    }
}

/**
 * Menampilkan hanya Gnome dengan tipe tertentu
 * format penampilan sama seperti printAllGnome
 */
/* Jika L kosong : Hanya menulis "List kosong" dan diakhiri newline */
void filterByType(GnomeTrack L, char *targetType){
    if(isEmpty(L)){
        printf("List kosong\n");
    }
    else{
        int idx = 0;
        for(int i = 0; i <= getLastIdx(L); i++){
            if(strcmp(L.contents[i].type, targetType) == 0){
                printf("Gnome Entry-%d\n", idx);
                printf("ID=%d\n",L.contents[i].id);
                /*
                Lanjutin untuk atribut lain...
                */
                idx++;
            }
            
        }
    }
}
