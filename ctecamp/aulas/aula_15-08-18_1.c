#include<stdio.h>
int main(){
	
	char nome[30], senha[30] = "everton";
	int ver;
	printf ("\nDigite seu nome: ");
	gets(nome);
	
	ver = strcmp(nome,senha);
	
	if (ver == 0){
		
		printf ("\nAcesso OK");	
		
	}else{
		printf ("\nSenha Incorreta");}
		
}
