#include <stdio.h>
struct ponto{int x,y;};
void imprime (int *n ,int *m) {printf ("Valores = %d , %d \n" ,*n ,*m);}
int main () {
    struct ponto p1 = {10,20};
    imprime (&p1.x,&p1.y);
    system ("pause");return 0;}
