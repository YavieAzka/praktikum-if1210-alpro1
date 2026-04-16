
#include "ListStatik.h"

int main() {
    TabInt T1, T2, T3;
    
    // 1. Uji Konstruktor
    printf("--- UJI KONSTRUKTOR ---\n");
    MakeEmptyList(&T1);
    MakeEmptyList(&T2);
    
    if (IsEmpty(T1)) {
        printf("T1 berhasil dibuat dan kosong.\n");
    }

    // 2. Mengisi List T1 dan T2
    printf("\n--- MENGISI LIST ---\n");
    // Karena tidak ada fungsi khusus Insert, kita gunakan SetEl dan SetNeff
    for (int i = 1; i <= 3; i++) {
        SetEl(&T1, i, i * 10); // T1: [10, 20, 30]
        SetEl(&T2, i, i * 5);  // T2: [5, 10, 15]
    }
    SetNeff(&T1, 3);
    SetNeff(&T2, 3);

    printf("Isi T1: ");
    ShowAll(T1);
    printf("\n");

    printf("Isi T2: ");
    ShowAll(T2);
    printf("\n");

    // 3. Uji Selektor dan Properti
    printf("\n--- UJI SELEKTOR ---\n");
    printf("Panjang T1: %d\n", Length(T1));
    printf("Kapasitas Maksimal: %d\n", MaxNbEl(T1));
    printf("Elemen pertama T1: %d\n", GetElmtAt(T1, GetFirstIdx(T1)));

    // 4. Uji Operator Aritmatika
    printf("\n--- UJI ARITMATIKA (T1 + T2) ---\n");
    T3 = PlusTab(T1, T2);
    printf("Hasil T1 + T2: ");
    ShowAll(T3);
    printf("\n");

    printf("Hasil T1 - T2: ");
    TabInt T_Minus = MinusTab(T1, T2);
    ShowAll(T_Minus);
    printf("\n");

    // 5. Uji Nilai Ekstrem (Hanya menguji fungsi pemanggilan)
    printf("\n--- UJI NILAI EKSTREM ---\n");
    printf("Nilai Max di T1: %d\n", ValMax(T1));
    printf("Nilai Min di T1: %d\n", ValMin(T1));

    // 6. Uji Penggabungan Tabel (Concat)
    printf("\n--- UJI CONCAT (T1 & T2) ---\n");
    TabInt T_Concat = ConcatTable(T1, T2);
    printf("Hasil Concat T1 dan T2: ");
    ShowAll(T_Concat);
    printf("\n");

    return 0;
}