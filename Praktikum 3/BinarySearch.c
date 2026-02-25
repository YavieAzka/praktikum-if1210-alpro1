#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {

        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n, k; scanf("%d", &n);
    int fin[100001];
    if(n == 1){
        int y; 
        scanf("%d", &y);
        scanf("%d", &k);
        int x;
        for(int i = 0; i < k; i++){
            scanf("%d", &x);
            if(x == y){
                fin[i] = 0;
            }
            else{
                fin[i] = -1;
            }
            //printf("#%d, ", fin[i]);
        }
        printf("[%d", fin[0]);
        for(int i = 1; i < k; i++){
            printf(", %d", fin[i]);
        }
        printf("]\n");
    }
    else{
        int a[100001];
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        
        scanf("%d", &k);
        int qq[100001]; 
        int sz = 1;
        for(int i = 0; i < k; i++){
            int x; int ans;
            scanf("%d", &x);
            ans = binarySearch(a, 0, n, x);
            
            int temp; int id = ans;
            while(a[ans] == a[id]){
                id--;
            }
            fin[i] = id + 1;
            //printf("#%d\n", fin[i]);
        
        }
        printf("[%d", fin[0]);
        for(int i = 1; i < k; i++){
            printf(", %d", fin[i]);
        }
        printf("]\n");    
    }
    
}