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


