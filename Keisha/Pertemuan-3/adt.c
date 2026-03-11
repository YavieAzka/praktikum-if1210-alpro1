#include <stdio.h>

typedef struct 
{
    char NIM[9];
    char Nama[32];
    float IPK;
    int semester;


} Mahasiswa;

// procedure
void printMahasiswa(Mahasiswa m) {
    printf("NIM: %s\n", m.NIM);
    printf("Nama: %s\n", m.Nama);
    printf("IPK: %.2f\n", m.IPK);
    printf("Semester: %d\n", m.semester);
}

void setNama(Mahasiswa *m, char *newNama) {
    strcpy(m->Nama, newNama);
}

int hitungSKS(Mahasiswa m) {
    return m.semester * 18;
}

int main(){
    Mahasiswa m1;
    strcpy(m1.NIM, "13524077");
    strcpy(m1.Nama, "Budi");
    m1.IPK = 3.75;
    m1.semester = 5;    
    
    // Pemanggilan procedure
    printMahasiswa(m1);

    // Pemanggilan function
    int totalSKS = hitungSKS(m1);

    // f(x) = y
    // hitungsks(m1) = totalSKS

    printf("Nama sebelum diubah: %s\n", m1.Nama);
    setNama(&m1, "Andi");
    printf("Nama setelah diubah: %s\n", m1.Nama);

    return 0;
}

