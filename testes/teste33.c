#include <stdio.h>
main(){
	FILE *arq;
	int op;
	printf ("Digite (e)screver ou (l)er\n");
	op = getc (stdin);
	switch (op){
	case 108:
	arq = fopen ("teste.txt","r");
	if (arq == NULL){printf("ERRO");exit(0);}
	char txt[20];
	fgets (txt,20,arq);
	printf("%s",txt);
	break;
	case 101:
	arq = fopen ("teste.txt","at");
	if (arq == NULL){printf("ERRO");exit(0);}
	char texto[20]="\nMeu programa em C";
	fputs (texto,arq);
	break;
	default:
	printf ("Opcao Errada");
	break;
	fclose(arq);}}
