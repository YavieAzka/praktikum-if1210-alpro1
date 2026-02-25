#include <stdio.h>
#include <stdbool.h>
#include "liststatik.h"
#include "Boolean.h"



int main() {
   ListStatik gudangPisang;
   CreateListStatik(&gudangPisang);
   
   int perintah;
   while (1) {
      scanf("%d", &perintah);
      
      if (perintah == -1) {
         break; // Keluar dari loop jika input -1
      } else if (perintah == 1) {
         // Insert pisang
         int berat, indeks;
         scanf("%d %d", &berat, &indeks);
         
         // Cek apakah aksi valid (list belum penuh dan indeks valid)
         if (isFull(gudangPisang) || !isIdxValid(gudangPisang, indeks) || 
             (indeks > getLastIdx(gudangPisang) + 1 && !isEmpty(gudangPisang)) || 
             (isEmpty(gudangPisang) && indeks != 0)) {
            printf("Aw, gabisa ngelakuin aksi itu\n");
            printList(gudangPisang);
            printf("\n");
         } else {
            // Insert berat pisang ke indeks
            if (isEmpty(gudangPisang)) {
               gudangPisang.contents[0] = berat;
            } else {
               // Geser elemen-elemen setelah indeks
               for (int i = getLastIdx(gudangPisang) + 1; i > indeks; i--) {
                  gudangPisang.contents[i] = gudangPisang.contents[i-1];
               }
               gudangPisang.contents[indeks] = berat;
            }
            printList(gudangPisang);
            printf("\n");
         }
      } else if (perintah == 0) {
         // Delete pisang
         int indeks;
         scanf("%d", &indeks);
         
         // Cek apakah aksi valid (list tidak kosong dan indeks valid)
         if (isEmpty(gudangPisang) || !isIdxEff(gudangPisang, indeks)) {
            printf("Aw, gabisa ngelakuin aksi itu\n");
            printList(gudangPisang);
            printf("\n");
         } else {
            int val;
            // Hapus pisang di indeks
            deleteAt(&gudangPisang, &val, indeks);
            printList(gudangPisang);
            printf("\n");
         }
      }
   }
   
   return 0;
}