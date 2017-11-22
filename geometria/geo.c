#include <stdio.h>
#include <math.h>

#ifndef GEOMETRIA
#define GEOMETRIA

struct s_ponto {
    double x, y;
};

typedef struct s_ponto ponto;
typedef struct s_ponto vetor;

struct s_segmento {
    ponto A, B;
};

struct s_triangulo {
    ponto A, B, C;
};

typedef struct s_triangulo triangulo;
typedef struct s_segmento segmento;

double produto_interno(vetor p, vetor q) {
    double pi;
    pi = p.x * q.x + p.y * q.y;
    return pi;
}

vetor subtrai(vetor p, vetor q) {
    vetor s;
    s.x = p.x - q.x;
    s.y = p.y - q.y;
    return s;
}

vetor roda90(vetor p) {
    vetor r;
    r.x = -p.y;
    r.y = p.x;
    return r;
}

double distancia(ponto p, ponto q) {
    double dist;
    dist = sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
    return dist;
}

int sinal_do_coseno(vetor u, vetor v) {
    double p = produto_interno(u, v);
    if (p == 0) {
        return 0;
    } else {
        return p / fabs(p);
    }
}

int sentido(ponto p, ponto q, ponto r) {
    double pv;
    vetor u, v;
    u.x = q.x - p.x;
    u.y = q.y - p.y;
    v.x = r.x - p.x;
    v.y = r.y - p.y;
    pv = u.x * v.y - u.y * v.x;
    if (pv == 0) {
        return 0;
    } else {
        return -pv / fabs(pv);
    }
}

int cruza(segmento s, segmento t) {
    int a, b, c, d;
    a=sentido(s.A, s.B, t.A);
    b=sentido(s.A, s.B, t.B);
    c=sentido(t.A, t.B, s.A);
    d=sentido(t.A, t.B, s.B);
    if((a!=b)&&(c!=d)){
        return 1;
    }else{
        return 0;
    }
}

int dentro(ponto p, triangulo t) {
    if ((sentido(p, t.A, t.B) == sentido(p, t.B, t.C))&&(sentido(p, t.A, t.B) == sentido(p, t.C, t.A))) {
        return 1;
    } else {
        return 0;
    }
}

ponto cruzamento(segmento s, segmento t){
    ponto O;
    double m1=(s.A.y-s.B.y)/(s.A.x-s.B.x), m2=(t.A.y-t.B.y)/(t.A.x-t.B.x), b1=s.A.y-m1*s.A.x, b2=t.A.y-m2*t.A.x;
    O.x=(b2-b1)/(m1-m2);
    O.y=m1*O.x+b1;
    return O;
}

ponto projeta(ponto p, segmento s){
    vetor u, v;
    u.x=p.x-s.A.x;
    u.y=p.y-s.A.y;
    v.x=s.B.x-s.A.x;
    v.y=s.B.y-s.A.y;
    double a;
    a=(u.x*v.x+u.y*v.y)/(pow(v.x, 2)+pow(v.y, 2));
    ponto q;
    q.x=s.A.x+a*v.x;
    q.y=s.A.y+a*v.y;
    return q;
}

int intersecta(triangulo a, triangulo b){
    segmento sa[3], sb[3];
    ponto pa[3]={a.A, a.B, a.C}, pb[3]={b.A, b.B, b.C};
    for(int i=0;i<3;i++){
        sa[i].A=pa[i];
        sa[i].B=pa[(i+1)%3];
        sb[i].A=pb[i];
        sb[i].B=pb[(i+1)%3];
    }
    int d=0;
    for(int i=0;i<3;i++){
        d+=dentro(pa[i], b);
        d+=dentro(pb[i], a);
        for(int j=0;j<3;j++){
            d+=cruza(sa[i], sb[j]);
        }
    }
    if(d==0){
        return 0;
    }else{
        return 1;
    }
}

#endif

int main(){
    triangulo a, b;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &a.A.x, &a.A.y, &a.B.x, &a.B.y, &a.C.x, &a.C.y, &b.A.x, &b.A.y, &b.B.x, &b.B.y, &b.C.x, &b.C.y)!=EOF){
        int d=intersecta(a, b);
        printf("%d\n", d);
    }
    return 0;
}