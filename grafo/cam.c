#include <stdio.h>
#include <stdlib.h>

int **m, n, p;

void imprime_caminho(int i, int j) {
 	if (i == j) {   
		printf("%d\n", i);
	}else if (m[i][j] == -1) {
		if(p == 1){
			p=0;
			printf("%d %d", i, j);
		}else{
			printf(" %d", j);
		}
    } else if(m[i][j] == n){
        printf("impossivel\n");
    }else{
        imprime_caminho(i, m[i][j]);
        imprime_caminho(m[i][j], j);
    }
}

int main() {
	p = 1;
    scanf("%d", &n);
    int a, b;
    scanf("%d %d", &a, &b);
    m = (int**) malloc(n * sizeof (int*));
    for (int i = 0; i < n; i++) {
        m[i] = (int*) malloc(n * sizeof (int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    imprime_caminho(a, b);
	printf("\n");
    return 0;
}
