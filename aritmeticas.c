//Soma os 2 primeiros elementos da pilha
int ADD(int pilha[], int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        printf("Linha %d ERRO 005 - Operando insuficientes para realizar a soma.\n", numLinha);
        return 1;
    }
    else {
        return pilha[*pTopo] + pilha[*pTopo - 1];
    }
}


//Faz o Topo da pilha menos o proximo elemento
int SUB(int pilha[], int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        printf("Linha %d ERRO 005 - Operando insuficientes para realizar a subtracao.\n", numLinha);
        return 1;
    }
    else {
        return pilha[*pTopo] - pilha[*pTopo - 1];
    }
}


//Multiplica os 2 primeiros elementos da pilha
int MUL(int pilha[], int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        printf("Linha %d ERRO 005 - Operando insuficientes para realizar a multiplicacao.\n", numLinha);
        return 1;
    }
    else {
        return pilha[*pTopo] * pilha[*pTopo - 1];
    }
}

//Faz o Topo da pilha divido o proximo elemento
int DIV(int pilha[], int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        printf("Linha %d ERRO 005 - Operando insuficientes para realizar a divisao.\n", numLinha);
        return 1;
    }
    else {
        //printf("\n %d \n", pilha[*pTopo - 1]);
        return pilha[*pTopo] / pilha[*pTopo - 1];
    }
}

//Faz o módulo do Topo da pilha pelo proximo elemento
int MOD(int pilha[], int *pTopo, int numLinha)
{
    if(*pTopo < 1) 
    {
        printf("Linha %d ERRO 005 - Operando insuficientes para realizar o modulo.\n", numLinha);
        return 1;
    }
    else {
        return pilha[*pTopo] % pilha[*pTopo - 1];
    }
}
