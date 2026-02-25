/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "Boolean.h"
#include <stdio.h>
#include <stdbool.h>

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Intedex baris, kolom */
typedef int ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
    m->rowEff = nRows;
    m->colEff = nCols;
}

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia Matrix" *** */
bool isMatrixIdxValid(int i, int j) {
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
    return m.rowEff - 1;
}

IdxType getLastIdxCol(Matrix m) {
    return m.colEff - 1;
}

bool isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (i >= 0 && i < m.rowEff && j >= 0 && j < m.colEff);
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    return m.mem[i][i];
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
    createMatrix(mIn.rowEff, mIn.colEff, mOut);
    for (int i = 0; i < mIn.rowEff; i++) {
        for (int j = 0; j < mIn.colEff; j++) {
            mOut->mem[i][j] = mIn.mem[i][j];
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
#include <stdio.h>

void readMatrix(Matrix *m, int nRow, int nCol) {
    createMatrix(nRow, nCol, m);
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            scanf("%d", &m->mem[i][j]);
        }
    }
}

void displayMatrix(Matrix m) {
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            printf("%d", m.mem[i][j]);
            if (j < m.colEff - 1) printf(" ");
        }
        if (i < m.rowEff - 1) printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
    Matrix m;
    createMatrix(m1.rowEff, m1.colEff, &m);
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            m.mem[i][j] = m1.mem[i][j] + m2.mem[i][j];
        }
    }
    return m;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    Matrix m;
    createMatrix(m1.rowEff, m1.colEff, &m);
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            m.mem[i][j] = m1.mem[i][j] - m2.mem[i][j];
        }
    }
    return m;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    Matrix m;
    createMatrix(m1.rowEff, m2.colEff, &m);
    for (int i = 0; i < m1.rowEff; i++) {
        for (int j = 0; j < m2.colEff; j++) {
            m.mem[i][j] = 0;
            for (int k = 0; k < m1.colEff; k++) {
                m.mem[i][j] += m1.mem[i][k] * m2.mem[k][j];
            }
        }
    }
    return m;
}

Matrix multiplyByConst(Matrix m, ElType x) {
    Matrix res;
    createMatrix(m.rowEff, m.colEff, &res);
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            res.mem[i][j] = m.mem[i][j] * x;
        }
    }
    return res;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    for (int i = 0; i < m->rowEff; i++) {
        for (int j = 0; j < m->colEff; j++) {
            m->mem[i][j] *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
bool isMatrixEqual(Matrix m1, Matrix m2) {
    if (m1.rowEff != m2.rowEff || m1.colEff != m2.colEff) return false;
    for (int i = 0; i < m1.rowEff; i++) {
        for (int j = 0; j < m1.colEff; j++) {
            if (m1.mem[i][j] != m2.mem[i][j]) return false;
        }
    }
    return true;
}

bool isMatrixNotEqual(Matrix m1, Matrix m2) {
    return !isMatrixEqual(m1, m2);
}

bool isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return (m1.rowEff == m2.rowEff && m1.colEff == m2.colEff);
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
    return m.rowEff * m.colEff;
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
bool isSquare(Matrix m) {
    return m.rowEff == m.colEff;
}

bool isSymmetric(Matrix m) {
    if (!isSquare(m)) return false;
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            if (m.mem[i][j] != m.mem[j][i]) return false;
        }
    }
    return true;
}

bool isIdentity(Matrix m) {
    if (!isSquare(m)) return false;
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            if (i == j && m.mem[i][j] != 1) return false;
            else if (i != j && m.mem[i][j] != 0) return false;
        }
    }
    return true;
}

bool isSparse(Matrix m) {
    int countNonZero = 0;
    int total = m.rowEff * m.colEff;
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            if (m.mem[i][j] != 0) countNonZero++;
        }
    }
    return countNonZero <= (total * 5 / 100);
}

Matrix negation(Matrix m) {
    return multiplyByConst(m, -1);
}

void pNegation(Matrix *m) {
    pMultiplyByConst(m, -1);
}

float determinant(Matrix m) {
    if (m.rowEff == 1) return m.mem[0][0];
    if (m.rowEff == 2) {
        return m.mem[0][0]*m.mem[1][1] - m.mem[0][1]*m.mem[1][0];
    }
    float det = 0;
    for (int k = 0; k < m.colEff; k++) {
        Matrix minor;
        createMatrix(m.rowEff - 1, m.colEff - 1, &minor);
        for (int i = 1; i < m.rowEff; i++) {
            int colMinor = 0;
            for (int j = 0; j < m.colEff; j++) {
                if (j == k) continue;
                minor.mem[i-1][colMinor] = m.mem[i][j];
                colMinor++;
            }
        }
        float cofactor = ((k % 2 == 0) ? 1 : -1) * m.mem[0][k] * determinant(minor);
        det += cofactor;
    }
    return det;
}

Matrix transpose(Matrix m) {
    Matrix res;
    createMatrix(m.colEff, m.rowEff, &res);
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            res.mem[j][i] = m.mem[i][j];
        }
    }
    return res;
}

void pTranspose(Matrix *m) {
    Matrix temp = transpose(*m);
    *m = temp;
}

#endif