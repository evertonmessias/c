# include <stdio.h>
# define T 5 // esse valor pode ser pedido em scanf
main() {
int i;
int *p = calloc(T,sizeof(int)); // criando um vetor de T posições
if (p==NULL){printf ("ERRO");exit(1);} // se der erro sai fora
for (i=0;i<T;i++){printf ("Digite o num %d : ", i+1); scanf ("%d", &p[i]);} // tratando o vetor
free(p);} // liberando memoriano final
