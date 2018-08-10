# include <stdio.h>
main() {
int n, i, *p , x = sizeof(int);
printf("Qtos numeros INT deseja armazenar ?\n");
scanf ("%d", &n);
p = calloc(n,x); // criando um vetor de zeros de N posições de tamanho X Bytes
printf("\nPonteiro antes:\n");
for (i=0;i<n;i++){printf ("%d, ", p[i]);}
printf("\n\nInserindo Dados...\n");
for (i=0;i<n;i++){printf ("Digite o %do num: ", i+1); scanf ("%d", &p[i]);} // tratando o vetor
printf("\nPonteiro Agora:\n");
for (i=0;i<n;i++){printf ("%d, ", p[i]);}
free(p);} // liberando memoriano final
