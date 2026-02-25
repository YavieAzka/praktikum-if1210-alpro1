#include <stdio.h>

int main(){
    int a, b, c, x, y, z, p, q, r;
    scanf("%d %d %d", &a,&b,&c);
    scanf("%d %d %d", &x,&y,&z);
    p = x - a; q = y - b; r = z - c;
    printf("%d %d %d\n", p, q, r);

    return 0;
}