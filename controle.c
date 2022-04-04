
//Coloca um numero no topo da pilha e incrementa o topo
void push(int pilha[], int *pTopo, int valor)
{
    if(*pTopo == 129) {
        printf("A pilha esta cheia.\n");
        abort();
    }
    else
    {
        *pTopo = *pTopo + 1;
        pilha[*pTopo] = valor;
    }
}

//Remove um numero do topo da pilha e decrementa o topo
void pop(int *pTopo)
{
    if(*pTopo == -1) {
        printf("A pilha esta vazia.\n");
        abort();
    }
    else
    {
        *pTopo = *pTopo - 1;
    }

}


void mov(int registradores[], int origem, int destino){
    registradores[destino] =  registradores[origem];
}


void regs(int registradores[]){
    int i;
    printf("[");
    for(i=0; i<5; i++){
        printf("%d ", registradores[i]);
    }
    printf("]\n");
}