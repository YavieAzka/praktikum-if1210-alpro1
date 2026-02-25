/* File: line.h */
/* Tanggal: 3 September 2022 */
/* Definisi ADT LINE, menggunakan ADT point */
#ifndef LINE_H
#define LINE_H

/* *** ADT LAIN YANG DIPAKAI *** */
#include "boolean.h"
#include "point.h"
#include "line.h"
#include <stdio.h>

/* *** Definisi TYPE LINE *** */
typedef struct {
  POINT PAw;  /* Titik Awal  */
  POINT PAkh; /* Titik Akhir */
} LINE;

/* *** Selektor LINE *** */
#define PAwal(L) (L).PAw
#define PAkhir(L) (L).PAkh
        
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk LINE *** */
void CreateLine(LINE * L, POINT P1, POINT P2) {
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaLINE(LINE * L) {
    POINT P1, P2;
    
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    
    while (EQ(P1, P2)) {
        printf("Invalid Line\n");
        BacaPOINT(&P1);
        BacaPOINT(&P2);
    }
    
    CreateLine(L, P1, P2);
}
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai LINE yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk LINE yang valid 
   LINE disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan line tidak valid, diberikan pesan kesalahan: 
   "Invalid Line" */
/* Contoh:
   2 3
   2 3
   Invalid Line
   2 3
   3 3 
   --> terbentuk line L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */

void TulisLINE(LINE L) {
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
}
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */

/* *** Kelompok operasi line *** */
float PanjangLINE(LINE L) {
    return Panjang(L.PAw, L.PAkh);
}
/* Menghitung panjang line L : berikan rumusnya */

float Gradien(LINE L) {
    float x1 = Absis(PAwal(L));
    float y1 = Ordinat(PAwal(L));
    float x2 = Absis(PAkhir(L));
    float y2 = Ordinat(PAkhir(L));
    
    return (y2 - y1) / (x2 - x1);
}
/* Mengembalikan Gradien (m) dari L */
/* Gradien line yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */

void GeserLINE(LINE * L, float deltaX, float deltaY) {
    L->PAw.X += deltaX;
    L->PAw.Y += deltaY;

    L->PAkh.X += deltaX;
    L->PAkh.Y += deltaY;
}
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */

/* *** Kelompok predikat *** */
boolean IsTegakLurus(LINE L1, LINE L2) {
    float m1 = Gradien(L1);
    float m2 = Gradien(L2);
    
    return (m1 * m2 == -1);
}
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua line saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */

boolean IsSejajar(LINE L1, LINE L2) {
    float m1 = Gradien(L1);
    float m2 = Gradien(L2);
    
    return (m1 == m2);
}
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua line saling sejajar jika memiliki gradien yang sama */

#endif