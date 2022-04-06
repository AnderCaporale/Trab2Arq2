#include "saidas.h"
#include <stdio.h>

//Retorna o topo da pilha
int OUT(int pilha[], const int *pTopo) {
    return pilha[*pTopo];
}


//Função para imprimir a pilha no console.
void imprimePilha(int pilha[], const int *pTopo) {
    int i;

    if (*pTopo == -1) {
        printf("A pilha esta vazia.\n");
    } else {
        printf("\nINICIO PILHA\n");
        for (i = *pTopo; i >= 0; i--)
            printf("%d\n", pilha[i]);
        printf("FIM PILHA\n");
    }
}


//Função para limpar a pilha, reseta o topo e coloca NULL nas posiçoes da pilha
void CLEAR(int pilha[], int *pTopo) {
    for (int i = 0; i < 128; i++)
        pilha[i] = 0;
    *pTopo = -1;
}