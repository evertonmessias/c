#include <stdio.h>
#include <ctype.h>
// Converte textos de minusculo para MAIUSCULO
main(){
	FILE *f1, *f2;
	f1 = fopen ("minusculo.txt","r");
	f2 = fopen ("maiusculo.txt","at");
	if (f1 == NULL || f2 == NULL){
	printf("ERRO");exit(0);}
	char c = fgetc (f1);
	while (!feof(f1)){
	fputc (toupper(c),f2);
	c = fgetc (f1);
	}fclose(f1);fclose(f2);
	}
