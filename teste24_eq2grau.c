#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void equacao_2o_grau (float a, float b, float c, float *x1, float *x2) {
				float delta;
				delta=(b*b)-(4*a*c);
				*x1=(((-1)*b)+(sqrt(delta)))/(2*a);
				*x2=(((-1)*b)-(sqrt(delta)))/(2*a); }
main () {
    float a,b,c,x1,x2;
    printf ("\nDigite o valor do termo a : ");
    scanf ("%f", & a);
    printf ("\nDigite o valor do termo b : ");
    scanf ("%f", & b);
    printf ("\nDigite o valor do termo c : ");
    scanf ("%f", & c);
    equacao_2o_grau (a,b,c,&x1,&x2);
    printf ("\n\nx1 = %.2f e x2 = %.2f\n\n",x1,x2);
    system ("pause");
    return 0;
    }
