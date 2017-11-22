#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprime_em_base(int n, int b) {
    if (n < b) {
        printf("%d", n);
    } else {
        int r = n % b;
        n /= b;
        imprime_em_base(n, b);
        printf("%d", r);
    }
}

int main(){
    int n, b;
    scanf("%d %d", &n, &b);
    imprime_em_base(n, b);
    return 0;
}