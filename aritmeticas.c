//Soma os 2 primeiros elementos da pilha
int ADD(int pilha[], int *pTopo)
{
    if(*pTopo < 1) 
    {
        printf("ERRO 005 - Operando insuficientes para realizar a soma.\n");
        return 1;
    }
    else {
        return pilha[*pTopo] + pilha[*pTopo - 1];
    }
}


//Faz o Topo da pilha menos o proximo elemento
int SUB(int pilha[], int *pTopo)
{
    if(*pTopo < 1) 
    {
        printf("ERRO 005 - Operando insuficientes para realizar a subtracao.\n");
        return 1;
    }
    else {
        return pilha[*pTopo] - pilha[*pTopo - 1];
    }
}


//Multiplica os 2 primeiros elementos da pilha
int MUL(int pilha[], int *pTopo)
{
    if(*pTopo < 1) 
    {
        printf("ERRO 005 - Operando insuficientes para realizar a multiplicacao.\n");
        return 1;
    }
    else {
        return pilha[*pTopo] * pilha[*pTopo - 1];
    }
}

//Faz o Topo da pilha divido o proximo elemento
int DIV(int pilha[], int *pTopo)
{
    if(*pTopo < 1) 
    {
        printf("ERRO 005 - Operando insuficientes para realizar a divisao.\n");
        return 1;
    }
    else {
        return pilha[*pTopo] / pilha[*pTopo - 1];
    }
}

//Faz o módulo do Topo da pilha pelo proximo elemento
int MOD(int pilha[], int *pTopo)
{
    if(*pTopo < 1) 
    {
        printf("ERRO 005 - Operando insuficientes para realizar o modulo.\n");
        return 1;
    }
    else {
        return pilha[*pTopo] % pilha[*pTopo - 1];
    }
}
