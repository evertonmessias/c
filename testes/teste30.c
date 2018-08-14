#include <stdio.h>
#include <stdlib.h>
main(){
	FILE *arq;
	arq = fopen ("teste.txt","at");
	char texto[]="\nMeu programa em C";
	int i;
	for (i=0;i<strlen(texto);i++){
		fputc (texto[i],arq); // putc(caracter,stdout) para video
	}
	fclose(arq);
}


