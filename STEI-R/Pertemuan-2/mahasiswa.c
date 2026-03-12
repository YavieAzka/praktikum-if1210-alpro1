#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[50];
    char NIM[8];
    int sks;
    float IPK;
    float IPS[14];
    int semester_now;
} Mahasiswa;

// Pass by value, jadi data mahasiswa yang asli tidak berubah
void printMahasiswa(Mahasiswa m){
    printf("Nama: %s\n", m.nama);
    printf("NIM: %s\n", m.NIM);
    printf("SKS: %d\n", m.sks);
    printf("IPK: %.2f\n", m.IPK);

    // testing pass by value
    m.sks = 100;
    // sks di main tidak berubah
}

// Pass by reference, jadi data mahasiswa yang asli bisa berubah
void updateSKS(Mahasiswa *m, int sks_baru){
    m->sks = sks_baru;
}

// TIPS: mengubah data di main: pass by reference
// TIPS: tidak mengubah (membaca, menghitung) data di main: pass by value

// fungsi untuk menambahkan IPK mahasiswa
float hitungIPK(Mahasiswa m){
    float totalIPS = 0;
    for(int i = 0; i < m.semester_now; i++){
        totalIPS += m.IPS[i];
    }
    float IPK_baru = totalIPS / m.semester_now;
    return IPK_baru;
}


int main(){
    Mahasiswa m1;

    // di C, mengisi tipe data string harus menggunakan strcpy(dest, source)
    strcpy(m1.nama, "Budi");
    strcpy(m1.NIM, "13524001");
    m1.sks = 40;
    m1.IPK = 3.8;
    m1.IPS[0] = 3.9;
    m1.IPS[1] = 3.7;
    m1.semester_now = 2;

    printMahasiswa(m1);

    Mahasiswa m2;
    strcpy(m2.nama, "Ani");
    strcpy(m2.NIM, "13524002");
    m2.sks = 40;
    m2.IPK = 3.9;
    m2.IPS[0] = 4.0;
    m2.IPS[1] = 3.8;
    m2.semester_now = 2;
    

    printf("\n");

    printMahasiswa(m2);
    
    m2.IPS[2] = 3.5;
    m2.semester_now = 3;
    updateSKS(&m2, 64);
    m2.IPK = hitungIPK(m2);
    printf("\nSetelah update IPS semester 3:\n");
    printMahasiswa(m2);
}