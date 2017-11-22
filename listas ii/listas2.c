#include <stdio.h>
#include <stdlib.h>

typedef struct s_no * no;

struct s_no{
  int item;
  no ant, prox;
};

no livre=NULL;
int N=0, L=0;

void insere_inicio(no *inicio, no x) {
  x->prox = *inicio;
  x->ant=NULL;
  *inicio = x;
}
no final(no inicio){
  if(inicio==NULL){
    return NULL;
  }
  for(;inicio->prox!=NULL;inicio=inicio->prox);
  return inicio;
}
void insere_final(no *inicio, no x){
  if(*inicio==NULL){
    *inicio=x;
  }else{
    no f=final(*inicio);
    f->prox=x;
    x->ant=f;
  }
}
no novo(int item){
  if(L==N){
    no v=(no)malloc(50*sizeof(struct s_no));
    for(int i=0;i<50;i++){
      insere_inicio(&livre, v+i);
    }
    N+=50;
    return novo(item);
  }else{
    no x=livre;
    livre=x->prox;
    x->prox=NULL;
    x->item=item;
    x->ant=NULL;
    L++;
    return x;
  }
}
void deleta(no x){
  insere_inicio(&livre, x);
  L--;
}
void deletalis(no *ini){
  while(*ini!=NULL){
    no x=*ini;
    *ini=x->prox;
    deleta(x);
  }
}
void imprime(no inicio) {
  no x;
  for (no x = inicio; x != NULL; x = x->prox)
    printf("%d ", x->item);
  printf("\n");
}

no soma(no a, no b){
  no s=NULL, fa=final(a), fb=final(b);
  int pa=1, pb=1;
  while(pa+pb){
    int d=0;
    if(pa){
      d+=fa->item;
    }
    if(pb){
      d+=fb->item;
    }
    insere_inicio(&s, novo(d));
  }
}

int main(){
  int p = 1;
  char c, o;
  no a=NULL, b=NULL, s=NULL;
  while(scanf("%c", &c)!=0){
    if((int)c <= 57 && (int)c >= 48){
      int d=(int)c-48;
      if(p){
        insere_final(&a, novo(d));
      }else{
        insere_final(&b, novo(d));
      }
    }
    else if(c=='\n'){
      p=1;
      if(o=='+'){
        s=soma(a, b);
        imprime(s);
      }
    }
    else{
      p=0;
      o=c;
    }
  }
}
