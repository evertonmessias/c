#include <stdio.h>
main() {
void *pp;
int p = 10;
pp = &p;
printf ("Conteudo: %d\n", *(int*)pp);}
// como é genérico tem q converter antes de exibir

