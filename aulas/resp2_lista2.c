#include<stdio.h>
#include <locale.h>
#define V 2

int main(){
    setlocale(LC_ALL, "Portuguese");
    int loop=0, i,op,matr[V];
    float nota[V];    
    do{    	
    system("cls");system("color fc");	
    printf("\n");
	for(i=0;i<40;i++){printf("%c",4);}
	printf("\n%c         Aula de Programação          %c\n",4,4);
	for(i=0;i<40;i++){printf("%c",4);}
	printf("\n%c                                      %c",4,4);
	printf("\n%c        (1)  Inserir Alunos           %c",4,4);
	printf("\n%c        (2)  Consultar Alunos         %c",4,4);
	printf("\n%c        (3)  Sair                     %c",4,4);
	printf("\n%c                                      %c\n",4,4);
	for(i=0;i<40;i++){printf("%c",4);}
	printf("\n\n         Digite uma Opção: ");
	op=getch();
	switch (op){
		case 49:
			system("cls");
			printf("Opção 1 - Inserir Alunos\n");
			for (i=0;i<V;i++){
				printf ("\nDigite a Matricula do Aluno %i: ",i+1);
				scanf("%i",&matr[i]);
				printf ("\nDigite a Nota do Aluno %i: ",i+1);
				scanf("%f",&nota[i]);				
			}
			printf("\n\n*** Inserção OK ***\n");
			getch();
			break;
		case 50:
			system("cls");
			printf("Opção 2 - Consultar Alunos\n");
			for (i=0;i<V;i++){
				printf ("\nAluno %i ==> Matricula: %i , Nota: %.1f ",i+1,matr[i],nota[i]);						
			}
			printf("\n\n*** Consulta OK ***\n");
			getch();
			break;
		case 51:
			system("cls");
			printf("\nFIM\n");
			return 0;
			break;
	}
    }while(loop==0);
}
