#include <stdio.h>
#include <string.h>

int m[8][8], v[10] = {10,11,12,13,14,15,16,17,18,19};

void movcav(int i, int j, int n){
    if(n==0){
        for(int a=0;a<10;a++){
            printf("%c%d", (char)(v[a]/10+65), v[a]%10);
        }
        printf("\n");
    }else{
        
    }
}

int main(){
    movcav(0, 0, 0);
    return 0;
}