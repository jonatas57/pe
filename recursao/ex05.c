#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverter(int n, char*p) {
    if (n < 2) {
        return 0;
    } else {
        char a = p[0];
        p[0] = p[n - 1];
        p[n - 1] = a;
        reverter(n - 2, p + 1);
        return 0;
    }
}

int main(){
    int n;
    char *p;
    scanf("%d", &n);
    p=(char*)malloc((n+1)*sizeof(char));
    scanf("%s", p);
    reverter(n, p);
    printf("%s\n", p);
    return 0;
}