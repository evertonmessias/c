#include <stdio.h>
#include <stdlib.h>
int main () {
    int num;
    printf ("Digite um numero\n");
    scanf ("%d",&num);
    (num >= 10) ? printf ("O num eh maior ou igual a 10\n"): printf ("O num eh menor que 10\n");
    system ("pause");
    return 0;
    }
