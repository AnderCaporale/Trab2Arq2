#include "aritmeticas.h"
#include <stdio.h>
#include "erro.h"

//Soma os 2 primeiros elementos da pilha
int ADD(int pilha[], const int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        ERROR(ERROR_NOT_ENOUGH_OPERANDS_FOR_ADDITION);
        return 1;
    }
    else {
        return pilha[*pTopo] + pilha[*pTopo - 1];
    }
}


//Faz o Topo da pilha menos o proximo elemento
int SUB(int pilha[], const int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        ERROR(ERROR_NOT_ENOUGH_OPERANDS_FOR_SUBTRACTION);
        return 1;
    }
    else {
        return pilha[*pTopo] - pilha[*pTopo - 1];
    }
}


//Multiplica os 2 primeiros elementos da pilha
int MUL(const int pilha[], const int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        ERROR(ERROR_NOT_ENOUGH_OPERANDS_FOR_MULTIPLICATION);
        return 1;
    }
    else {
        return pilha[*pTopo] * pilha[*pTopo - 1];
    }
}

//Faz o Topo da pilha divido o proximo elemento
int DIV(const int pilha[], const int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        ERROR(ERROR_NOT_ENOUGH_OPERANDS_FOR_DIVISION);
        return 1;
    }
    else {
        //printf("\n %d \n", pilha[*pTopo - 1]);
        return pilha[*pTopo] / pilha[*pTopo - 1];
    }
}

//Faz o módulo do Topo da pilha pelo proximo elemento
int MOD(const int pilha[], const int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        ERROR(ERROR_NOT_ENOUGH_OPERANDS_FOR_MODULO);
        return 1;
    }
    else {
        return pilha[*pTopo] % pilha[*pTopo - 1];
    }
}
