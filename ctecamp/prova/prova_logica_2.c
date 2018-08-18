#include <stdio.h>

    /*

    Desenvolva um programa que:
    1 - Crie um VETOR Float de 4 posições.
    2 - Crie uma Função Float para cálculo do Delta.
    3 - Receba valores nas posições 0,1,2 do VETOR (com FOR) e envie-as para a Função Delta.
    4 - Receba o resultado de Delta na Posição 3.
    5 - Exiba a resposta.

    */


float delta (float a, float b, float c){
    return (b*b)-(4*a*c);
}

int main(){

    int i;
    float vetor[4];

    for (i=0;i<3;i++){
    printf ("\nDigite o Valor %c: ",i+65);
    scanf("%f",&vetor[i]);
    }

    vetor[3] = delta(vetor[0],vetor[1],vetor[2]);

    printf("\nDELTA: %.1f\n",vetor[3]);

}
