#include <stdio.h>
#include <string.h>

void alf(){

}

int main(){
    char s[1001];
    char alfa[26] = "abcdefghijklmnopqrstuvwxyz";
    int alfanum[26];
    for(int i = 0; i < 26; i++){
        alfanum[i] = 0;
    }
    scanf("%s", s);
    int l = strlen(s);
    for(int i = 0; i < l; i++){
        char c = s[i];
        for(int i = 0; i < 26; i++){
            if(c == alfa[i]){
                alfanum[i]++;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < 26; i++){
        if(alfanum[i] % 2 != 0){
            count++;
        }
    }
    if(count > 1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}