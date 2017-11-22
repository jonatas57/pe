#include <stdio.h>

int soma(int i) {
    if (i == 1) {
        return 1;
    } else {
        return i + soma(i - 1);
    }
}

int main(){
    int a, b;
    scanf("%d", &a);
    b=soma(a);
    printf("%d\n", b);
    return 0;
}