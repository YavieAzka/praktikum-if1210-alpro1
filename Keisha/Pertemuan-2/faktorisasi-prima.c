#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int faktor = 2;
    int pangkat = 0;

    int start = 0;
    while(n > 1){
        while(n % faktor == 0){
            n = n/faktor;
            pangkat++;
        }

        if(pangkat != 0){
            if(pangkat == 1){
                if(start == 0){
                    printf("%d ", faktor);
                    start++;
                }
                else{
                    printf("* %d ", faktor);
                }
                
            }
            else{
                if(start == 0){
                    printf("%d^%d ", faktor, pangkat);
                    start++;
                }
                else{
                    printf("* %d^%d ", faktor, pangkat);
                }
                
            }
            
        } 

        faktor++;
        pangkat = 0;

        
    }
    printf("\n");
}