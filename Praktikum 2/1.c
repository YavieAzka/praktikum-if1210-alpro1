#include <stdio.h>
#include <math.h>

double c_to_f(double z){
    double a = (z*9/5) + 32; 
    return a;
}
double c_to_k(double z){
    double a = z + 273.15; 
    return a;
}
double f_to_c(double z){
    double a = (z - 32);
    a = a * 5/9; 
    return a;
}
double f_to_k(double z){
    double a = ((z - 32)*5/9) + 273.15;
    return a;
}
double k_to_c(double z){
    double a = z - 273.15;
    return a;
}
double k_to_f(double z){
    double a = (z - 273.15);
    a = a * 9/5;
    a = a + 32;
    return a;
}
int main(){
    int n; 
    scanf("%d", &n);
    double arr[10000];
    for(int i = 0; i < n; i++){
        double x, t; char a, b;
        scanf("%lf %c %c", &x, &a, &b);
        //printf("%lf %c %c", x, a, b);
            if(a == 'C'){
                if(b == 'F') t = floor(c_to_f(x));
                if(b == 'K') t = floor(c_to_k(x));
            }
            if(a == 'F'){
                if(b == 'C') t = floor(f_to_c(x));
                if(b == 'K') t = floor(f_to_k(x));
            }
            if(a == 'K'){
                if(b == 'C') t = floor(k_to_c(x));
                if(b == 'F') t = floor(k_to_f(x));
            }
            arr[i] = t;
    }
    for(int i = 0; i < n; i++){
        printf("%.2f\n", arr[i]);
    }
}