#include <stdio.h>
#include <stdlib.h>

typedef struct s_no * no;

struct s_no{
  int item;
  no ant, prox;
};

no livre=NULL;
//int N=0, L=0;

void imprime(no inicio) {
  no x;
  for (no x = inicio; x != NULL; x = x->prox)
    printf("%d", x->item);
  printf("\n");
}
void insere_inicio(no *inicio, no x) {
  if(*inicio==NULL){
    *inicio=x;
  }
  else{
    x->prox=*inicio;
    (*inicio)->ant=x;
    *inicio=x;
  }
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
  if(livre==NULL){
    no v=(no)calloc(1024, sizeof(struct s_no));
    for(int i=0;i<1024;i++){
      insere_inicio(&livre, v+i);
    }
    //N+=1024;
    return novo(item);
  }
  else{
    no x=livre;
    livre=x->prox;
    x->prox=NULL;
    x->item=item;
    x->ant=NULL;
    //L++;
    return x;
  }
}
void deleta(no x){
  insere_inicio(&livre, x);
  //L--;
}
void deletalis(no *ini){
  while(*ini!=NULL){
    no x=*ini;
    *ini=x->prox;
    deleta(x);
  }
}

no soma(no a, no b){
  no s=NULL, fa=final(a), fb=final(b);
  int pa=1, pb=1, d=0;
  while(pa+pb){
    if(pa){
      d+=fa->item;
      if(fa->ant==NULL){
        pa=0;
      }
      else{
        fa=fa->ant;
      }
    }
    if(pb){
      d+=fb->item;
      if(fb->ant==NULL){
        pb=0;
      }
      else{
        fb=fb->ant;
      }
    }
    insere_inicio(&s, novo(d%10));
    d/=10;
  }
  if(d>0){
    insere_inicio(&s, novo(1));
  }
  return s;
}
no prod(no a, no b){
  no s=NULL, aux=NULL;
  int m=0, r=0;
  insere_inicio(&s, novo(0));
  for(no i=final(a);i!=NULL;i=i->ant){
    for(int k=0;k<m;k++){
      insere_inicio(&aux, novo(0));
    }
    for(no j=final(b);j!=NULL;j=j->ant){
      int d=i->item*j->item;
      insere_inicio(&aux, novo((d+r)%10));
      r=(d+r)/10;
    }
    if(r>0){
      insere_inicio(&aux, novo(r));
    }
    no x=soma(s, aux);
    deletalis(&s);
    s=x;
    deletalis(&aux);
    m++;
  }
  return s;
}

int main(){
  int p = 1;
  char c, o;
  no a=NULL, b=NULL, s=NULL;
  while(scanf("%c", &c)!=EOF){
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
      }
      else if(o=='*'){
        s=prod(a, b);
      }
      while(s!=NULL&&s->prox!=NULL&&s->item==0){
        if(s->item==0){
          s->prox->ant=NULL;
          no x=s;
          s=s->prox;
          deleta(x);
        }
      }
      imprime(s);
      deletalis(&a);
      deletalis(&b);
      deletalis(&s);
      //printf("usados: %d; total: %d\n", L, N);
    }
    else{
      p=0;
      o=c;
    }
  }
}
