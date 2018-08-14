#include <stdio.h>
#include <stdlib.h>
main(){
	FILE *arq;
	arq = fopen ("teste.txt","r");
	char c = fgetc (arq);
	while (c != EOF){
	printf ("%c",c);
	c = fgetc (arq); // c = getc(stdin) para obter do teclado
	}
	printf ("\nFIM\n");
	fclose(arq);
}
