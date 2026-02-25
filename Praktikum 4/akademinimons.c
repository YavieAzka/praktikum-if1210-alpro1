/**
 * Pengolahan Data para Nimons
 *
 * INPUT
 * sebuah nama file untuk dibaca.
 *
 * FORMAT FILE MASUKAN: (Asumsikan format input sudah pasti valid)
 *
 * NIM1|Nama1|Nilai1,Nilai2,Nilai3,...
 * NIM2|Nama2|Nilai1,Nilai2,Nilai3,...
 * ...
 * NIMN|NamaN|Nilai1,Nilai2,Nilai3,...
 *
 * NOTE:
 * - Panjang karakter NIM maksimal 20
 * - Panjang karakter Nama maksimal 100
 * - Panjang karakter Nilai maksimal 20
 * - Nilai dalam format integer
 *
 *
 * OUTPUT
 *
 * FORMAT KELUARAN PADA CONSOLE:
 *
 * NIM1|Nama1|Rata-rata|Tertinggi|Terendah|Status(newline)
 * NIM2|Nama2|Rata-rata|Tertinggi|Terendah|Status(newline)
 * ...(newline)
 * NIMN|NamaN|Rata-rata|Tertinggi|Terendah|Status(newline)
 * TotalNimons(newline)
 * JumlahLulus PesentaseLulus(newline)
 * JumlahTidakLulus PesentaseTidakLulus(newline)
 * NIMTertinggi|NamaTertinggi|Rata-rataTertinggi(newline)
 *
 * NOTE:
 * - Rata-rata ditulis dengan 2 angka di belakang koma
 * - Status dalam format "PASS" atau "FAIL"
 * - Persentase lulus dan tidak lulus ditulis dengan 2 angka di belakang koma
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IO_LENGTH 100    // Panjang maksimal nama file input/output
#define MAX_NAME_LENGTH 100  // Panjang maksimal nama
#define MAX_NIM_LENGTH 20    // Panjang maksimal NIM
#define MAX_LINE_LENGTH 1024 // Panjang maksimal satu baris
#define MAX_SCORES 20        // Maksimal jumlah nilai per nimon
#define MAX_NIMONS 100       // Maksimal jumlah nimons
#define PASS_THRESHOLD 60    // Ambang batas kelulusan (harus >= 60)


// Struktur data untuk menyimpan data nilai nimons dan juga beberapa statistiknya
typedef struct
{
  char nim[MAX_NIM_LENGTH];
  char name[MAX_NAME_LENGTH];
  int scores[MAX_SCORES];
  int scoreCount;
  float average;
  int highest;
  int lowest;
  char status[5]; // "PASS" or "FAIL"
} Nimon;

/**
 * Prosedur pembantu untuk melakukan parsing data nimons dari sebuah baris pada file input dalam format:
 *
 * NIM|Nama|Nilai1,Nilai2,Nilai3,...
 *
 * dan menyimpannya ke dalam struktur data Nimon.
 *
 * Hint:
 * 1. strtok - Memisahkan string berdasarkan delimiter
 *    Contoh:
 *    char str[] = "apple,banana,orange";
 *    char *token = strtok(str, ",");     // token = "apple"
 *    token = strtok(NULL, ",");          // token = "banana"
 *    token = strtok(NULL, ",");          // token = "orange"
 *
 *    Catatan: strtok mengubah string asli dengan menempatkan '\0'
 *    di tempat delimiter dan menyimpan posisi internal untuk
 *    pemanggilan berikutnya.
 *
 * 2. strcpy - Menyalin string dari sumber ke tujuan
 *    Contoh:
 *    char dest[20];
 *    char src[] = "Hello";
 *    strcpy(dest, src);  // dest sekarang berisi "Hello"
 *
 *    Catatan: Pastikan buffer tujuan cukup besar untuk
 *    menampung string sumber, termasuk null terminator.
 *
 * 3. atoi - Mengkonversi string menjadi nilai integer
 *    Contoh:
 *    char *num = "42";
 *    int value = atoi(num);  // value = 42
 *
 *    Catatan: atoi mengembalikan 0 jika konversi gagal.
 *
 * @line: baris yang berisi data nimons
 * @nimon: pointer ke struktur Nimon untuk menyimpan hasil parsing
 */
void parseStudentData(char *line, Nimon *nimon){
    char *token= strtok(line, "|");
    strcpy(nimon->nim, token);

    token = strtok(NULL, "|");
    strcpy(nimon->name, token);
    //printf("%s\n", nimon->name);

    token = strtok(NULL, "|");
    char *scoreToken = strtok(token, ",");
    nimon->scoreCount = 0;
    while(scoreToken != NULL){
        nimon->scores[nimon->scoreCount] = atoi(scoreToken);
        nimon->scoreCount++;
        //printf("%s\n", scoreToken);
        scoreToken = strtok(NULL, ",");
    }
    //calculateStatistics(nimon);
}

/**
 * Prosedur pembantu untuk menghitung statistik dari sebuah nimon
 * - Rata-rata
 * - Nilai tertinggi
 * - Nilai terendah
 * - Status (PASS/FAIL)
 *
 * @nimons: pointer ke struktur Nimon yang berisi data nimons
 */
void calculateStatistics(Nimon *nimon){
    // AVERAGE
    float sum = 0;
    int hi = -1;
    int lo = 9999;
    for(int i = 0; i < nimon->scoreCount; i++){
        sum += nimon->scores[i];
        if(nimon->scores[i] > hi){
            hi = nimon->scores[i];
        }
        if(nimon->scores[i] < lo){
            lo = nimon->scores[i];
        }
    }
    nimon->highest = hi;
    nimon->lowest = lo;
    nimon->average = sum/nimon->scoreCount;
    //printf("AVG: %.2f\n", nimon->average);
    //printf("Highest: %d\n", nimon->highest);60
    //printf("Lowest: %d\n", nimon->lowest);

    if(nimon->average >= 60){
        strcpy(nimon->status, "PASS");
    }
    else{
        strcpy(nimon->status, "FAIL");
    }
    //printf("Status: %s\n", nimon->status);

}

/**
 * Prosedur pembantu untuk menulis hasil nimons ke console dengan format:
 *
 * NIM|Nama|Rata-rata|Tertinggi|Terendah|Status(newline)
 *
 * NOTE:
 * - Rata rata ditulis dengan 2 angka di belakang koma
 * - status dalam format "PASS" atau "FAIL"
 * - Jangan lupa menambahkan newline di akhir setiap baris
 *
 * @nimon: pointer ke struktur Nimon yang berisi data nimons
 *
 */
void writeStudentResult(Nimon *nimon){
    printf("%s|%s|%.2f|%d|%d|%s\n", nimon->nim, nimon->name, nimon->average, nimon->highest, nimon->lowest, nimon->status);
}

/**
 * Prosedur pembantu untuk menghitung dan menulis ringkasan statistik kelas dalam format:
 *
 * TotalNimons(newline)
 * JumlahLulus PesentaseLulus(newline)
 * JumlahTidakLulus PesentaseTidakLulus(newline)
 * NIMTertinggi|NamaTertinggi|RataRataTertinggi(newline)
 *
 * NOTE:
 * - Persentase lulus dan tidak lulus ditulis dengan 2 angka di belakang koma
 * - Rata-rata tertinggi ditulis dengan 2 angka di belakang koma
 *
 * @nimons: array of Nimon structures
 * @nimonCount: jumlah nimons dalam array
 */
void writeSummary(Nimon *nimons, int nimonCount){
    int passCount = 0;
    int failCount = 0;
    float passPercent, failPercent;
    Nimon tensai;
    tensai.average = -1;
    for(int i = 0; i < nimonCount; i++){
        if(nimons[i].average >= 60){
            passCount++;
        }
        else{
            failCount++;
        }
        if(nimons[i].average > tensai.average){
            tensai = nimons[i];
        }
    }
    passPercent = (float)passCount/nimonCount * 100;
    failPercent = (float)failCount/nimonCount * 100;
    
    printf("%d\n", nimonCount);
    printf("%d %.2f%%\n", passCount, passPercent);
    printf("%d %.2f%%\n", failCount, failPercent);
    printf("%s|%s|%.2f\n", tensai.nim, tensai.name, tensai.average);
    //printf("Imba: %s\n", tensai.name);
}

/**
 * Fungsi utama akan membaca file input, memproses data nimons,
 * dan menampilkan hasilnya langsung ke console.
 *
 * NOTE: Gunakan fungsi-fungsi sebelumnya untuk mempermudah pengerjaan
 *
 * @inputFileName: nama file input
 * @return 0 jika berhasil, 1 jika gagal (misalnya file tidak ditemukan)
 */
int run(char *inputFileName) {
    FILE *inputFile;
    Nimon nimons[MAX_NIMONS];
    int nimonCount = 0;
    char line[MAX_LINE_LENGTH];
    
    inputFile = fopen(inputFileName, "r");
    
    if (inputFile == NULL) {
        return 1; // Mengembalikan kode error
    }
    

    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL && nimonCount < MAX_NIMONS) {
        // Menghapus newline di akhir baris jika ada
        line[strcspn(line, "\n")] = '\0';
        
        // Memproses data dari baris
        parseStudentData(line, &nimons[nimonCount]);
        
        // Menghitung statistik untuk nimon saat ini
        calculateStatistics(&nimons[nimonCount]);
        
        // Meningkatkan counter nimon
        nimonCount++;
    }
    
    // Menutup file setelah selesai dibaca
    fclose(inputFile);
    
    // Menampilkan hasil untuk setiap nimon
    for (int i = 0; i < nimonCount; i++) {
        writeStudentResult(&nimons[i]);
    }
    
    // Menampilkan ringkasan statistik
    writeSummary(nimons, nimonCount);
    
    return 0; // Operasi berhasil
}



/**
 * driver.c
 *
 * Contoh cara pengujian program untuk praktikan
 *
 * NOTE:
 * - Cara compile:
 *   - gcc akademinimons.c driver.c -o akademinimons
 *   - Harus compile driver.c dan juga implementasi akademinimons.c
 * - Cara run:
 *  - Jalankan ./akademinimons
 *  - Masukkan nama/path file input (bisa relative path). Misalnya "input.txt"
 */

/*
int main()
{
    char inputFileName[MAX_IO_LENGTH];

    // Input nama file input
    scanf("%s", inputFileName);
  
    // Jalankan program
    int result = run(inputFileName);
  
    return result;
}
*/