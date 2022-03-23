int OUT(int pilha[], int *pTopo){

    return pilha[*pTopo];
}


void imprimePilha(int pilha[], int *pTopo)
{
    int i = 0;

    if(*pTopo == -1)
    {
        printf("A pilha esta vazia.\n");
    }
    else
    {
        printf("\nINICIO PILHA\n");
        for(i = *pTopo; i >= 0; i--)
        {
            printf("%d\n", pilha[i]);
        }
        printf("FIM PILHA\n");
    }
}


void CLEAR(int pilha[], int *pTopo){

    for (int i=0; i<128; i++){
        pilha[i] = NULL;
    }

    *pTopo = -1;

    //printf("\nPILHA LIMPA\n");

}