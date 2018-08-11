#include<stdio.h>
#define V 2

int main(){
    int loop=0, i,op,matr[V];
    float nota[V];    
    do{    	
    system("cls");system("color fc");	
    printf("\n");
	for(i=0;i<40;i++){printf("%c",219);}
	printf("\n%c         Aula de Programa%c%co          %c\n",219,135,132,219);
	for(i=0;i<40;i++){printf("%c",219);}
	printf("\n%c                                      %c",219,219);
	printf("\n%c        (1)  Inserir Alunos           %c",219,219);
	printf("\n%c        (2)  Consultar Alunos         %c",219,219);
	printf("\n%c        (3)  Sair                     %c",219,219);
	printf("\n%c                                      %c\n",219,219);
	for(i=0;i<40;i++){printf("%c",219);}
	printf("\n\n         Digite uma Op%c%co: ",135,132);
	op=getch();
	switch (op){
		case 49:
			system("cls");
			printf("Op%c%co 1 - Inserir Alunos\n",135,132);
			for (i=0;i<V;i++){
				printf ("\nDigite a Matricula do Aluno %i: ",i+1);
				scanf("%i",&matr[i]);
				printf ("\nDigite a Nota do Aluno %i: ",i+1);
				scanf("%f",&nota[i]);				
			}
			printf("\n\n*** Inser%c%co OK ***\n",135,132);
			getch();
			break;
		case 50:
			system("cls");
			printf("Op%c%co 2 - Consultar Alunos\n",135,132);
			for (i=0;i<V;i++){
				printf ("\nAluno %i ==> Matricula: %i , Nota: %.1f ",i+1,matr[i],nota[i]);						
			}
			printf("\n\n*** Consulta OK ***\n",135,132);
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
