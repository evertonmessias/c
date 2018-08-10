#include <stdio.h>

int main(){

	int letra;	
	
	printf ("Digite (s/n):  ");
	letra = getch();
	
	if (letra == 115){
		printf("\nSIM");
	}else if (letra == 110){
		printf("\nNAO");
	}else {
		printf ("\nLETRA ERRADA");
	}

}
