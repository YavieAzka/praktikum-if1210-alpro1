
#include "GnomeTracker.h"

int main() {
    GnomeTrack Tracker;
    Gnome tempGnome;
    
    // 1. Inisialisasi
    printf("--- INISIALISASI TRACKER ---\n");
    createTracker(&Tracker);
    if (isEmpty(Tracker)) {
        printf("Tracker berhasil dibuat dan masih kosong!\n\n");
    }

    // 2. Pembuatan Data Gnome
    Gnome g1 = {1, "Gimli", 1.25, "builder", true};
    Gnome g2 = {2, "Smigol", 0.95, "thief", false};
    Gnome g3 = {3, "Gandalf", 1.85, "leader", true};
    Gnome g4 = {4, "Goblin", 1.00, "forest", false};
    Gnome g5 = {5, "Frodo", 1.15, "forest", true};

    // 3. Uji Insert (InsertFirst, InsertLast, InsertAt)
    printf("--- UJI INSERT DATA ---\n");
    insertFirst(&Tracker, g1);        // Tracker: [g1]
    insertLast(&Tracker, g2);         // Tracker: [g1, g2]
    insertFirst(&Tracker, g3);        // Tracker: [g3, g1, g2]
    insertAt(&Tracker, g4, 2);        // Tracker: [g3, g1, g4, g2]
    insertLast(&Tracker, g5);         // Tracker: [g3, g1, g4, g2, g5]
    
    printf("Total Gnome saat ini: %d\n\n", length(Tracker));

    // 4. Menampilkan Seluruh Gnome
    printf("--- SELURUH GNOME DALAM TRACKER ---\n");
    printAllGnome(Tracker);
    printf("\n");

    // 5. Uji Filter
    printf("--- FILTER: TINGGI >= 1.20 ---\n");
    filterByHeight(Tracker, 1.20);
    printf("\n");

    printf("--- FILTER: TIPE 'forest' ---\n");
    filterByType(Tracker, "forest");
    printf("\n");

    // 6. Uji Cari Indeks
    printf("--- UJI PENCARIAN (indexOf) ---\n");
    int searchId = 4;
    IdxType foundIdx = indexOf(Tracker, searchId);
    if (foundIdx != IDX_UNDEF) {
        printf("Gnome dengan ID %d ditemukan pada indeks %d\n\n", searchId, foundIdx);
    }

    // 7. Uji Delete Unfriendly
    printf("--- PURGE GNOME BERBAHAYA (Delete Unfriendly) ---\n");
    deleteUnfriendly(&Tracker);
    printf("\n");

    // 8. Cek Sisa Gnome
    printf("--- SISA GNOME SETELAH PURGE ---\n");
    printAllGnome(Tracker);
    printf("\n");

    // 9. Uji Delete Standar (DeleteFirst)
    printf("--- UJI DELETE FIRST ---\n");
    deleteFirst(&Tracker, &tempGnome);
    printf("Terhapus: %s (ID: %d)\n", tempGnome.name, tempGnome.id);
    printAllGnome(Tracker);

    return 0;
}