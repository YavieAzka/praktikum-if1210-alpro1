/*
* File: polynomial.h
* Deskripsi: Definisi ADT Polynomial untuk representasi polynomial dengan elemen integer
*/

#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_DEGREE 100

/**
 * Definisi dari ADT Polynomial
 * Sebuah Polynomial direpresentasikan oleh sebuah array of coefficients
 * dimana sebuah index menunjukkan eksponennya
 * Contoh: 3^2 + 2x + 1 direpresentasikan sebagai coeff[0] = 1, coeff[1] = 2, coeff[2] = 3
 */

typedef struct {
    int coeff[MAX_DEGREE + 1];  // Array untuk menyimpan koefisien polynomial
    int degree;                 // Derajat tertinggi sebuah polynomial
} Polynomial;

/* ==================== Polynomial Operations ==================== */
/**
 * File: polynomial.c
 * Implementasi dari ADT Polynomial untuk representasi polynomial dengan elemen integer
 */


 /* Konstruktor */
 void CreatePolynomial(Polynomial *p) {
     int i;
     for (i = 0; i <= MAX_DEGREE; i++) {
         p->coeff[i] = 0;
     }
     p->degree = 0;
 }
 
 void CreatePolynomialFromArray(Polynomial *p, int coeffArray[], int size) {
     int i;
     
     // Inisialisasi semua koefisien dengan 0
     for (i = 0; i <= MAX_DEGREE; i++) {
         p->coeff[i] = 0;
     }
     
     // Set koefisien berdasarkan array yang diberikan
     for (i = 0; i < size && i <= MAX_DEGREE; i++) {
         p->coeff[i] = coeffArray[i];
     }
     
     // Update derajat polynomial
     p->degree = 0;
     for (i = MAX_DEGREE; i >= 0; i--) {
         if (p->coeff[i] != 0) {
             p->degree = i;
             break;
         }
     }
 }
 
 /* Selektor */
 int GetCoefficient(Polynomial *p, int exponent) {
     if (exponent < 0 || exponent > MAX_DEGREE) {
         return 0;  // Return 0 untuk eksponen di luar range
     }
     return p->coeff[exponent];
 }
 
 int GetDegree(Polynomial *p) {
     return p->degree;
 }
 
 int Evaluate(Polynomial *p, int x) {
     int result = 0;
     int i;
     
     for (i = 0; i <= p->degree; i++) {
         result += p->coeff[i] * (int)pow(x, i);
     }
     
     return result;
 }
 
 /* Mutator */
 void SetCoefficient(Polynomial *p, int exponent, int coefficient) {
     if (exponent < 0 || exponent > MAX_DEGREE) {
         return;  // Ignore if exponent is out of range
     }
     
     p->coeff[exponent] = coefficient;
     
     // Update degree jika diperlukan
     if (coefficient != 0 && exponent > p->degree) {
         p->degree = exponent;
     } else if (coefficient ==
  0 && exponent == p->degree) {
         // Jika koefisien tertinggi menjadi 0, cari derajat tertinggi baru
         int i;
         for (i = p->degree - 1; i >= 0; i--) {
             if (p->coeff[i] != 0) {
                 p->degree = i;
                 return;
             }
         }
         p->degree = 0;  // Jika semua koefisien 0
     }
 }
 
 /* Operasi Baca/Tulis */
 void ReadPolynomial(Polynomial *p) {
     int size, i, coeff;
     
     // Inisialisasi polynomial
     CreatePolynomial(p);
     
     // Baca ukuran
     scanf("%d", &size);
     
     // Baca koefisien
     for (i = 0; i < size && i <= MAX_DEGREE; i++) {
         scanf("%d", &coeff);
         SetCoefficient(p, i, coeff);
     }
 }
 
 /* Operator Aritmatika */
 void AddPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result) {
     int i;
     int maxDegree = (p1->degree > p2->degree) ? p1->degree : p2->degree;
     
     // Inisialisasi result
     CreatePolynomial(result);
     
     // Penjumlahan koefisien
     for (i = 0; i <= maxDegree; i++) {
         result->coeff[i] = p1->coeff[i] + p2->coeff[i];
     }
     
     // Update derajat result
     result->degree = maxDegree;
     
     // Periksa derajat tertinggi (mungkin hasil penjumlahan = 0)
     for (i = maxDegree; i >= 0; i--) {
         if (result->coeff[i] != 0) {
             result->degree = i;
             break;
         }
         if (i == 0) {
             result->degree = 0;  // Jika semua koefisien 0
         }
     }
 }
 
 void SubtractPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result) {
     int i;
     int maxDegree = (p1->degree > p2->degree) ? p1->degree : p2->degree;
     
     // Inisialisasi result
     CreatePolynomial(result);
     
     // Pengurangan koefisien
     for (i = 0; i <= maxDegree; i++) {
         result->coeff[i] = p1->coeff[i] - p2->coeff[i];
     }
     
     // Update derajat result
     result->degree = maxDegree;
     
     // Periksa derajat tertinggi (mungkin hasil pengurangan = 0)
     for (i = maxDegree; i >= 0; i--) {
         if (result->coeff[i] != 0) {
             result->degree = i;
             break;
         }
         if (i == 0) {
             result->degree = 0;  // Jika semua koefisien 0
         }
     }
 }
 
 int IsEqual(Polynomial *p1, Polynomial *p2) {
     int i;
     
     // Jika derajat berbeda, polynomial tidak sama
     if (p1->degree != p2->degree) {
         return 0;
     }
     
     // Periksa semua koefisien
     for (i = 0; i <= p1->degree; i++) {
         if (p1->coeff[i] != p2->coeff[i]) {
             return 0;
         }
     }
     
     return 1;  // Jika semua koefisien sama
 }
 
 /* Operasi Lain */
 void PrintPolynomial(Polynomial *p) {
     int i;
     int isFirstTerm = 1;
     
     // Jika semua koefisien 0, tampilkan hanya 0
     if (p->degree == 0 && p->coeff[0] == 0) {
         printf("0\n");
         return;
     }
     
     // Tampilkan polynomial dari derajat tertinggi ke terendah
     for (i = p->degree; i >= 0; i--) {
         if (p->coeff[i] != 0) {
             // Menangani tanda plus/minus
             if (isFirstTerm) {
                 // Suku pertama
                 if (p->coeff[i] < 0) {
                     printf("-");
                 }
                 isFirstTerm = 0;
             } else {
                 // Bukan suku pertama
                 if (p->coeff[i] < 0) {
                     printf(" - ");
                 } else {
                     printf(" + ");
                 }
             }
             
             // Tampilkan koefisien (kecuali koefisien 1 atau -1 dan bukan konstanta)
             int absCoeff = abs(p->coeff[i]);
             if ((absCoeff != 1) || (i == 0)) {
                 printf("%d", absCoeff);
             }
             
             // Tampilkan variabel dan eksponennya
             if (i > 0) {
                 printf("x");
                 if (i > 1) {
                     printf("^%d", i);
                 }
             }
         }
     }
     
     printf("\n");
 }
 #endif