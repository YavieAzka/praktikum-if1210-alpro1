#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include "boolean.h"
#include <math.h>  

/* Definisi type POINT */
typedef struct {
    float X;  /* absis (sumbu X) */
    float Y;  /* ordinat (sumbu Y) */
} POINT;

/* Macro selektor komponen */
#define Absis(P)   (P).X
#define Ordinat(P) (P).Y

/* Membentuk POINT P dengan komponen X dan Y */
void CreatePoint(POINT *P, float X, float Y) {
    P->X = X;
    P->Y = Y;
}

/* Membaca nilai POINT dari stdin: masukkan X Y */
void BacaPOINT(POINT *P) {
    scanf("%f %f", &P->X, &P->Y);
}

/* Menulis POINT ke stdout dalam format "(X,Y)" */
void TulisPOINT(POINT P) {
    printf("(%f,%f)", P.X, P.Y);
}

/* Mengambil / mengubah komponen X dan Y */
float GetX(const POINT P) {
    return P.X;
}

float GetY(const POINT P) {
    return P.Y;
}

void SetX(POINT *P, float X) {
    P->X = X;
}

void SetY(POINT *P, float Y) {
    P->Y = Y;
}

/* Mengecek lokasi POINT pada sumbu atau kuadran */
boolean IsOrigin(POINT P) {
    return (P.X == 0 && P.Y == 0);
}

boolean IsOnSbX(POINT P) {
    return (P.Y == 0);
}

boolean IsOnSbY(POINT P) {
    return (P.X == 0);
}

int Kuadran(POINT P) {
    if (P.X > 0 && P.Y > 0) return 1;
    else if (P.X < 0 && P.Y > 0) return 2;
    else if (P.X < 0 && P.Y < 0) return 3;
    else if (P.X > 0 && P.Y < 0) return 4;
    return 0; /* Prekondisi: P bukan origin dan tidak di sumbu */
}

/* Membandingkan dua POINT */
boolean Equals(POINT P1, POINT P2) {
    return (P1.X == P2.X && P1.Y == P2.Y);
}

boolean NonEquals(POINT P1, POINT P2) {
    return (P1.X != P2.X || P1.Y != P2.Y);
}

/* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
float Distance(POINT P1, POINT P2) {
    float dx = P1.X - P2.X;
    float dy = P1.Y - P2.Y;
    return sqrtf(dx * dx + dy * dy);
}

/* Menghasilkan titik tengah P1 dan P2 */
POINT MidPoint(POINT P1, POINT P2) {
    POINT P;
    P.X = (P1.X + P2.X) / 2;
    P.Y = (P1.Y + P2.Y) / 2;
    return P;
}

#endif  /* POINT_H */