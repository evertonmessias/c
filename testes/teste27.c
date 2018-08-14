#include <stdio.h>
typedef struct {
        int a,b,c;
}eq2g;

int equacao2g (eq2g *e) {
                int delta;
                int r[2];
                if (e->a == 0){printf("\n\nO termo a nao pode ser zero!\n\n");return 0;}
				delta=(e->b*e->b)-(4*(e->a)*(e->c));
				if (delta >= 0){
				r[0]=(((-1)*(e->b))+(sqrt(delta)))/(2*(e->a));
				r[1]=(((-1)*(e->b))-(sqrt(delta)))/(2*(e->a));
				printf ("\n\nx1 = %d e x2 = %d\n\n",*r,*(r+1));
				return &r;}
				else {printf ("\n\nNao existe raiz real\n\n");return 0;}}

main () {
    eq2g dados;
    int *r;
    printf ("\nDigite o valor do termo a : ");
    scanf ("%d", &dados.a);
    printf ("\nDigite o valor do termo b : ");
    scanf ("%d", &dados.b);
    printf ("\nDigite o valor do termo c : ");
    scanf ("%d", &dados.c);
    r = equacao2g (&dados);
    printf ("\n\nx1 = %d e x2 = %d\n\n",*r,*(r+1));}
