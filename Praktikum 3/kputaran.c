#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[10001], temp[10001];
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            arr[i] = x;
            temp[i] = x;
    }
    if(k == 0){
        printf("%d", arr[0]);
        for(int k = 1; k < n; k++){
            printf(" %d", arr[k]);
        }
        printf("\n");
        return 0;
    }
    for(int i = 0; i < k; i++){
        int mov = 1;
        int id = 0;
        for(int j = 0; j < n; j++){
            int now = (j + 1) % n;
            arr[now] = temp[id];
            id++;
        }
        //copy
        for(int j = 0; j < n; j++){
            temp[j] = arr[j];
        }      
    }
    printf("%d", arr[0]);
    for(int k = 1; k < n; k++){
        printf(" %d", arr[k]);
    }
    printf("\n");
    return 0;
    return 0;

}