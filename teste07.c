#include <stdio.h>

int main(){

	int letra;	
	
	printf ("Digite (s/n):  ");
	letra = getch();
	
	switch (letra){
		case 115:
			printf("\nSIM");
			break;
		
		case 110:
			printf("\nNAO");
			break;
		
		default:
			printf ("\nLETRA ERRADA");			
	}
}
