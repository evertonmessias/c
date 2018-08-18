#include <stdio.h>
#define V 5
int main (){
	int i;
	char nomes[V][30];
	
	for (i=0;i<V;i++){
		printf("\nDigite o Nome %i: ",i+1);
		gets(nomes[i]);	
		fflush(stdin);	
	}
	
	printf ("\nLista de Nomes:\n");	
	
	for (i=0;i<V;i++){
		printf ("\n%s", nomes[i]);
	}
	
}
