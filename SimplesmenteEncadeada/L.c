/*
  *Lista Simplesmente Encadeada
  *Autor Helberth Lucas
  *Referência Canal Youtube Rainbowsv
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Lista{
        int num;
        struct Lista *prox;
}L;
void insertL(L **l,int n)
{
    L *lAux;
    lAux = malloc(sizeof(lAux));
    lAux->num=n;

    if(*l == NULL)
    {
        lAux->prox=NULL;
        *l = lAux;
    }else{
        lAux->prox=*l;
        *l=lAux;
    }
}
void showLista(L *l)
{
    L *auxLista;
    auxLista = l;

    do{
                printf("%6d-> ",auxLista->num);
                auxLista = auxLista->prox;
      }while(auxLista!=NULL);
}

int main (void)
{
    L *LISTA = NULL;

    // Preenchendo Lista Automaticamente
    insertL(&LISTA,rand()%100);
    insertL(&LISTA,rand()%100);
    insertL(&LISTA,rand()%100);

    showLista(LISTA);
    free(LISTA);
    printf("\n\n");
    return 0;
}
