#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define clrscr() (system("cls"))

void gotoxy(int x, int y){ // COORDENADAS PARA WINDOWS
     COORD coord;
     coord.X=(short)x;
     coord.Y=(short)y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/******************************************************************************/
struct REG_CORREDOR{
   int CODIGO;
   char NOME_ATLETA[31];
   char PROVA[100];
   int PESO;
   int ALTURA;
   char RESULTADOS[60];
   int EXCLUIDO;
};
struct REG_CORREDOR CORREDOR;
FILE *ARQCORRE;
int I,NR_CORR,ESCOLHA;
char OPT[2];
char RESP,TECLA;
char SISTEMA[40]="CADASTRO DE CORREDORES - FAC 1, TADS 3oS";
/******************************************************************************/
void line(void);
void center(int LINHA, char *MENSAGEM);
void tela(void);
void mostradados(void);
int PESQUISA(int NUMERO);
int cadastra(void);
int consulta(void);
int editar(void);
int cor(void);
int exclusao(int NUMERO);
/******************************************************************************/
void clearline(void){
     printf("                                                                                 ");
     return;
}
/******************************************************************************/
int main(void)
{
  /*Verifica existencia do arquivo, se nÃ£o existe, cria*/
  char OPCAO;
  if((ARQCORRE=fopen("CADCORRE.DAT","rb+"))==NULL){ 
     ARQCORRE=fopen("CADCORRE.DAT","wb+");		// grava em binário pra segurança 
     fwrite(&CORREDOR,sizeof(struct REG_CORREDOR),1,ARQCORRE);
  }
  do{
	 system("COLOR F0");
     clrscr();
     line();
     center(2,SISTEMA);
     center(4,"MENU DE OPCOES");
     gotoxy (20,7);printf("***************************************");
     gotoxy (20,9);printf("*     Cadastrar...............[1]     *");
     gotoxy(20,11);printf("*     Consultar/Editar........[2]     *");
     gotoxy(20,13);printf("*     Excluir.................[3]     *");
     gotoxy(20,15);printf("*     Finalizar e salvar......[4]     *");
     gotoxy(20,17);printf("***************************************");
     gotoxy(20,19);printf("      Entre com a opcao   ==> ");	 
     scanf("%c",&OPCAO);fflush(stdin);
     switch(OPCAO){
        case '1':cadastra();break;
        case '2':ESCOLHA=0;consultar();break;
        case '3':ESCOLHA=1;consultar();break;
     }
  }while(OPCAO!='4');
  fclose(ARQCORRE);
  gotoxy(1,23);
  return(0);
}
/******************************************************************************/
/*Troca uma linha*/
void line(void){
     int POSICAO;
     for(POSICAO=0;POSICAO<80;POSICAO++)
       printf("+");
     return;
}
/*Centraliza uma mensagem no video em uma determinada linha*/
void center(int LINHA, char *MENSAGEM){
     int COLUNA;
     COLUNA = ((80-strlen(MENSAGEM))/2);
     gotoxy(COLUNA,LINHA);
     printf(MENSAGEM);
     return;
}
/*Apresenta a tela de cadastro e consulta*/
/******************************************************************************/
void tela(void){
     gotoxy(18,10);clearline();
     gotoxy(18,11);clearline();
     gotoxy(18,12);clearline();
     gotoxy(18,13);clearline();
     gotoxy(18,14);clearline();
     gotoxy(18,15);clearline();
     gotoxy(1,10);printf("CODIGO..........:");
     gotoxy(1,11);printf("NOME DO ATLETA..:");
     gotoxy(1,12);printf("PROVA...........:");
     gotoxy(1,13);printf("PESO (Kg).......:");
     gotoxy(1,14);printf("ALTURA (cm).....:");
     gotoxy(1,15);printf("RESULTADOS......:");
     return;
}
/*Mostra os dados quando da consulta ou tentativa de cadastro*/
/******************************************************************************/
void mostradados(void){
     gotoxy(18,10);printf("%d",NR_CORR);
     gotoxy(18,11);printf("%s",CORREDOR.NOME_ATLETA);
     gotoxy(18,12);printf("%s",CORREDOR.PROVA);
     gotoxy(18,13);printf("%d",CORREDOR.PESO);
     gotoxy(18,14);printf("%d",CORREDOR.ALTURA);
     gotoxy(18,15);printf("%s",CORREDOR.RESULTADOS);
     return;
}
/******************************************************************************/
int pesquisa(int NUMERO){
    int ACHOU = 0;
    rewind(ARQCORRE);
    while(!feof(ARQCORRE)&&ACHOU!=1){
       fread(&CORREDOR,sizeof(struct REG_CORREDOR),1,ARQCORRE);
       if(NUMERO==CORREDOR.CODIGO)
          ACHOU = 1;
    }
    return(ACHOU);
}
/******************************************************************************/
int exclusao(int NUMERO){

    CORREDOR.EXCLUIDO=1;
    fseek(ARQCORRE , -(long)sizeof(struct REG_CORREDOR), 1);
    fwrite(&CORREDOR,sizeof(struct REG_CORREDOR),1,ARQCORRE);
    printf("Registro excluido! Pressione <Enter> para prosseguir                       ");

    
}
/******************************************************************************/
/*Cadastramento de dados*/
int cadastra(void){
    clrscr();
    line();
    center(2,SISTEMA);
    center(3,"Modulo de Cadastramento\n");
    line();
    gotoxy(28,1);printf("Digite os dados abaixo");
    do{
       gotoxy(1,22);//clearline()
       gotoxy(1,23);//clearline()
       printf("Digite[0] para voltar ao menu                     ");
       tela();
       gotoxy(18,10);fflush(stdin);
       scanf("%d",&NR_CORR);
       gotoxy(1,23);//clearline();
       if(NR_CORR!=0){
          if(pesquisa(NR_CORR)==1)
          {
             /*Apresenta os dados caso exista no arquivo*/
             mostradados();
             gotoxy(1,22);
             if(CORREDOR.EXCLUIDO!=1)printf("Este registro ja existe    ");
             else printf("Este registro foi excluido    ");
             gotoxy(1,23);
             printf("Tecle <Enter> para nova tentativa   ");
             fflush(stdin);
             while((TECLA=getchar())!='\n')
             gotoxy(33,23);
             gotoxy(1,22);clearline();
          }
          else{
             /*Localiza posicao para gravar registro*/
             fseek(ARQCORRE,(long)sizeof(struct REG_CORREDOR),2);
             /*Grava registro*/
             gotoxy(18,11);
             fflush(stdin);fgets(CORREDOR.NOME_ATLETA,31,stdin);
             gotoxy(18,12);
             fflush(stdin);fgets(CORREDOR.PROVA,100,stdin);
             gotoxy(18,13);
             fflush(stdin);scanf("%d",&CORREDOR.PESO);
             gotoxy(18,14);
             fflush(stdin);scanf("%d",&CORREDOR.ALTURA);
             gotoxy(18,15);
             fflush(stdin);fgets(CORREDOR.RESULTADOS,60,stdin);
             CORREDOR.CODIGO=NR_CORR;
             CORREDOR.EXCLUIDO = 0;
             fwrite(&CORREDOR,sizeof(struct REG_CORREDOR),1,ARQCORRE);
             gotoxy(1,23);
             printf("Tecle <Enter> para nova tentativa   ");
             fflush(stdin);
             while((TECLA = getchar())!='\n')
                gotoxy(33,23);
          }
       }
    }
    while(NR_CORR != 0);
    return(0);
}
/******************************************************************************/
/*Consulta dos dados*/
int consultar(void){
    clrscr();
    line();
    center(2,SISTEMA);
    center(3,"Modulo de consulta\n");
    line();
    gotoxy(28,6);printf("Digite o numero do codigo:");
    do{
       gotoxy(1,22);//clearline();
       gotoxy(1,23);//clearline();
       printf("Digite [0] para voltar ao menu                                   ");
       tela();
       gotoxy(18,10);fflush(stdin);scanf("%d",&NR_CORR);
       gotoxy(1,23);//clearline();
       if(NR_CORR != 0){
          I=pesquisa(NR_CORR);
          if(I==1&&CORREDOR.EXCLUIDO==0){
             /*Apresenta os dados caso exista no arquivo*/
             mostradados();
             alterar:
             gotoxy(1,23);clearline();gotoxy(1,23);
             if(ESCOLHA==0)
             {
              printf("Deseja editar esse registro(S/N)?");fflush(stdin);fgets(OPT,2,stdin);
              if(strcmp(OPT,"n")==0||strcmp(OPT,"N")==0){}
              else if(strcmp(OPT,"s")==0||strcmp(OPT,"S")==0){
                editar();
              }
              else{
                gotoxy(1,23);clearline();gotoxy(1,23);
                printf("Digite S ou N! Pressione <Enter> para continuar...   ");
                while((TECLA=getchar())!='\n')
                  gotoxy(33,23);
                goto alterar;
              }
             }
             else
             {
              printf("Deseja excluir esse registro(S/N)?");fflush(stdin);fgets(OPT,2,stdin);
              if(strcmp(OPT,"n")==0||strcmp(OPT,"N")==0){}
              else if(strcmp(OPT,"s")==0||strcmp(OPT,"S")==0)
              {
                gotoxy(1,23);clearline();gotoxy(1,23);
                exclusao(NR_CORR);
              }
              else{
                gotoxy(1,23);clearline();gotoxy(1,23);
                printf("Digite S ou N! Pressione <Enter> para continuar...   ");
                while((TECLA=getchar())!='\n')
                  gotoxy(33,23);
                goto alterar;
              }
             }
             gotoxy(1,23);
             printf("Tecle <Enter> para nova tentativa                    ");
             fflush(stdin);
             while((TECLA=getchar())!='\n')
                gotoxy(33,23);
          }
          else{
             gotoxy(1,22);
             if(CORREDOR.EXCLUIDO!=1)
                printf("Este registro nao esta cadastrado                   ");
             else{
                printf("Este registro esta excluido                         ");
                mostradados();
             }
             gotoxy(1,23);
             printf("Tecle <Enter> para nova tentativa                   ");
             fflush(stdin);
             while((TECLA=getchar())!='\n')
                gotoxy(33,23);
             gotoxy(1,22);
             printf("                                    ");
          }
       }
    }while(NR_CORR!=0);
    return(0);
}
/*****************************************************************************/
/*EdiÃ§Ã£o de dados*/
int editar(void){
   /*AlteraÃ§Ãµes e miscelenia*/
   char OPCAO;
   int achou=2;
   do{
      gotoxy(1,23);printf("[1]NOME_ATLETA|[2]PROVA|[3]PESO|[4]ALTURA|[5]RESULTADOS|[6]Confirma|[7]Abandona:");
      fflush(stdin);OPCAO=getchar();
      switch(OPCAO){
         case '1':
              gotoxy(18,11);printf("                                           ");gotoxy(18,11);
              fflush(stdin);fgets(CORREDOR.NOME_ATLETA,31,stdin);
              break;
         case '2':
              gotoxy(18,12);printf("                                                     ");gotoxy(18,12);
              fflush(stdin);fgets(CORREDOR.PROVA,100,stdin);
              break;
         case '3':
              gotoxy(18,13);printf("                                           ");gotoxy(18,13);
              fflush(stdin);scanf("%d",&CORREDOR.PESO);
              break;
         case '4':
              gotoxy(18,14);printf("                                           ");gotoxy(18,14);
              fflush(stdin);scanf("%d",&CORREDOR.ALTURA);
              break;
         case '5':
              gotoxy(18,15);printf("                                           ");gotoxy(18,15);
              fflush(stdin);fgets(CORREDOR.RESULTADOS,60,stdin);
              break;
         case '6':
              Confirma:
              gotoxy(1,23);clearline();gotoxy(1,23);
              printf("Confirma a edicao desse registro(S/N)?");fflush(stdin);fgets(OPT,2,stdin);
              if(strcmp(OPT,"n")==0||strcmp(OPT,"N")==0){}
              else if(strcmp(OPT,"s")==0||strcmp(OPT,"S")==0){
                 achou=0;
              }
              else{
                 gotoxy(1,23);
                 printf("Digite S ou N! Pressione <Enter> para continuar...       ");
                 while((TECLA=getchar())!='\n')
                   gotoxy(33,23);
                 goto Confirma;
              }
              break;
         case '7':
              Cancela:
              gotoxy(1,23);clearline();gotoxy(1,23);
              printf("Abandona a edicao desse registro(S/N)?");fflush(stdin);fgets(OPT,2,stdin);
              if(strcmp(OPT,"n")==0||strcmp(OPT,"N")==0){}
              else if(strcmp(OPT,"s")==0||strcmp(OPT,"S")==0){
                 achou=1;
              }
              else{
                 gotoxy(1,23);clearline();gotoxy(1,23);
                 printf("Digite S ou N! Pressione <Enter> para continuar...      ");
                 while((TECLA=getchar())!='\n')
                   gotoxy(33,23);
                 goto Cancela;
              }
              break;
      }
      gotoxy(71,23);printf("         ");
   }while(achou!=0&&achou!=1);
   gotoxy(1,23);
   if(achou==0){
      fseek(ARQCORRE , -(long)sizeof(struct REG_CORREDOR), 1);
      fwrite(&CORREDOR,sizeof(struct REG_CORREDOR),1,ARQCORRE);
      printf("Sucesso na alteracao do registro! Pressione <Enter> para prosseguir   ");
   }
   else
   {
      printf("Registro alterado! Pressione <Enter> para prosseguir   ");
   }
   fflush(stdin);
   while((TECLA = getchar())!='\n')
      gotoxy(33,23);
   gotoxy(1,23);clearline();
   return(0);
}
