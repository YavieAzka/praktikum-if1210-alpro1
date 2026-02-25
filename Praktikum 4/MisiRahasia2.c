#include <stdio.h>
#include <stdlib.h>
#include "tester.h"
typedef struct MisiRahasia2
{
    int id;
    int success;
    int value;
} nimons;


void sortbubble(nimons arr[], int n){
    if(n > 1){
        int pass = 1 ;
        int tukar = 1 ;
        while(pass <= n-1 && tukar == 1){
            tukar = 0 ;
            for(int i = n-1 ; i > pass-1 ; i--){
                if(arr[i].success < arr[i-1].success){
                    int temp = arr[i].success;
                    arr[i].success = arr[i-1].success;
                    arr[i-1].success = temp;
                    tukar = 1 ;
                }
                else if(arr[i].success == arr[i-1].success){
                    int temp;
                    if(arr[i].value < arr[i-1].value)
                        temp = arr[i].value;
                        arr[i].value = arr[i-1].value;
                        arr[i-1].value = temp;
                        tukar = 1 ;
                    if(arr[i].value == arr[i-1].value){
                        if(arr[i].id < arr[i-1].id)
                        temp = arr[i].id;
                        arr[i].id = arr[i-1].id;
                        arr[i-1].id = temp;
                        tukar = 1 ;
                    }
                }
            }
            pass++ ;
        } 
    }
}

void sortselectionSuccess(nimons arr[], int n){
    if(n > 1){
        for(int i = 0 ; i < n-1 ; i++){
            int Imin = i ;
            // Mencari minimum pada array [j..n-1]
            for(int j = i+1 ; j < n ; j++){
                if(arr[Imin].success > arr[j].success ){
                    Imin = j ;
                }
                // berdasarkan value   
            }

            // Tukar arr[i] dengan arr[Imin]
            nimons temp = arr[Imin] ;
            arr[Imin] = arr[i] ;
            arr[i] = temp ;
        }
    }
}

void sortselectionValue(nimons arr[], int n){
    if(n > 1){
        for(int i = 0 ; i < n-1 ; i++){
            int Imin = i ;
            // Mencari minimum pada array [j..n-1]
            for(int j = i+1 ; j < n ; j++){
                if(arr[Imin].value > arr[j].value && (arr[Imin].success == arr[j].success)){
                    Imin = j ;
                }
                // berdasarkan value   
            }

            // Tukar arr[i] dengan arr[Imin]
            nimons temp = arr[Imin] ;
            arr[Imin] = arr[i] ;
            arr[i] = temp ;
        }
    }
}

void sortselectionId(nimons arr[], int n){
    if(n > 1){
        for(int i = 0 ; i < n-1 ; i++){
            int Imin = i ;
            // Mencari minimum pada array [j..n-1]
            for(int j = i+1 ; j < n ; j++){
                if(arr[Imin].id > arr[j].id && (arr[Imin].value == arr[j].value) && (arr[Imin].success == arr[j].success)){
                    Imin = j ;
                }
                // berdasarkan value   
            }

            // Tukar arr[i] dengan arr[Imin]
            nimons temp = arr[Imin] ;
            arr[Imin] = arr[i] ;
            arr[i] = temp ;
        }
    }
}

int main(){
    init();
    FILE *f = fopen("input.txt", "r");
    nimons n;
    nimons arr2[1002];
    fscanf(f, "%d %d %d", &n.id, &n.success, &n.value);
    int idx = 0;
    while(n.id != -1){
        arr2[idx] = n;
        idx++;
        fscanf(f, "%d %d %d", &n.id, &n.success, &n.value);
    }
    sortselectionSuccess(arr2, idx);
    sortselectionValue(arr2, idx);
    sortselectionId(arr2, idx);
    FILE *out = fopen("query.txt", "r");
    for(int i = 0; i < idx; i++){
        //printf("%d %d %d\n", arr2[i].id, arr2[i].success, arr2[i].value);
    }
    int nq;
    fscanf(out, "%d", &nq);
    //printf("%d",nq);
    for(int i = 0; i < nq; i++){
        int q;
        fscanf(out, "%d", &q);
        printf("%d %d\n", arr2[q - 1].id, arr2[q - 1].value);
    }

    

}   