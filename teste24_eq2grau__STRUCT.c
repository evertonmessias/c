#include <stdio.h>
typedef struct {
        float a,b,c,x1,x2;
}eq2g;

eq2g equacao2g (eq2g *e) { //recebe o end dos dados num ponteiro
                float delta;
                if (e->a == 0){printf("\n\nERRO: 'a' nao pode ser zero!\n\n");exit(0);}
				delta=(e->b*e->b)-(4*(e->a)*(e->c));
				if (delta >= 0){
				e->x1=(((-1)*(e->b))+(sqrt(delta)))/(2*(e->a));
				e->x2=(((-1)*(e->b))-(sqrt(delta)))/(2*(e->a));
				return *e;} //retorna o que aponta, isto é: os dados
				else {printf ("\n\nERRO: nao existe raiz real\n\n");exit(0);}}
main () {
    eq2g dados; //duas variaveis do tipo eq2g
    printf ("\nDigite o valor do termo a : ");
    scanf ("%f", &dados.a);
    printf ("\nDigite o valor do termo b : ");
    scanf ("%f", &dados.b);
    printf ("\nDigite o valor do termo c : ");
    scanf ("%f", &dados.c);
    dados=equacao2g (&dados); // envia o end e recebe dados
    printf ("\n\nx1 = %.2f e x2 = %.2f\n\n",dados.x1,dados.x2);}
