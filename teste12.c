# include <stdio.h>
double fatorial (int n) {
    if (n != 0)return n*fatorial(n-1);
    else return 1 ;}
main(){
    int numero;
    double resposta;
    printf ("\nDigite um numero: ");
    scanf ("%d", & numero);
    resposta=fatorial(numero);
    printf ("\nA resposta eh: %.0lf \n\n",resposta); // para double %f ou %e
    return 0;}
