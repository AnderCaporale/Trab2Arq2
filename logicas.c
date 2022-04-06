#include "logicas.h"
#include <stdio.h>

//Transforma um numero decimal para binario (sinal magnitude)
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

//Transforma um numero binario para decimal
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


//Transforma o numero para binario de depois troca os 1 e 0s
int NOT(int pilha[], const int *pTopo){

    int vetor[16];
    decToBin(pilha[*pTopo], vetor);

    for (int i=0; i<16; i++){
        if (vetor[i] == 0){
            vetor[i] = 1;
        } else{
            vetor[i] = 0;
        }
    }

    return binToDec(vetor);
}


//Transforma o numero para binario de depois inverte a sequencia
int MIR(int pilha[], const int *pTopo){

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


//Transforma os 2 primeiros numeros da pilha pra binario e faz o OR entre eles
int OR(int pilha[], const int *pTopo){

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

//Transforma os 2 primeiros numeros da pilha pra binario e faz o AND entre eles
int AND(int pilha[], const int *pTopo){

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