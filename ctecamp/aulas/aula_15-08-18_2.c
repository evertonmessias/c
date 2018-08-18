#include<stdio.h>
#include "area.h"

float raio,area;

int main(){
	
	printf ("\nDigite o Raio da Circunferencia: ");
	scanf ("%f", &raio);
	
	area = areaC (raio);
	
	printf ("\nArea da Circunferencia: %.1f", area);	
	
}
