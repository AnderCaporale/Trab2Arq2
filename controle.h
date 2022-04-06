#pragma once

//Coloca um numero no topo da pilha e incrementa o topo
void push(int pilha[], int *pTopo, int valor);

//Remove um numero do topo da pilha e decrementa o topo
void pop(int *pTopo);

void mov(int registradores[], int origem, int destino);

void regs(int registradores[]);

void stack(int pilha[], const int *pTopo);