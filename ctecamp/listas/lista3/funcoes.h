#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define V 50

	int i,matr[V], teclaESC, qtdAlunos = 0;
    float nota1[V], nota2[V], media[V];
	char nome[V][30];
	
void fim(void){
	printf("\n\nOpera%c%co OK, Qualquer Tecla para Continuar...\n",135,132);
	getch();
}

void inserir (void){
	for (i=0;i<V;i++){
		
		system("cls");
		printf("Op%c%co 1 - Inserir Alunos",135,132);
		
		printf ("\n\nDigite o Nome do Aluno %i: ",i+1);
		gets(nome[i]);fflush(stdin);
		printf ("\nDigite a Matricula do Aluno %i: ",i+1);
		scanf("%i",&matr[i]);fflush(stdin);
		printf ("\nDigite a Nota 1 do Aluno %i: ",i+1);
		scanf("%f",&nota1[i]);fflush(stdin);
		printf ("\nDigite a Nota 2 do Aluno %i: ",i+1);
		scanf("%f",&nota2[i]);fflush(stdin);
		
		qtdAlunos++; // determina a quantidade de alunos
		
		printf("\n\n(ENTER para Continuar, ESC para Sair.)");
		teclaESC = getch();		
		if (teclaESC == 27){break;}				
	}
	fim();
}

void consultar (void){
	system("cls");
	printf("Op%c%co 2 - Consultar Alunos",135,132);	
	for (i=0;i<qtdAlunos;i++){			
		printf ("\n\nAluno %i:\nNome: %s\nMatricula: %i\nNotas: %.1f\t%.1f",i+1,nome[i],matr[i],nota1[i],nota2[i]);		
	}
	fim();		
}

void calcular (void){
	system("cls");
	printf("Op%c%co 3 - Calcular Media",135,132);	
	
	// PROGRAMAR AQUI
	
}
