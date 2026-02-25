#include <stdio.h>
int main(){
    int n, t, x;
    scanf("%d", &n);
    scanf("%d", &t);
    scanf("%d", &x);
    //printf("%d %d %d", n, t, x);
    long now = n;
    long dec = 0;
    for(int i = 1; i <= t; i++){
        long temp = (now - dec) * x;
        dec = now;
        now += temp;  
    }
    printf("Terdapat %ld Virus Nimons Gila pada jam ke-%ld\n", now, t);
}