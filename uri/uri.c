#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*#define N 56253

int main() {
    printf("%d\n", 1);
    int n, aux = 1;
    printf("%d\n", 1);
    char g[40][N];
    printf("%d\n", 1);
    g[0][0] = '3';
    g[0][1] = '\0';
    while (scanf("%d", &n) != EOF) {
        if (n > aux) {
            while (aux < n) {
                int c = 0, j = 0;
                for (int i = 0; (g[aux-1][i - 1] != '\0')||i==0; i++) {
                    if (i == 0 || g[aux-1][i] == g[aux-1][i - 1]) {
                        c++;
                    }
                    else {
                        g[aux][j] = (char) (c + 48);
                        g[aux][++j] = g[aux-1][i - 1];
                        c = 1;
                        j++;
                    }
                }
                g[aux][j] = '\0';
                aux++;
            }
        }
        //printf("%s\n", g[n-1]);
        if(n>10){
            int l=strlen(g[n-1]);
            printf("%d\n", l);
        }else{
            printf("%s\n", g[n-1]);
        }
    }
    return 0;
}
/*int main() {
    char n[50], m[50];
    while (scanf("%s", &n) != EOF) {
        int c = 0, j = 0;
        for (int i = 0; n[i - 1] != '\0'; i++) {
            if (i == 0 || n[i] == n[i - 1]) {
                c++;
            } else {
                m[j] = (char) (c + 48);
                m[++j] = n[i - 1];
                c = 1;
                j++;
            }
        }
        m[j] = '\0';
        printf("%s - %s\n", n, m);
    }
    return 0;
}*/

int main(){
    int t, r;
    char I[999];
    scanf("%d", &t);
    for(int a=0;a<t;a++){
        scanf("%s", &I);
        int l=strlen(I), c=0, p=0,z=0;
        while(I[z]!='\0'){
            for(int i=0;i<l;i++){
                if(I[i]!=0){
                    int d=(int)I[i]-48;
                    I[i]=d/2;
                    if(p){
                        I[i]+=5;
                    }
                    p=d%2;
                }
            }
            while(I[z]==0){
                z++;
            }
        }
    }
    return 0;
}