#include "ui.h"
#include "listlinier.h"
#include <stdio.h>

// Fungsi untuk dealokasi list
void dealokasiList(List *l) {
    Address p_current = FIRST(*l);
    Address p_next;

    while (p_current != NULL) {
        p_next = NEXT(p_current);
        free(p_current);
        p_current = p_next;
    }

    *l = NULL;
}

// Fungsi untuk insert secara terurut
void insertSorted(List *l, ElType val) {
    if (isEmpty(*l)) {
        insertLast(l, val);
    } else {
        for (int i = 0; i < length(*l); i++) {
            int x = getElmt(*l, i);
            if (x > val) {
                insertAt(l, val, i);
                return;
            }
        }
        insertLast(l, val);
    }
}

// Fungsi untuk mendapatkan union dari dua list
List getUnion(List l1, List l2) {
    List l3;
    CreateList(&l3);
    
    // Masukkan semua elemen dari l1 (tanpa duplikasi)
    for (int i = 0; i < length(l1); i++) {
        ElType val = getElmt(l1, i);
        if (indexOf(l3, val) == IDX_UNDEF) {
            insertSorted(&l3, val);
        }
    }
    
    // Masukkan elemen dari l2 yang belum ada di l3
    for (int j = 0; j < length(l2); j++) {
        ElType val = getElmt(l2, j);
        if (indexOf(l3, val) == IDX_UNDEF) {
            insertSorted(&l3, val);
        }
    }
    
    return l3;
}

// Fungsi untuk mendapatkan irisan dari dua list
List getIntersect(List l1, List l2) {
    List l3;
    CreateList(&l3);
    
    // Cari elemen yang ada di kedua list
    for (int i = 0; i < length(l1); i++) {
        ElType val = getElmt(l1, i);
        // Cek apakah elemen ada di l2 dan belum ada di l3
        if (indexOf(l2, val) != IDX_UNDEF && indexOf(l3, val) == IDX_UNDEF) {
            insertSorted(&l3, val);
        }
    }
    
    return l3;
}

// Fungsi utama untuk mengambil data dan menghitung union & irisan
void getData(List *Union, List *Irisan) {
    int n;
    scanf("%d", &n);
    
    CreateList(Union);
    CreateList(Irisan);
    
    for (int i = 0; i < n; i++) {
        List currentList;
        CreateList(&currentList);
        int size;
        scanf("%d", &size);
        
        // Baca data hari ke-i
        for (int j = 0; j < size; j++) {
            int x;
            scanf("%d", &x);
            insertLast(&currentList, x);
        }
        
        if (i == 0) {
            // Untuk hari pertama, copy ke Union dan Irisan
            for (int k = 0; k < length(currentList); k++) {
                ElType val = getElmt(currentList, k);
                if (indexOf(*Union, val) == IDX_UNDEF) {
                    insertSorted(Union, val);
                }
                if (indexOf(*Irisan, val) == IDX_UNDEF) {
                    insertSorted(Irisan, val);
                }
            }
        } else {
            // Untuk hari selanjutnya, hitung union dan irisan baru
            List newUnion = getUnion(*Union, currentList);
            List newIntersect = getIntersect(*Irisan, currentList);
            
            // Dealokasi list lama
            dealokasiList(Union);
            dealokasiList(Irisan);
            
            // Assign list baru
            *Union = newUnion;
            *Irisan = newIntersect;
        }
        
        // Dealokasi currentList
        dealokasiList(&currentList);
    }
}