#include <stdio.h>
main() {
    int i, *p, vet[5] = {1,2,3,4,5};
    p = vet; // nao precisa colocar & pois o nome do vetor é seu end
    for (i=0;i<5;i++){
    printf ("%d\n", p[i]); // ou
    printf ("%d\n", *(p+i));}}

