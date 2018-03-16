# include <stdio.h>
# include <stdlib.h>
# define MAX 2 // vetor com MAX campos

typedef struct { 	// estrutura tipo aluno com campos nome e idade
        char nome [30];
        int idade;
}Aluno;

main()
{
    Aluno dado[MAX]; 	// declarando variável dado[MAX] do TIPO struct aluno
    int i;
    for (i=0;i<MAX;i++){
    fflush(stdin);
    printf ("\nDigite o nome do aluno %d : ", i+1);
    gets (dado[i].nome);
    printf ("\nDigite a idade do aluno %d : ", i+1);
    scanf ("%d", & dado[i].idade);
    }
    printf ("\n\nLISTA DE ALUNOS\n\n");
    for (i=0;i<MAX;i++){
    printf ("%s : %d anos\n", dado[i].nome,dado[i].idade);
    }
    printf ("\n");
    system ("pause");
    return 0;
    }
