#include <stdio.h>

long soma_digitos(int n) {
    if (n < 10) {
        return n;
    } else {
        long a = n % 10;
        n /= 10;
        return a + soma_digitos(n);
    }
}

int main(){
    int n, s;
    scanf("%d", &n);
    s=soma_digitos(n);
    printf("%d\n", s);
    return 0;
}