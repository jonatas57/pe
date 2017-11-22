#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int n, *v, m;
    scanf("%d", &n);
    v=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d", v+i);
    }
    m=min(n, v);
    printf("%d\n", m);
    return 0;
}