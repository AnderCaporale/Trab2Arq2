#pragma once

//Transforma um numero decimal para binario (sinal magnitude)
void decToBin(int num, int bin[]);

//Transforma um numero binario para decimal
int binToDec(int vetor[]);

//Transforma o numero para binario de depois troca os 1 e 0s
int NOT(int pilha[], const int *pTopo);

//Transforma o numero para binario de depois inverte a sequencia
int MIR(int pilha[], const int *pTopo);

//Transforma os 2 primeiros numeros da pilha pra binario e faz o OR entre eles
int OR(int pilha[], const int *pTopo);

//Transforma os 2 primeiros numeros da pilha pra binario e faz o AND entre eles
int AND(int pilha[], const int *pTopo);