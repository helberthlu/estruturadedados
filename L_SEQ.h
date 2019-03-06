/*
  * Autor Helberth Lucas
  * Biblioteca SEQ.h Definida para manuazear a Lista
  * Referências c-progressivo-pdf, Estudo Dirigito Linguagem C - José Augusto N. G. Manzano
*/

// Definição da Lista com nome NODE para auxiliar no entendimento dos nos da Lista

struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node node;

int tam; //Tamanho da Lista

//Definição de Funções

void inicia(node *LISTA);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);

void exibeElemento(node *LISTA);
void exibePosicao(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
node *retira(node *LISTA);

void inicia(node *LISTA)
{
 LISTA->prox = NULL;
 tam=0;
}


int vazia(node *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

// Verifica Se tem memoria disponivel para alocar
node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf(" Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf(" Novo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}

void insereFim(node *LISTA)
{
 node *novo=aloca();
 novo->prox = NULL;

 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  node *tmp = LISTA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}

void insereInicio(node *LISTA)
{
 node *novo=aloca();
 node *oldHead = LISTA->prox;

 LISTA->prox = novo;
 novo->prox = oldHead;

 tam++;
}


void libera(node *LISTA)
{
 if(!vazia(LISTA)){
  node *proxNode,
     *atual;

  atual = LISTA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}

void insere(node *LISTA)
{
 int pos, count;
 printf(" Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
 scanf("%d", &pos);

 if(tam==0 && pos == 1)
 {
    insereInicio(LISTA);
 }else if(pos>0 && pos <= tam)
 {
  if(pos==1)
   insereInicio(LISTA);
  else{
        node *atual = LISTA->prox,
        *anterior=LISTA;
        node *novo=aloca();

   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->prox;
   }
   anterior->prox=novo;
   novo->prox = atual;
   tam++;
  }

 }else
  printf(" Elemento invalido\n\n");

  Sleep(1000);
  system("cls");

  return;
}

void exibeElemento(node *LISTA)
{
    int pos;

    printf(" Informe a posicao do elemento: ");
    scanf("%d",&pos);

    system("cls");
    if(vazia(LISTA)){
        printf(" Lista vazia!\n\n");
        Sleep(1500);
        system("cls");
    return ;
 }

    node *tmp;
    tmp = LISTA->prox;
    int i=1;

    printf("\n\##########################################");
    printf("\n \t\tLista\n");
    while( tmp != NULL && i < pos)

    {
         tmp = tmp->prox;
         i++;
    }

    if(tmp == NULL)
    {
        printf(" Elemento Inexistente\n\n");
    }else{
            printf("\n Posicao Encontrada\n");
            printf(" Elemento: %5d\n", tmp->num);
         }
    printf("##########################################\n\n");
}

void exibePosicao(node *LISTA)
{
     int elemento;

    printf(" Informe a valor do elemento: ");
    scanf("%d",&elemento);

    system("cls");
    if(vazia(LISTA)){
        printf("Lista vazia!\n\n");
    return ;
 }

    node *tmp;
    tmp = LISTA->prox;

    int i=0;

    printf("\n\n##########################################");
    printf("\n \t\tLista\n");
    while( tmp != NULL && tmp->num != elemento)
    {
         tmp = tmp->prox;
         i++;
    }

    if(tmp == NULL)
    {
        printf(" Elemento Inexistente\n\n");
    }else{
            printf("\n Elemento Encontrado:\n");
            printf(" Elemento: %5d\n", tmp->num);
            printf(" Na Posicao: %d\n", i+1);
         }

    printf("##########################################\n\n");
}



node *retiraInicio(node *LISTA)
{
 if(LISTA->prox == NULL){
  printf(" Lista ja esta vazia\n");
  return NULL;
 }else{
  node *tmp = LISTA->prox;
  LISTA->prox = tmp->prox;
  tam--;
  return tmp;
 }

}

node *retiraFim(node *LISTA)
{
 if(LISTA->prox == NULL){
  printf("Lista ja vazia\n\n");
  return NULL;
 }else{
  node *ultimo = LISTA->prox,
    *penultimo = LISTA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}

node *retira(node *LISTA)
{
 int opt,count;

 printf(" Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
 scanf("%d", &opt);

 if(opt>0 && opt <= tam){
  if(opt==1)
   return retiraInicio(LISTA);
  else{
        node *atual = LISTA->prox,
        *anterior=LISTA;

   for(count=1 ; count < opt ; count++){
    anterior=atual;
    atual=atual->prox;
   }

  anterior->prox=atual->prox;
  tam--;
  return atual;
  }

 }else{
  printf(" Elemento invalido\n\n");
  Sleep(1500);
  return NULL;
 }
}
