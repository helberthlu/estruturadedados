/*
    *Autor Helberth Lucas
    *Trabalho Pratica de Estrutura de Dados - Curso Desenvolvimento de Sistemas - Prepara Cursos & Sagatech
    *Referências c-progressivo-pdf, Estudo Dirigito Linguagem C - José Augusto N. G. Manzano
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#include"L_SEQ.h"

// Definições de funções

int menu(void);
void opcao(node *LISTA, int op);
void exibe(node *LISTA);
void esvaziar(node *LISTA);

int main()
{
    //Verifica memoria para criar a Lista

 node *LISTA = (node *) malloc(sizeof(node));
 if(!LISTA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(LISTA);
 int opt;

 do{                //Loop Para Voltar ao menu;
    opt=menu();
    opcao(LISTA,opt);
 }while(opt);

 free(LISTA);       //Libera a memoria
 return 0;
 }
    return 0;
}

int menu(void)
{
  // Menu modificado para ANSI para fechar com ESC

 int opt;
 char tecla;

 system("color A");
 printf("\n\n Para Escolher uma opção basta teclar na opção\n\n",setlocale(LC_ALL,""));
 printf("\n\n\t\t######################\n");
 printf("\t\t#  Escolha Uma Opção #\n");
 printf("\t\t######################\n");
 printf("\t\t# 1. Exibir lista    #\n");
 printf("\t\t# 2. Inserir         #\n");
 printf("\t\t# 3. Remover         #\n");
 printf("\t\t# 4. Exibir Elemento #\n");
 printf("\t\t# 5. Exibir Posicao  #\n");
 printf("\t\t# 6. Esvaziar        #\n");
 printf("\t\t# [ESQ]. Sair        #\n");
 printf("\t\t######################\n\n");
 printf("\t\tOpcao: "); tecla = getch();
 printf("%c",tecla);
 Sleep(100);

 opt=tecla;

 printf("\n");

 return opt;
}

void opcao(node *LISTA, int op)
{

 node *tmp;

 switch(op){
  case 0:
   libera(LISTA);
   break;

  case 49:
   exibe(LISTA);
   break;

  case 50:
   insere(LISTA);
   break;

  case 51:
   tmp= retira(LISTA);
   printf(" Retirado: %3d\n\n", tmp->num);
   Sleep(1500);
   system("cls");

   break;

  case 52:
    exibeElemento(LISTA);
   break;

  case 53:
    exibePosicao(LISTA);
   break;

  case 54:
        esvaziar(LISTA);
  break;

  case 27:
        exit(0);
  break;


  default:

   printf("Comando invalido\n\n");
   Sleep(1500);
   system("cls");
 }
 return;
}
void exibe(node *LISTA)
{
 system("cls");
 if(vazia(LISTA)){
  printf("Lista vazia!\n\n");
  Sleep(1000);
  system("cls");
  return ;
 }

 node *tmp;
 tmp = LISTA->prox;
 printf("\n\n ##########################################");
 printf("\n Lista:");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n         ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
  printf("\n Ordem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);

 printf("\n ##########################################\n\n");
 return;
}
void esvaziar(node *LISTA)
{

    if(vazia(LISTA))
        {
            printf(" Lista ja esta vazia!\n\n");
            Sleep(1500);
            system("cls");
       }
        else{
                int count = tam;

                do{
                    node *tmp = LISTA->prox;
                    LISTA->prox = tmp->prox;
                    tam--;
                    count--;
                    free(tmp);

                    printf("\n\n ESVAZIANDO");
                    for(int i=0;i < 2;i++)
                      {
                        printf("...");
                        Sleep(1500);
                      }

                    if(count==0)
                        break;

                }while(count  <= tam);
                 system("cls");
            }

    return;
}


