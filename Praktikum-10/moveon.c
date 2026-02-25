#include "listlinier.h"
#include "moveon.h"
#include <stdio.h>


/*
 * Fungsi : removeAll
 * -------------------
 * Menghapus semua elemen dalam list yang memiliki nilai info sama dengan 'val'.
 *
 * Parameter:
 *  - l   : pointer ke list yang akan dimodifikasi
 *  - val : nilai elemen yang ingin dihapus dari list
 *
 * Deskripsi:
 *  - Fungsi ini melakukan traversal pada list l dan menghapus semua node
 *    yang memiliki nilai INFO(node) == val.
 *  - Penghapusan dilakukan dengan benar, termasuk menangani kasus:
 *      - Node yang dihapus berada di awal list
 *      - Node yang dihapus berada di tengah list
 *      - Node yang dihapus berada di akhir list
 *  - Setelah node dihapus, memori dari node tersebut harus di-dealokasi (menggunakan free).
 *
 * Aturan:
 *  - Tidak boleh menggunakan array tambahan, struktur data lain, atau rekursi.
 *  - Hanya boleh menggunakan operasi pointer dan fungsi dari ADT listlinier.h
 *  - Tidak memodifikasi nilai dari node lain, hanya menghapus node yang sesuai.
 *
 * Contoh:
 *  - Jika list l = [1, 2, \, 3, 2, 4] dan val = 2,
 *    maka setelah removeAll(&l, 2), list menjadi [1, 3, 4]
 */
void removeAll(List *l, ElType val){
    int val2;
    for(int i = 0; i < length(*l); i++){
        int x;
        x = getElmt(*l, i);
        //printf("%d\n", x);
        if(x == val){
            deleteAt(l, i, &val2);
            i--;
        }
    }
    displayList(*l);
    printf("\n");   
}



// int main(){
//     int n;
//     scanf("%d", &n);
//     List l;
//     CreateList(&l);
//     for(int i = 0; i < n; i++){
//         int x; scanf("%d", &x);
//         insertLast(&l, x);
//     }
//     int k;
//     scanf("%d", &k);
//     removeAll(&l, k);
// }