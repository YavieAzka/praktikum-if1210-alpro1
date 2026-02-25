#include <stdio.h>
#include "queue.h"
int main(){
    int n;
    scanf("%d", &n);
    Queue q;
    CreateQueue(&q);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n-i-1;j++){
            if(q.buffer[j]<q.buffer[j+1]){
                int temp = q.buffer[j];
                q.buffer[j]= q.buffer[j+1];
                q.buffer[j+1]= temp;
            }
        }
    }
    displayQueue(q);
    q.idxHead = q.buffer[0];
    q.idxTail = q.buffer[n-1];
    return 0;
}