# include <stdio.h>
double fatorial (int n) {
    if (n == 0 || n == 1)return 1;
    else return n*fatorial(n-1);}
main(){
    int numero;
    double resposta;
    printf ("\nDigite um numero: ");
    scanf ("%d", & numero);
    resposta=fatorial(numero);
    printf ("\nA resposta eh: %.2e \n\n",resposta); // para double %f ou %e
    return 0;}
