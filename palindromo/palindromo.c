#include <stdio.h>
#include <string.h>

int remchar(char *f, char d) {
    int p = 1, j, c = 0;
    for (int i = 0; f[i] != '\0'; i++) {
        if(f[i]==d){
            c++;
            if(p==1){
                j=i;
                p=0;
            }
        }else{
            if(p==0){
                f[j]=f[i];
                j++;
            }
        }
    }
    return c;
}

int main(int argc, char** argv) {
    char *frase, d = ' ';
    int n;

    if (argc >= 2) {
        frase = argv[1];
        n = strlen(frase);
        n-=remchar(frase, d);
        int p = 1;
        for (int i = 0; i < n / 2; i++) {
            if (frase[i] == frase[n - 1 - i]) {
                p *= 1;
            } else {
                p *= 0;
            }
        }
        if (p == 0) {
            printf("Nao e palindromo\n");
        } else {
            printf("E palindromo\n");
        }
    }

    return 0;
}