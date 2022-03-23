#include <stdio.h>
#include <stdlib.h>

typedef struct structPilha{
    int dado;
    struct TPtPilha *elo;
} PILHA;



void InicializaPilha (PILHA *Topo);
int Vazia (PILHA *Topo);
void ImprimirPilha (PILHA *Topo);
PILHA* PushPilha (PILHA *Topo, int Dado);
int PopPilha (PILHA **Topo, int *Dado);
int ConsultaPilha (PILHA *Topo);
PILHA* DestroiPilha (PILHA *Topo);



void InicializaPilha (PILHA *Topo)
{
    return NULL;
}


void ImprimirPilha (PILHA *Topo)
{
    PILHA *ptaux;

    if (Topo != NULL)
    {
    puts("---Imprimindo pilha---");
    for (ptaux=Topo; ptaux!=NULL; ptaux=ptaux->elo)
        printf("%d\n",ptaux->dado);
    puts("-------Fim pilha------");
    }
    else
    puts("Pilha vazia");

}


PILHA* PushPilha (PILHA *Topo, int Dado)
{
    PILHA *novo; //novo elemento

    /*aloca um novo nodo */
    novo = (PILHA*) malloc(sizeof(PILHA));

    /*insere a informa��o no novo nodo*/
    novo->dado = Dado;

    /*encaeia o elemento*/
    novo->elo = Topo;
    Topo = novo;
    return Topo;
}


int PopPilha (PILHA **Topo, int *Dado) //retorna 1 se exclui e zero se n�o exclui
{
   PILHA* ptaux;

   if (Topo == NULL)
     return 0;   //n�o tem nada na pilha
   else
   {
        //*Dado = (*Topo)->dado;     // devolve o valor do topo
        ptaux = *Topo;          //guarda o endere�o do topo
        *Topo = (*Topo)->elo;     //o pr�ximo passa a ser o topo
        free(ptaux);           //libera o que estava no topo
        //ptaux=NULL;
        return 1;
   }
}

int ConsultaPilha (PILHA *Topo)
{
 if (Topo==NULL)
   return 0;
 else
   return Topo->dado;

}

PILHA* DestroiPilha (PILHA *Topo)
{
    PILHA *ptaux;
    while (Topo != NULL)
    {
        ptaux = Topo;          //guarda o endere�o do topo
        Topo = Topo->elo;     //o pr�ximo passa a ser o topo
        free(ptaux);           //libera o que estava no topo
    }
    return NULL;
}



