#pragma once

//Retorna o topo da pilha
int OUT(int pilha[], const int *pTopo);

//Função para imprimir a pilha no console.
void imprimePilha(int pilha[], const int *pTopo);

//Função para limpar a pilha, reseta o topo e coloca NULL nas posiçoes da pilha
void CLEAR(int pilha[], int *pTopo);