#include <stdio.h>
#include <string.h>

int main(){

    /*

    Desenvolva um programa que receba um NOME qualquer e em seguida apresente na saída:
    1 - A Quantidade de caracteres do NOME.
    2 - Se a Quantidade estiver entre 3 e 8, escrever: "Dentro da Faixa"
    3 - Escreva esse NOME ao contrário

    */

    char nome[30];
    int i, qtd;

    printf ("\nDigite um nome: ");
    scanf("%s",nome);

    qtd = strlen(nome);

    printf ("\n%i caracteres",qtd);

    if (qtd >= 3 && qtd <= 8){
        printf ("\nDentro da Faixa\n");
    }else{printf("\nIncorreto\n");}

    for (i=qtd;i>=0;i--){
        printf("%c",nome[i]);
    }

}
