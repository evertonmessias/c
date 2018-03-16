#include <stdio.h>
#include <stdlib.h>
int main () {
    int i;
    do {
    system ("cls");
    printf ("Escolha uma Opcao:\n\n");
    printf ("(1) Opcao 1\n");
    printf ("(2) Opcao 2\n");
    printf ("(3) Opcao 3\n");
    scanf ("%d", &i);
    }while ((i < 1) || (i > 3));
    printf ("Voce escolheu a Opcao %d\n\n",i);
    system ("pause");
    return 0;
    }
