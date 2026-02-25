#include <stdio.h>
#include "queue.h"

void prioritizeValue(Queue *q, int x){
    Queue prio, notprio;
    int v;
    CreateQueue(&prio);
    CreateQueue(&notprio);
    int id = 0;
    while(id <= q->idxTail){
        //printf("#%d", q->buffer[id]);
        if(q->buffer[id] == x){
            enqueue(&prio, q->buffer[id]);
        }
        else{
            enqueue(&notprio, q->buffer[id]);
        }
        //dequeue(&(*q), &v);
        id++;
    }
    while(!isEmpty(*q)){
        dequeue(q, &v);
    }
    while(!isEmpty(prio)){
        dequeue(&prio, &v);
        enqueue(q, v);
    }
    while(!isEmpty(notprio)){
        dequeue(&notprio, &v);
        enqueue(q, v);
    }
    
    //q->idxHead = 0;
    //q->idxTail = n-1;
}

