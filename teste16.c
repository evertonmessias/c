#include <stdio.h>
struct ponto{int x,y;};

void imprime (struct ponto *P) {
printf ("Valores = %d , %d \n" ,P->x ,P->y);}

int main () {
    struct ponto p1 = {10,20};
    imprime (&p1);}
