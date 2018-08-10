#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main () {
    char palavra[20];
    printf ("\nDigite uma palavra: ");
    //scanf ("%s", palavra); - uma palavra apenas ate o enter
    gets (palavra); // frases inteiras até o enter
    printf ("\n\n%s\n\n",palavra);
    system ("pause");
    return 0;
    }
