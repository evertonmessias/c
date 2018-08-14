#include <stdio.h>
float equacao2g (float *e, int t) { //recebe o end num ponteiro e o tamanho do vetor
                float delta;
                if (e[0] == 0){printf("\n\nERRO: 'a' nao pode ser zero!\n\n");exit(0);}
				delta=(e[1]*e[1])-(4*(e[0])*(e[2]));
				if (delta >= 0){
				e[3]=(((-1)*(e[1]))+(sqrt(delta)))/(2*(e[0]));
				e[4]=(((-1)*(e[1]))-(sqrt(delta)))/(2*(e[0]));
				return *e;} //retorna o que aponta, isto é: os dados
				else {printf ("\n\nERRO: nao existe raiz real\n\n");exit(0);}}
main () {
    float dados[5];
    printf ("\nDigite o valor do termo a : ");
    scanf ("%f", &dados[0]);
    printf ("\nDigite o valor do termo b : ");
    scanf ("%f", &dados[1]);
    printf ("\nDigite o valor do termo c : ");
    scanf ("%f", &dados[2]);
    *dados=equacao2g (dados,5); //envia end s/ '&' (indicar tam vetor), recebe em: dados[5] ou *dados
    printf ("\n\nx1 = %.2f e x2 = %.2f\n\n",*(dados+3),dados[4]);}
