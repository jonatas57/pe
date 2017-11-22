#include <stdio.h>

long enum_pot2(int k) {
    long r;
    if (k == 0) {
        printf("%d\n", 1);
        return 1;
    } else {
        r = 2 * enum_pot2(k - 1);
        printf("%ld\n", r);
        return r;
    }
}

int main(){
    int k;
    scanf("%d", &k);
    enum_pot2(k);
    return 0;
}