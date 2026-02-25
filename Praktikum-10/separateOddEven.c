#include "listlinier.h"
#include "separateOddEven.h"
#include "stdio.h"

void separateOddEven(List *l)
{
  /* I.S. l terdefinisi, mungkin kosong */
  /* F.S. List l diatur ulang sehingga semua bilangan ganjil muncul sebelum bilangan genap */
  /*      dengan mempertahankan urutan relatif dalam setiap kelompok */
  int j = 0;
  for(int i = 0; i < length(*l); i++){
        
        int val2;
        int x;
        x = getElmt(*l, i);
        //printf("%d\n", x);
        if(x % 2 == 1){
            deleteAt(l, i, &val2);
            insertAt(l, val2, j);
            

            j++;
        }
        
    }


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
//     separateOddEven(&l);
    
// }