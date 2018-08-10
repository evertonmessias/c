#include <stdio.h>
struct ponto{int x,y;};
void atribui (struct ponto *p) { // passada a struct inteira
    (*p).x = 10; p->y = 20;} // tem q ser (*p).x ou p->x pois só agora está acessando os campos
int main () {
    struct ponto p1;
    atribui(&p1); // passa a struct inteira pela variavel
    printf ("x = %d ; y = %d\n",p1.x,p1.y);
    system ("pause");return 0;}
