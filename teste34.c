#include <stdio.h>
main(){
	FILE *arq; // ponteiro tipo FILE
	int op;
    printf ("LISTA DE NOMES\n");
	printf ("Digite (e)screver ou (l)er\n");
	op = getc (stdin); // recebe opção do teclado
	switch (op){
	case 101:// e em ascii
	arq = fopen ("teste.txt","at");
	if (arq == NULL){printf("ERRO");exit(0);}
	char nome[30];
	printf("Digite seu nome: \n");
	__fpurge(stdin); // LIMPAR O BUFFER; para windows use: fflush(stdin);
	fgets(nome,30,stdin);
	printf("\nGravado: %s\n",nome);
	fprintf(arq,"%s",nome);
	break;
	case 108: // l em ascii
	arq = fopen ("teste.txt","r"); // abre arquivo para leitura
	if (arq == NULL){printf("ERRO");exit(0);}
	int pos;
	printf ("Qual posicao deseja ler ?");
	scanf ("%d",&pos);
	fseek (arq,pos*sizeof(char),SEEK_SET);
	char txt[20];
	fgets(txt,20,arq); // fscanf (arq,"%s",txt);
	printf("%s",txt);
	break;
	default:printf ("Opcao Errada");break;
	fclose(arq);}}
