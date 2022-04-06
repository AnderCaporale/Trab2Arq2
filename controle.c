#include "controle.h"
#include <stdio.h>
#include <stdlib.h>

//Coloca um numero no topo da pilha e incrementa o topo
void push(int pilha[], int *pTopo, int valor) {
    if (*pTopo == 129) {
        printf("A pilha esta cheia.\n");
        abort();
    } else {
        *pTopo = *pTopo + 1;
        pilha[*pTopo] = valor;
    }
}

//Remove um numero do topo da pilha e decrementa o topo
void pop(int *pTopo) {
    if (*pTopo == -1) {
        printf("A pilha esta vazia.\n");
        abort();
    } else {
        *pTopo = *pTopo - 1;
    }

}


void mov(int registradores[], int origem, int destino) {
    registradores[destino] = registradores[origem];
}


void regs(int registradores[]) {
    printf("[");
    for (int i = 0; i < 5; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", registradores[i]);
    }
    printf("]\n");
}

void stack(int pilha[], const int *pTopo) {
    int topo = *pTopo;
    printf("[");

    while (topo >= 0) {
        printf("%d", pilha[topo]);
        if (topo != 0)
            printf(" ");
        (topo)--;
    }
    printf("]\n");
}