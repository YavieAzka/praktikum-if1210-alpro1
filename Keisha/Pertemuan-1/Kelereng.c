#include <stdio.h>

int main(){
    int m; // 1000
    int h; // 1500
    int k; // 2000

    // scanf("%d", &m);
    // scanf("%d", &h);
    // scanf("%d", &k);

    /*
    ^ format input:
    1
    1
    1
    */ 

    // bagaimana jika format inputnya:
    // 1 1 1
    scanf("%d %d %d", &m, &h, &k);

    int jumlah = (m * 1000) + (h * 1500) + (k * 2000);
    printf("%d", jumlah);
}