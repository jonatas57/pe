#include <stdio.h>

long pot2(int k) {
    if (k == 0) {
        return 1;
    } else {
        return 2 * pot2(k - 1);
    }
}

int main(){
    int k;
    long n;
    scanf("%d", &k);
    n=pot2(k);
    printf("%ld\n", n);
    return 0;
}