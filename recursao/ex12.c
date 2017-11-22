#include <stdio.h>
#include <stdlib.h>

void troca_blocos(int p, int q, int r, int *v) {
    if (p != q) {
        for (int i = p, j = q; i < q && j < r; i++, j++) {
            int a = v[i];
            v[i] = v[j];
            v[j] = a;
        }
        if (q - p < r - q) {
            troca_blocos(q, 2 * q - p, r, v);
        } else {
            troca_blocos(p + r - q, q, r, v);
        }
    }
}

int main(){
    int p, q, r, *v, n;
    scanf("%d", &n);
    v=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d", v+i);
    }
    scanf("%d %d %d", &p, &q, &r);
    printf("111\n");
    troca_blocos(p, q, r, v);
    printf("111\n");
    for(int i=0;i<n;i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}