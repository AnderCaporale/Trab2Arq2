void decToBin(int num, int bin[])
{   
    if (num < 0){
        num = -num + 32768;
    }
    
    int aux;

    for (aux = 15; aux >= 0; aux--)
    {
        if (num % 2 == 0)
            bin[aux] = 0;
        else
            bin[aux] = 1;
        num = num / 2;
    }
}

int binToDec(int vetor[]){
    int total = 0;
    int i, j=1;

    for (i=15; i>=1; i--){
        total += vetor[i] * j;
        j*=2;
    }
    if (vetor[0] == 1){
        return -total;
    }
    return total;
}

int NOT(int pilha[], int *pTopo){

    int vetor[16];
    decToBin(pilha[*pTopo], vetor);

    for (int i = 0; i < 16; i++)
        printf("%d", vetor[i]);
    printf("\n");

    for (int i=0; i<16; i++){
        if (vetor[i] == 0){
            vetor[i] = 1;
        } else{
            vetor[i] = 0;
        }
    }

    for (int i = 0; i < 16; i++)
        printf("%d", vetor[i]);
    printf("\n");

    return binToDec(vetor);
}


int MIR(int pilha[], int *pTopo){

    int vetor[16], aux[16], i,j;
    decToBin(pilha[*pTopo], vetor);

    for (i = 0, j=15; i<16; i++, j--){
        aux[i] = vetor[j];
    }

    for (i = 0; i < 16; i++)
        printf("%d", aux[i]);
    printf("\n");

    return binToDec(aux);

}


int OR(int pilha[], int *pTopo){

    int primeiro[16], segundo[16], i, aux[16];

    decToBin(pilha[*pTopo], primeiro);
    decToBin(pilha[*pTopo-1], segundo);

    for (i=0; i<16; i++){
        aux[i] = primeiro[i] || segundo[i];
    }

    for (i = 0; i < 16; i++)
        printf("%d", aux[i]);
    printf("\n");

    return binToDec(aux);
}

int AND(int pilha[], int *pTopo){

    int primeiro[16], segundo[16], i, aux[16];

    decToBin(pilha[*pTopo], primeiro);
    decToBin(pilha[*pTopo-1], segundo);

    for (i=0; i<16; i++){
        aux[i] = primeiro[i] && segundo[i];
    }

    for (i = 0; i < 16; i++)
        printf("%d", aux[i]);
    printf("\n");

    return binToDec(aux);
}