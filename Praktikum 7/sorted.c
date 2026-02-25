#include <stdio.h>
#include "listkontigu.h"

int main(){
    int n;
    scanf("%d",&n);
    ListKontigu arr;
    CreateList(&arr);
    int input;
    int reversing =0, reversed = 0, srev = 0, erev = n-1;
    scanf("%d",&arr.contents[0]);
    for (int i = 1; i < n; i++)
    {
     scanf("%d",&input);
     arr.contents[i] =input;
     if (!reversing)
     {
        if (arr.contents[i] < arr.contents[i-1])
        {
            reversing =1;
            srev = i-1;
            reversed++;
        }
     }else{
        if (arr.contents[i] > arr.contents[i-1])
        {
            reversing =0;
            erev = i-1;
        }
     }
    }
    if (reversed ==0)
    {
        printf("YA\n");
    }else if (reversed == 1)
    {
        printf("YA\n");
        printf("%d %d\n",srev,erev);
    }else{
        printf("TIDAK\n");
    }
    
    
}
//  gcc sorted.c listkontigu.c -o sorted