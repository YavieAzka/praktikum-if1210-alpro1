#include <stdio.h>
#include "stack.h"
int main(){
    int n;
    scanf("%d", &n);
    int arr[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        
        for(int j = i; j < n; j++){
            int max = -1;
            for(int k = i; k <= j; k++){
                if(arr[k] > max){
                    max = arr[k];
                }
            }
            sum += max;
        }


    }
    printf("%d\n", sum);
}