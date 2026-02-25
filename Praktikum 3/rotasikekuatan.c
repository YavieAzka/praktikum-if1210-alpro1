#include <stdio.h>
int main(){
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int arr[1000]; int temp[1000];
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        arr[i] = x;
        temp[i] = x;
    }
    int inp[100];
    for(int i = 0; i < k; i++){
        scanf("%d", &inp[i]);
    }
    int otp[100];
    for(int i = 0; i < k; i++){
        int mov = inp[i];
        int id = 0;
        for(int j = 0; j < n; j++){
            int now = (j + mov) % n;
            arr[now] = temp[id];
            id++;
        }
        //copy
        printf("[%d", arr[0]);
        for(int k = 1; k < n; k++){
            printf(", %d", arr[k]);
        }
        printf("]", arr[0]);
        printf("\n");
    }
    
}
/*
1 2 3 4
#1
[4, 1, 2, 3]
*/