#include <stdio.h>
#include <math.h>

#define N 20000

int main() {
    int n = 0;
    double t[N] = {0}, med, min = 100, max = -100, soma = 0;

    while (n < N && scanf("%lf", &t[n]) != EOF) {
        soma += t[n];
        if (t[n] > max) {
            max = t[n];
        }
        if (t[n] < min) {
            min = t[n];
        }
        n++;
    }

    med = soma / n;

    printf("med = %.3lf, min = %.3lf, max = %.3lf\n", med, min, max);

    double soma2 = 0, med2, n2 = 0;
    for (int i = 0; i < N; i++) {
        if (t[i] > med) {
            soma2 += t[i];
            n2++;
        }
    }
    med2 = soma2 / n2;
    printf("Media das temperaturas acima da media: %.3lf\n", med2);

    int aux[20] = {0}, aux2;
    double itvl = (max - min) / 20;

    for (int i = 0; i < N; i++) {
        aux2 = (t[i] - min) / itvl;
        aux[aux2]++;
    }
    for(int i=0;i<20;i++){
        printf("aux[%d] = %d\n", i, aux[i]);
    }
    int aux3[20], max2 = -1;
    for (int i = 0; i < 20; i++) {
        aux3[i] = aux[i] / 122;
        if (aux[i] % 122 != 0) {
            aux3[i]++;

        }
        if (max2 < aux3[i]) {
            max2 = aux3[i];
        }
    }
    for (int i = 0; i < 20; i++) {
        printf("Temperaturas entre %06.3lf e %06.3lf: ", min + i*itvl, min + (i + 1) * itvl);
        for (int j = 0; j < aux3[i]; j++) {
            printf("*");
        }
        printf("\n", aux[i]);
    }
    printf("Histograma na vertical:\n");
    for (int i = 0; i < 20; i++) {
        aux3[i] = max2 - aux3[i];
    }
    for (int i = 0; i < max2; i++) {
        for (int j = 0; j < 20; j++) {
            if (aux3[j] > i) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}
