#include <stdio.h>
#include "listkontigu.h"

int main(){
    int n;
    scanf("%d",&n);
    int cursize =0;
    ListKontigu arr;
    CreateList(&arr);
    int input;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&input);
        for (int j = 0; j <= cursize && cursize<n ; j++)
        {
            if (arr.contents[j] == MARK)
            {
                insertLast(&arr, input);
                cursize++;
                break;
            }
            if (input < arr.contents[j])
            {
                int val = 0;
                insertAt(&arr,input,j);
                cursize++;
                break;
            }
        }
        printList(arr);
        printf("\n");
    }    
}
// gcc Schedule.c listkontigu.c -o jadwal
