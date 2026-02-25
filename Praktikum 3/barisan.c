#include <stdio.h>
#define nl printf("\n");
#define ll long long
int gcd(int a, int b){ 
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }   
}

int main(){
    ll n; scanf("%lld", &n);
    if(n == 0){
        printf("%d\n", 0);
        return 0;
    }
    ll arr[1000];
    ll m;
    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    if(n == 1){
        printf("%lld\n", arr[0]*arr[0]);
        return 0;
    }
    ll prefGCD[1000], prefLCM[1000];
    ll sufGCD[1000], sufLCM[1000];
    prefGCD[0] = arr[0]; prefLCM[0] = arr[0];
    sufGCD[n - 1] = arr[n - 1]; sufLCM[n - 1] = arr[n - 1];
    for(int i = 1; i < n; i++){
        prefGCD[i] = gcd(prefGCD[i - 1], arr[i]);
        prefLCM[i] = (arr[i]*prefLCM[i - 1])/gcd(arr[i],prefLCM[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--){
        sufGCD[i] = gcd(sufGCD[i + 1], arr[i]);
        sufLCM[i] = (arr[i]*sufLCM[i + 1])/gcd(arr[i],sufLCM[i + 1]);
    }
    ll fpb = prefGCD[n - 1];
    ll kpk = prefLCM[n - 1];
    ll out = kpk*fpb;
    for(int i = 0; i < n; i++){
        if(i == 0){
            fpb = sufGCD[1];
            kpk = sufLCM[1];
        }
        else if(i == n - 1){
            fpb = prefGCD[n - 2];
            kpk = prefLCM[n - 2];
        }
        else{
            fpb = gcd(prefGCD[i - 1], sufGCD[i + 1]);
            kpk = (prefLCM[i - 1]*sufLCM[i + 1])/gcd(prefLCM[i - 1],sufLCM[i + 1]);
        }
        
        if(fpb*kpk > out){
            out = fpb*kpk;
        }
        
    }
    printf("%lld\n", out);
    
    // 4 6 8 3 5
    // LCM = 120
// L[]=3 15 30 120 120
// delete 6: 3 5 | 8 12
//         = lcm[1],
}