#include <stdio.h>

int main(){
    // int nilai = 60;
    // if (nilai >= 75) printf("Selamat, Anda Lulus!\n");
    // printf("Selesai");
    // Cetak angka 1 sampai 5
    // for(<komponen_1>;<komponen_2>;<komponen_3>)
    /*
    komponen_1: inisialisasi variabel
    komponen_2: batas
    komponen_3: increment/decrement
    increment:
    i++ -> i = i + 1
    i-- -> i = i - 1
    i+=2 -> i = i + 2
    */
    // menjumlahkan bilangan dari 1 -> 100
    // int jumlah = 0;
    for (int i = 1; i <= 10; i++) {
        // break: for loop akan d
        if(i == 5){
            break;
        }

        printf("%d\n", i);
    }
    printf("========CONTINUE========\n");
    for (int i = 1; i <= 10; i++) {
        // continue: for loop akan dihentikan di keadaan ini, dan dilanjutkan di keadaan selanjutnya
        if(i == 5){
            continue;
        }

        printf("%d\n", i);
    }
    // //printf("Jumlah: %d", jumlah);

    // int nilai = 85;

    
    // if (nilai >= 75) {
    //     printf("Selamat, Anda Lulus!\n");
    // }


    

    // for (int i = 1; i <= 5; i++) {
    //     printf("Angka: %d\n", i);
    // }
    int i = 6;

    // while (i <= 5) {
    //     printf("Angka: %d\n", i);
    //     i++; // Jangan lupa increment agar tidak infinite loop!
    // }

    // do {
    //     printf("Angka: %d\n", i);
    //     i++;
    // } while (i <= 5);
    // printf("Selesai\n");

    /*
    Kapan harus menggunakan for/while?
    For -> tahu berapa banyak/berapa kali blok program akan diulang
    cth: 
    - jumlahin 100 bilangan dari 1 -> 100
    - traversal array yang kita tahu sizenya : looping dari 0 -> size - 1

    While -> kita hanya tahu bagaimana kejadian berhentinya
    - traversal array yang kita gatau sizenya : while(i < size(array))
    - mencari faktor bilangan -> kita gatau berapa kali harus mencari faktornya, tapi kita tau harus berhenti ketika nilai = 1
    cth: 
    1. faktor dari 10
    - 10 : 2 = 5
    - 5 : 5 = 1
    2. faktor dari 24
    - 24 : 2 = 12
    - 12 : 2 = 6
    - 6 : 2 = 3
    - 3 : 3 = 1

    NOTES: semua for loop bisa direpresentasikan sebagai while
    */
}