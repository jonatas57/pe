#include <stdio.h>
#include <stdlib.h>

int soma(int n, int *v) {
    if (n == 1) {
        return v[0];
    } else {
        return v[n - 1] + soma(n - 1, v);
    }
}

int main(){
    int n, *v, s;
    scanf("%d", &n);
    v=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d", v+i);
    }
    s=soma(n, v);
    printf("%d\n", s);
    return 0;
}