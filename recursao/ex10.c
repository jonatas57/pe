#include <stdio.h>
#include <stdlib.h>

void permut(int n, int *v, int *w, int l) {
    if (n == 1) {
        for (int i = 0; i < l; i++) {
            if (i == l - 1) {
                printf("%d\n", w[i]);
            } else {
                printf("%d ", w[i]);
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            int aux = v[0];
            v[0] = v[i];
            v[i] = aux;
            permut(n - 1, v + 1, w, l);
            aux = v[0];
            v[0] = v[i];
            v[i] = aux;
        }
    }
}

void enum_permut(int n, int *v) {
    int *w = v;
    permut(n, v, w, n);
}

int main(){
    int n, *p;
    scanf("%d", &n);
    p = (int*) malloc(n * sizeof (int));
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
    }
    enum_permut(n, p);
    printf("\n");
    return 0;
}