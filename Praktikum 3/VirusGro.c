#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Alokasi memori untuk array afinitas
    long long *a = (long long*)malloc(n * sizeof(long long));
    if (a == NULL) return 1;
    
    // Baca nilai afinitas
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    long long result = LLONG_MIN;
    
    // Untuk setiap kemungkinan rumah terakhir
    for (int last = 0; last < n; last++) {
        // Untuk setiap jumlah titik awal d (1 ≤ d ≤ k)
        for (int d = 1; d <= k && d < n; d++) {
            // Buat array untuk menyimpan nilai rumah selain rumah terakhir
            long long *others = (long long*)malloc((n-1) * sizeof(long long));
            if (others == NULL) {
                free(a);
                return 1;
            }
            
            // Salin nilai rumah selain rumah terakhir
            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (i != last) {
                    others[idx++] = a[i];
                }
            }
            
            // Ambil d nilai tertinggi tanpa menggunakan pengurutan penuh
            long long sum = a[last]; // Nilai rumah terakhir
            
            for (int count = 0; count < d; count++) {
                // Temukan nilai terbesar di array others
                long long maxVal = LLONG_MIN;
                int maxIdx = -1;
                
                for (int i = 0; i < n-1; i++) {
                    if (others[i] > maxVal) {
                        maxVal = others[i];
                        maxIdx = i;
                    }
                }
                
                if (maxIdx != -1) {
                    sum += maxVal;
                    // Tandai nilai yang sudah digunakan dengan menetapkan nilai minimum
                    others[maxIdx] = LLONG_MIN;
                }
            }
            
            if (sum > result) {
                result = sum;
            }
            
            free(others);
        }
    }
    
    printf("%lld\n", result);
    
    free(a);
    return 0;
}