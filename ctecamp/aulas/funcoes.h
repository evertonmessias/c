#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define V 2

	int i,matr[V];
    float nota[V];
	char nome[V][30];
	
void pausa(void){
	printf("\n\nOpera%c%co OK, Qualquer Tecla para Continuar...\n",135,132);
	getch();
}

void inserir (void){	
	system("cls");
	printf("Op%c%co 1 - Inserir Alunos\n",135,132);
	for (i=0;i<V;i++){
		printf ("\nDigite o Nome do Aluno %i: ",i+1);
		gets(nome[i]);fflush(stdin);
		printf ("\nDigite a Matricula do Aluno %i: ",i+1);
		scanf("%i",&matr[i]);fflush(stdin);
		printf ("\nDigite a Nota do Aluno %i: ",i+1);
		scanf("%f",&nota[i]);fflush(stdin);				
	}
	pausa();
}

void consultar (void){
	system("cls");
	printf("Op%c%co 2 - Consultar Alunos\n",135,132);
	if (matr[0] != 0){
	for (i=0;i<V;i++){
		printf ("\nAluno %i:\nNome: %s\nMatricula: %i\nNota: %.1f\n",i+1,nome[i],matr[i],nota[i]);						
	}
	pausa();
	}else {
	pausa();
}
}
