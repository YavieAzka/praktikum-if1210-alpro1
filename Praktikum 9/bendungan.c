#include <stdio.h>
#include "stack.h"
int main(){
    int n; 
    scanf("%d", &n);
    Stack s;
    CreateEmpty(&s);
    int sum = 0;
    int arr[1001];
    int val;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        while(!IsEmpty(s) && arr[i] > arr[InfoTop(s)]){
            Pop(&s, &val);
            if(IsEmpty(s)){
                break;
            }
            int d = i - InfoTop(s) - 1;
            int fill;
            if(arr[i] < arr[InfoTop(s)]){
                fill = arr[i];
            }
            else{
                fill = arr[InfoTop(s)];
            }
            fill -= arr[val];
            sum += d * fill;
        }
        Push(&s, i);
    }
    printf("%d\n", sum);
}