#ifndef KALKULUS_H
#define KALKULUS_H

#include "Boolean.h"
#include "matrix.h"

Matrix dilate(Matrix v, int scale){
    Matrix R;
    createMatrix(v.rowEff, v.colEff, &R);
    for(int i = 0; i < v.rowEff; i++){
        for(int j = 0; j < v.colEff; j++){
            R.mem[i][j] = v.mem[i][j] * scale;
        }
    }
    return R;
}
/* Setiap titik (x, y) menjadi (x*scale, y*scale) */

Matrix translate(Matrix v, int dx, int dy){
    Matrix R;
    createMatrix(v.rowEff, v.colEff, &R);
    for(int i = 0; i < v.rowEff; i++){
        for(int j = 0; j < v.colEff; j++){
            if(v.mem[i][j] == 0){
                R.mem[i][j] = v.mem[i][j] + dx;
            }
            else{
                R.mem[i][j] = v.mem[i][j] + dy;
            }
        }
    }
    return R;
}
/* Setiap titik (x, y) menjadi (x+dx, y+dy) */

Matrix reflect(Matrix v, char axis){
    Matrix R;
    createMatrix(v.rowEff, v.colEff, &R);
    if(axis == 'y'){
        for(int i = 0; i < v.rowEff; i++){
            for(int j = 0; j < v.colEff; j++){
                if(j == 0){
                    R.mem[i][j] = v.mem[i][j] * -1;
                }
                else{
                    R.mem[i][j] = v.mem[i][j];
                }
            }
        }
    }
    if(axis == 'x'){
        for(int i = 0; i < v.rowEff; i++){
            for(int j = 0; j < v.colEff; j++){
                if(j == 1){
                    R.mem[i][j] = v.mem[i][j] * -1;
                }
                else{
                    R.mem[i][j] = v.mem[i][j];
                }
            }
        }
    return R;
    }
}   
/* 'x' → y = -y, 'y' → x = -x */

Matrix rotate(Matrix v, int degree){
    Matrix R;
    createMatrix(v.rowEff, v.colEff, &R);
    int sin, cos;
    if(degree == 0){
        sin = 0;
        cos = 1;
    }
    if(degree == 90){
        sin = 1;
        cos = 0;
    }
    if(degree == 180){
        sin = 0;
        cos = -1;
    }
    if(degree == 270){
        sin = -1;
        cos = 0;
    }
    for(int i = 0; i < v.rowEff; i++){
        for(int j = 0; j < v.colEff; j++){
            if(j == 0){
                R.mem[i][j] = v.mem[i][0] * cos + v.mem[i][1] * sin;
            }
            if(j == 1){
                R.mem[i][j] = (v.mem[i][0] * -1) * sin + v.mem[i][1] * cos;
            }
        }
    }
    return R;
}
/* Memutar setiap titik (x, y) sebesar degree derajat searah jarum jam dari (0,0) */
/* Gunakan rumus rotasi:
   x' = x * cosθ + y * sinθ
   y' = -x * sinθ + y * cosθ
   degree hanya 0, 90, 180, 270 (bisa pakai konstanta tanpa trigonometri float) */
/* cos0 = 1, sin0 = 0*/
/* cos90 = 0, sin90 = 1*/
/* cos180 = -1, sin180 = 0*/
/* cos270 = 0, sin270 = -1*/
/* DEGREE SUDAH PASTI 4 JENIS, HARDCODE SAJA, TIDAK PERLU PAKE <math.h> */

#endif