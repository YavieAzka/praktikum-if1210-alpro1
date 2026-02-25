#include <stdio.h>

void sort(int arr[], int n) {
    //Bubble sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main(){
    /*
    int a[100000]; int t;
    int temp[100000];
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        temp[i] = a[i];
    }
    sort(a, n);
    scanf("%d", &t);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] + a[j] == t){
                int b = -1;
                int c = -1;
                for(int k = 0; k < n; k++){
                    if(temp[k] == a[i] && b == -1){
                        b = k;
                    }
                    else if(temp[k] == a[j] && c == -1){
                        c = k;
                    }
                }
                printf("[%d, %d]\n", b, c);
                return 0;
            }
        }
    }
    */
    int n; 
    scanf("%d", &n);
    int arr[10001];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);  
    }
    int k; scanf("%d", &k);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == k){
                printf("[%d, %d]\n", i, j);
                return 0;
            }
        }
    }
}