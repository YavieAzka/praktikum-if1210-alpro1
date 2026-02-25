/* File : matrix.h */
/* Deskripsi : Definisi ADT Matrix untuk representasi matriks dengan elemen float */
#ifndef MATRIX_H
#define MATRIX_H
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct
{
  float data[MAX_ROWS][MAX_COLS];
  int rows;
  int cols;
} Matrix;

/* Konstruktor */
void CreateMatrix(int rows, int cols, Matrix *M){
    M->rows = rows;
    M->cols = cols;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            M->data[i][j] = 0.0;
        }
    }
}
/* I.S. rows dan cols terdefinisi dan valid (1 <= rows,cols <= MAX) */
/* F.S. Terbentuk matrix M dengan ukuran rows x cols */
/* Semua elemen diinisialisasi dengan 0.0 */

/* Selector */
int GetRows(Matrix M){
    return M.rows;
}
/* Mengembalikan jumlah baris matrix M */

int GetCols(Matrix M){
    return M.cols;
}
/* Mengembalikan jumlah kolom matrix M */

float *GetElement(Matrix *M, int row, int col){
    if(row >= M->rows || col >= M->cols || row < 0 || col < 0){
        return NULL;
    }
    else{
        return &M->data[row][col];
    }
}
/* Mengembalikan pointer ke elemen matrix M pada baris row dan kolom col */
/* Mengembalikan NULL jika row atau col tidak valid untuk matrix M */

/* Mutator */
bool SetElement(Matrix *M, int row, int col, float value){
    if(row >= M->rows || col >= M->cols || row < 0 || col < 0){
        return false;
    }
    else{
        M->data[row][col] = value;
        return true;
    }
}
/* I.S. M terdefinisi */
/* F.S. Jika row dan col valid, elemen M pada baris row dan kolom col bernilai value, mengembalikan true */
/*      Jika row atau col tidak valid, mengembalikan false */

/* Operasi Baca/Tulis */
void ReadMatrix(Matrix *M){
    int col, row;
    scanf("%d %d", &row, &col);
    while(row >= MAX_ROWS || col >= MAX_COLS || row <= 0 || col <= 0){
        scanf("%d %d", &row, &col);
    }
    M->cols = col;
    M->rows = row;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%f", &M->data[i][j]);
        }
    }
}
/* I.S. M belum terdefinisi */
/* F.S. M terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input */
/*      Meminta input ukuran matrix (rows, cols) hingga valid
        Valid: 0 < rows < MAX_ROWS and 0 < cols < MAX_COLS */
/*      Meminta input elemen matrix M sebanyak rows * cols 
        Format input: Setiap elemen dipisahkan oleh spasi
        Contoh input: 
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
        Contoh input tidak valid:
        -1 -1
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
*/

void PrintMatrix(Matrix M){
    for(int i = 0; i < M.rows; i++){
        for(int j = 0; j < M.cols; j++){
            printf("%.2f ", M.data[i][j]);
        }
        printf("\n");
    }
}
/* I.S. M terdefinisi */
/* F.S. Seluruh elemen M tertulis ke layar dalam format matrix */
/* Baris dipisahkan oleh newline, kolom dipisahkan oleh spasi */
/* Format output: Setiap elemen diformat "%.2f" */

/* Operator Relasional */
bool IsSquare(Matrix M){
    return (M.cols - M.rows == 0);
}
/* Mengembalikan true jika M adalah matrix persegi (rows = cols) */

bool IsSymmetric(Matrix M){
    /*
    4 4
    1 3 5 9
    3 4 7 8
    5 7 1 4
    9 8 4 3
    */
    if(!IsSquare(M)){
        return false;
    }
    int col = 0;
    bool sym = true;
    while(col < M.cols){
        for(int j = col + 1; j < M.rows; j++){
            //printf("# %.2f %.2f\n", M.data[col][j] , M.data[j][col]);
            if(M.data[col][j] != M.data[j][col]){
                sym = false;
            }
        }
        col++;
    }
    return sym;
}
/* Mengembalikan true jika M adalah matrix simetrik terhadap diagonal */
/* Matrix simetrik adalah matrix yang memiliki elemen tercermin oleh diagonal*/
/* Prekondisi: M adalah matrix persegi */

bool IsDiagonallyDominant(Matrix M){

    for (int i = 0; i < M.rows; i++) {
        float diag = fabs(M.data[i][i]);  
        float sum = 0.0;
        for (int j = 0; j < M.cols; j++) {
            if (j != i) {
                sum += fabs(M.data[i][j]);  
            }
        }
        if (diag <= sum) {
            return false; 
        }
    }
    return true; 

}
/* Mengembalikan true jika M adalah matrix diagonal dominant */
/* |a[i][i]| > sum(|a[i][j]|) untuk j != i pada setiap baris i */
/* Hint: Gunakan fabs untuk melakukan abs terhadap float */

/* Operator Aritmatika */
Matrix *MultiplyMatrix(Matrix M1, Matrix M2){
    if (M1.cols != M2.rows) {
        return NULL;
    }
    Matrix *result = (Matrix *)malloc(sizeof(Matrix));
    if (result == NULL) {
        return NULL; 
    }
    result->rows = M1.rows;
    result->cols = M2.cols;

    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = 0;
        }
    }
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M2.cols; j++) {
            for (int k = 0; k < M1.cols; k++) {
                result->data[i][j] += M1.data[i][k] * M2.data[k][j];
            }
        }
    }

    return result;
}
/* Menghasilkan hasil perkalian matrix M1 dan M2 */
/* Mengembalikan NULL jika jumlah kolom M1 != jumlah baris M2 */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *AddMatrix(Matrix M1, Matrix M2){
    if(M1.cols == M2.cols && M1.rows == M2.rows){
        Matrix *result = (Matrix *)malloc(sizeof(Matrix));
        if (result == NULL) {
            return NULL; 
        }
        result->cols = M1.cols;
        result->rows = M2.rows;
        for(int i = 0; i < M1.rows; i++){
            for(int j = 0; j < M1.cols; j++){
                result->data[i][j] = M1.data[i][j] + M2.data[i][j];
            }
        }
        return result;
    }
    else{
        return NULL;
    }
   
}
/* Menghasilkan hasil penjumlahan matrix M1 dan M2 */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *SubtractMatrix(Matrix M1, Matrix M2){
    if(M1.cols == M2.cols && M1.rows == M2.rows){
        Matrix *result = (Matrix *)malloc(sizeof(Matrix));
        if (result == NULL) {
            return NULL; 
        }
        result->cols = M1.cols;
        result->rows = M2.rows;
        for(int i = 0; i < M1.rows; i++){
            for(int j = 0; j < M1.cols; j++){
                result->data[i][j] = M1.data[i][j] - M2.data[i][j];
            }
        }
        return result;
    }
    else{
        return NULL;
    }
   
}

/* Menghasilkan hasil pengurangan matrix M1 dan M2 (M1 - M2) */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix MultiplyScalar(Matrix M, float scalar){
    Matrix MM;
    MM.rows = M.rows;
    MM.cols = M.cols;
    for(int i = 0; i < M.rows; i++){
        for(int j = 0; j < M.cols; j++){
            MM.data[i][j] = M.data[i][j] * scalar;
        }
    }
    return MM;
}
/* Menghasilkan hasil perkalian matrix M dengan skalar scalar */
/* Prekondisi: M terdefinisi dan skalar terdefinisi */
/* Hint: Buat matrix baru untuk menyimpan hasil */

Matrix GetTranspose(Matrix M){
    /*
    2 3    3 2      
    1 2 3  1 4
    4 5 6  2 5
           3 6
    */
    Matrix MM;
    MM.cols = M.rows;
    MM.rows = M.cols;
    for(int i = 0; i < M.cols; i++){
        for(int j = 0; j < M.rows; j++){
            MM.data[i][j] = M.data[j][i];
        }
    }
    return MM;

}
/* Menghasilkan matrix transpose dari M */
/* Hint: Buat matrix baru untuk menyimpan hasil */

#endif



    //PrintMatrix(M);
    //SetElement(&M, 0, 2, 9);
    //float *val = GetElement(&M, 0, 2);
    //printf("-----\n");
    //PrintMatrix(M);
    
    /*
    2 3            
    1 2 3
    4 5 6
    
    4 4
    1 3 5 9
    3 4 7 8
    5 7 1 4
    9 8 4 3
    */
