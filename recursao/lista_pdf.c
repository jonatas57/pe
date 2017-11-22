#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check() {
    printf("check\n");
}
//----------1-----------

int soma(int i) {
    if (i == 1) {
        return 1;
    } else {
        return i + soma(i - 1);
    }
}
//----------2-----------

int soma2(int n, int *v) {
    if (n == 1) {
        return v[0];
    } else {
        return v[n - 1] + soma2(n - 1, v);
    }
}
//----------3----------

int min(int n, int *v) {
    if (n == 1) {
        return v[0];
    } else {
        if (v[n - 1] < min(n - 1, v)) {
            return v[n - 1];
        } else {
            return min(n - 1, v);
        }
    }
}
//----------4----------

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
//----------5----------

void reverter(int n, char*p) {
    if (n < 2) {
        return;
    } else {
        char a = p[0];
        p[0] = p[n - 1];
        p[n - 1] = a;
        reverter(n - 2, p + 1);
    }
}
//----------6----------

long pot2(int k) {
    if (k == 0) {
        return 1;
    } else {
        return 2 * pot2(k - 1);
    }
}
//----------7----------

int enum_pot2(int k) {
    int r;
    if (k == 0) {
        printf("%d\n", 1);
        return 1;
    } else {
        r = 2 * enum_pot2(k - 1);
        printf("%ld ", r);
        return r;
    }
}
//----------8----------

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
//----------9----------

int soma_digitos(int n) {
    if (n < 10) {
        return n;
    } else {
        int a = n % 10;
        n /= 10;
        return a + soma_digitos(n);
    }
}
//----------10---------

/*void permut(int n, int *v, int *w, int l) {
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
}*/
//----------11---------

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
            if (v[0] != v[i] || i == 0) {
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
}

void enum_permut(int n, int *v) {
    int *w = v;
    permut(n, v, w, n);
}
//----------12---------

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

int main() {
    int n, *p;
    while (scanf("%d", &n) != EOF) {
        p = (int*) malloc(n * sizeof (int));
        for (int i = 0; i < n; i++) {
            scanf("%d", p + i);
        }
        enum_permut(n, p);
    }
    printf("\n");
    return 0;
}