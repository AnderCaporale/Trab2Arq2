#pragma once


//Soma os 2 primeiros elementos da pilha
int ADD(int pilha[], const int *pTopo, int numLinha);

//Faz o Topo da pilha menos o proximo elemento
int SUB(int pilha[], const int *pTopo, int numLinha);

//Multiplica os 2 primeiros elementos da pilha
int MUL(const int pilha[], const int *pTopo, int numLinha);

//Faz o Topo da pilha divido o proximo elemento
int DIV(const int pilha[], const int *pTopo, int numLinha);

//Faz o módulo do Topo da pilha pelo proximo elemento
int MOD(const int pilha[], const int *pTopo, int numLinha);