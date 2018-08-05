#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define clrscr() (system("CLS"))

void gotoxy(int x, int y){
     COORD coord;
     coord.X=(short)x;
     coord.Y=(short)y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/******************************************************************************/
struct REG_CLI{
   int CODIGO;
   char NOME[31];
   char ENDERECO[100];
   int CEP;
   int TELEFONE;
   char EMAIL[60];
   int EXCLUIDO;
};
struct REG_CLI CLIENTE;
FILE *ARQCLI;
int I,NR_CLI,ESCOLHA;
char OPT[2];
char RESP,TECLA;
char SISTEMA[33]="PROGRAMA DE CADASTRO DE CLIENTES";
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
  /*Verifica existencia do arquivo, se não existe, cria*/
  char OPCAO;
  if((ARQCLI=fopen("CADCLI.DAT","rb+"))==NULL){
     ARQCLI=fopen("CADCLI.DAT","wb+");
     fwrite(&CLIENTE,sizeof(struct REG_CLI),1,ARQCLI);
  }
  do{
     system("COLOR F0");
     clrscr();
     line();
     center(2,SISTEMA);
     center(3,"Menu de Opcoes");
     gotoxy(26,9);printf("Cadastrar...............[1]");
     gotoxy(26,11);printf("Consultar/Editar........[2]");
     gotoxy(26,13);printf("Excluir.................[3]");
     gotoxy(26,15);printf("Finalizar e salvar......[4]");
     gotoxy(26,17);printf("Entre com a opcao:");
     scanf("%c",&OPCAO);fflush(stdin);
     switch(OPCAO){
        case '1':cadastra();break;
        case '2':ESCOLHA=0;consultar();break;
        case '3':ESCOLHA=1;consultar();break;
     }
  }while(OPCAO!='4');
  fclose(ARQCLI);
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
     gotoxy(1,10);printf("Codigo......:");
     gotoxy(1,11);printf("Nome........:");
     gotoxy(1,12);printf("Endereco....:");
     gotoxy(1,13);printf("CEP.........:");
     gotoxy(1,14);printf("Telefone....:");
     gotoxy(1,15);printf("E-Mail......:");
     return;
}
/*Mostra os dados quando da consulta ou tentativa de cadastro*/
/******************************************************************************/
void mostradados(void){
     gotoxy(18,10);printf("%d",NR_CLI);
     gotoxy(18,11);printf("%s",CLIENTE.NOME);
     gotoxy(18,12);printf("%s",CLIENTE.ENDERECO);
     gotoxy(18,13);printf("%d",CLIENTE.CEP);
     gotoxy(18,14);printf("%d",CLIENTE.TELEFONE);
     gotoxy(18,15);printf("%s",CLIENTE.EMAIL);
     return;
}
/******************************************************************************/
int pesquisa(int NUMERO){
    int ACHOU = 0;
    rewind(ARQCLI);
    while(!feof(ARQCLI)&&ACHOU!=1){
       fread(&CLIENTE,sizeof(struct REG_CLI),1,ARQCLI);
       if(NUMERO==CLIENTE.CODIGO)
          ACHOU = 1;
    }
    return(ACHOU);
}
/******************************************************************************/
int exclusao(int NUMERO){
    /*Exclusão de clientes*/
    
    /*Nota para o professor: Achei dois modos de excluir um registro do arquivo,
    o primeiro foi substituir a struct dos elementos por uma struct vazia e a 
    segunda foi o que está abaixo, que é recopiar o banco. Desse jeito eu pode
    ser que venha a travar pois o numero de instruções executadas é muito maior
    do que do outro modo, mas dessa maneira eu não comprometo a integridade do
    arquivo salvando arquivos com muito lixo dentro.*/
    /*
    FILE *AUX;
    fclose(ARQCLI);
    system("copy CADCLI.DAT DADOS.DAT");
    gotoxy(1,23);clearline();gotoxy(1,23);
    system("del CADCLI.DAT");    
    ARQCLI=fopen("CADCLI.DAT","wb+");
    AUX=fopen("DADOS.DAT","rb+");
    rewind(AUX);  
    while(!feof(AUX)){
       fread(&CLIENTE,sizeof(struct REG_CLI),1,AUX);
       if(NUMERO!=CLIENTE.CODIGO)
          fwrite(&CLIENTE,sizeof(struct REG_CLI),1,ARQCLI);
    }  
    fclose(AUX);
    system("del DADOS.DAT");
    gotoxy(1,23);    
    printf("Registro excluido! Pressione <Enter> para prosseguir   ");
    fflush(stdin);
    while((TECLA = getchar())!='\n')
       gotoxy(33,23);    
    return(0);*/
    
    /*segunda maneira*/
    CLIENTE.EXCLUIDO=1;
    fseek(ARQCLI , -(long)sizeof(struct REG_CLI), 1);
    fwrite(&CLIENTE,sizeof(struct REG_CLI),1,ARQCLI);
    printf("Registro excluido! Pressione <Enter> para prosseguir                       ");
    
    /*Eu poderia setar um flag apontando se ele estivesse sendo excluido ou não
    com a data e hora da exclusão mas eu procurei fazer de um modo simples*/
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
       scanf("%d",&NR_CLI);
       gotoxy(1,23);//clearline();
       if(NR_CLI!=0){
          if(pesquisa(NR_CLI)==1)
          {
             /*Apresenta os dados caso exista no arquivo*/
             mostradados();
             gotoxy(1,22);
             if(CLIENTE.EXCLUIDO!=1)printf("Este registro ja existe    ");
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
             fseek(ARQCLI,(long)sizeof(struct REG_CLI),2);
             /*Grava registro*/
             gotoxy(18,11);
             fflush(stdin);fgets(CLIENTE.NOME,31,stdin);
             gotoxy(18,12);
             fflush(stdin);fgets(CLIENTE.ENDERECO,100,stdin);
             gotoxy(18,13);
             fflush(stdin);scanf("%d",&CLIENTE.CEP);
             gotoxy(18,14);
             fflush(stdin);scanf("%d",&CLIENTE.TELEFONE);
             gotoxy(18,15);
             fflush(stdin);fgets(CLIENTE.EMAIL,60,stdin);
             CLIENTE.CODIGO=NR_CLI;
             CLIENTE.EXCLUIDO = 0;
             fwrite(&CLIENTE,sizeof(struct REG_CLI),1,ARQCLI);
             gotoxy(1,23);
             printf("Tecle <Enter> para nova tentativa   ");
             fflush(stdin);
             while((TECLA = getchar())!='\n')
                gotoxy(33,23);
          }
       }
    }
    while(NR_CLI != 0);
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
       gotoxy(18,10);fflush(stdin);scanf("%d",&NR_CLI);
       gotoxy(1,23);//clearline();
       if(NR_CLI != 0){
          I=pesquisa(NR_CLI);
          if(I==1&&CLIENTE.EXCLUIDO==0){
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
                exclusao(NR_CLI);
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
             if(CLIENTE.EXCLUIDO!=1)
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
    }while(NR_CLI!=0);
    return(0);
}
/*****************************************************************************/
/*Edição de dados*/
int editar(void){
   /*Alterações e miscelenia*/
   char OPCAO;
   int achou=2;
   do{
      gotoxy(1,23);printf("[1]Nome|[2]Endereco|[3]CEP|[4]Telefone|[5]Email|[6]Confirma|[7]Abandona:");
      fflush(stdin);OPCAO=getchar();
      switch(OPCAO){
         case '1':
              gotoxy(18,11);printf("                                           ");gotoxy(18,11);
              fflush(stdin);fgets(CLIENTE.NOME,31,stdin);
              break;
         case '2':
              gotoxy(18,12);printf("                                                     ");gotoxy(18,12);
              fflush(stdin);fgets(CLIENTE.ENDERECO,100,stdin);
              break;
         case '3':
              gotoxy(18,13);printf("                                           ");gotoxy(18,13);
              fflush(stdin);scanf("%d",&CLIENTE.CEP);
              break;
         case '4':
              gotoxy(18,14);printf("                                           ");gotoxy(18,14);
              fflush(stdin);scanf("%d",&CLIENTE.TELEFONE);
              break;
         case '5':
              gotoxy(18,15);printf("                                           ");gotoxy(18,15);
              fflush(stdin);fgets(CLIENTE.EMAIL,60,stdin);
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
      fseek(ARQCLI , -(long)sizeof(struct REG_CLI), 1);
      fwrite(&CLIENTE,sizeof(struct REG_CLI),1,ARQCLI);
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