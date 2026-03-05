// Header 
#include <stdio.h>

int main(){
    // kita bakal ngoding disini (untuk sekarang)
    // program untuk menambahkan 2 bilangan dari input
    // bilangan1, bilangan2 -> bilangan1 + bilangan2
    // deklarasi variabel: <tipe_data> <nama_variabel>;
    int bilangan1;
    int bilangan2;

    // syntax untuk output string
    printf("Masukkan angka pertama: ");

    // syntax untuk input
    // scanf("<%d/%f/%c", &<nama_variabel>)
    /*
    %d : integer
    %f : float
    %c : character

    */
    // SETIAP TIPE DATA PRIMITIF PADA SCANF HARUS DIAWALI OLEH '&'
    scanf("%d",&bilangan1);

    printf("Masukkan angka kedua: ");
    scanf("%d", &bilangan2);

    float jumlah = bilangan1 / bilangan2;
    printf("Nilai bilangan1 / bilangan2 = \n");
    printf("%f", jumlah);


    // Operasi aritmatik:
    /*
    +, -, /, *
    mod (%) -> 7 mod 3 = 1

    div -> tidak ada, bisa diakali dengan menyatakan hasil sebagai int
    */

    return 0;
}