#include<stdio.h>
#include "tela.h"
#include "funcoes.h"
#define V 2

int main(){
    int loop=0, i,op; 
    do{
    tela();
	op=getch();
	switch (op){
		case 49:
			inserir();
			break;
		case 50:
			consultar();
			break;
		case 51:
			system("cls");
			printf("\nFIM\n");
			return 0;
			break;
	}
    }while(loop==0);
}
