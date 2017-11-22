#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int eh_palindroma(int n, char*p) {
    if (n < 2) {
        return 1;
    } else {
        if (p[0] == p[n - 1]) {
            return eh_palindroma(n - 2, p + 1);
        } else {
            return 0;
        }
    }
}

int main(){
    int n;
    char *p;
    scanf("%d", &n);
    p=(char*)malloc((n+1)*sizeof(char));
    scanf("%s", p);
    int a=eh_palindroma(n, p);
    if(a){
        printf("E palindroma\n");
    }else{
        printf("Nao e palindroma\n");
    }
    return 0;
}