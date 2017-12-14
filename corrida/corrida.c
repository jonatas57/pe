#include <stdio.h>
#include <stdlib.h>

typedef struct inst inst;
typedef struct s_no * pno;
typedef struct funcao funcao;

struct inst{
  char vel, tipo;
  int num, den;
  double fra;
};
struct s_no{
  inst item;
  pno prox;
};
struct funcao{
  double a, b;
};
funcao prod(funcao f, double a){
  f.a*=a;
  f.b*=a;
  return f;
}
funcao inverte(funcao f){
  funcao g;
  g.a=1/f.a;
  g.b=-f.b/f.a;
  return g;
}
funcao soma(funcao f, funcao g){
  f.a+=g.a;
  f.b+=g.b;
  return f;
}
double calc(funcao f, double x){
  return f.a*x+f.b;
}

void prin(inst I){
  printf("vel %c: %.3f de %c\n", I.vel, I.fra, I.tipo);
}
void imprime(pno inicio) {
  for (pno x = inicio; x != NULL; x = x->prox)
    prin(x->item);
}

pno livre=NULL;
void insere_inicio(pno *inicio, pno x) {
  if(*inicio==NULL){
    *inicio=x;
  }
  else{
    x->prox=*inicio;
    *inicio=x;
  }
}
pno novo(inst item){
  if(livre==NULL){
    pno v=(pno)calloc(1024, sizeof(struct s_no));
    for(int i=0;i<1024;i++){
      insere_inicio(&livre, v+i);
    }
    return novo(item);
  }
  else{
    pno x=livre;
    livre=x->prox;
    x->prox=NULL;
    x->item=item;
    return x;
  }
}
void deleta(pno x){
  insere_inicio(&livre, x);
}
inst retira(pno *ini){
  pno x=*ini;
  *ini=x->prox;
  inst I=x->item;
  deleta(x);
  return I;
}

int main(){
  inst I;
  funcao S={1,0}, T={1,0};
  pno list_inst=NULL;
  while(scanf("%c %d %d %c", &I.vel, &I.num, &I.den, &I.tipo)!=-1){
    I.fra=(double)I.num/I.den;
    insere_inicio(&list_inst, novo(I));
    if(I.fra==1){
      double t;
      int v, p=1;
      while(list_inst!=NULL){
        I=retira(&list_inst);

        if(I.vel=='A'){
          v=5;
        }
        else{
          v=10;
        }

        if(p){
          p=0;
          S.a=v;
          T.a=1;
        }
        else{
          if(I.tipo=='E'){
            S=prod(S, 1/(1-I.fra));
            T=soma(T, prod(S, I.fra/v));
          }
          else{
            T=prod(T, 1/(1-I.fra));
            S=soma(S, prod(T, I.fra*v));
          }
        }
      }
      t=calc(inverte(S), 100);
      t=calc(T, t);
      printf("%.3lf\n", t);
    }
    char aux;scanf("%c", &aux);
  }
  return 0;
}
