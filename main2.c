#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aritmeticas.c"
#include "logicas.c"
#include "controle.c"
#include "saidas.c"


int main()
{
    int pilha[128] = {};
    int topo = -1, *pTopo = &topo;
    int registrador = 0, *pRegistrador = &registrador;

    char letra;
    int i = 0, j = 0;
    int PeV = 0;
    char linha[25] = {}, num[10] = {}, inst[10] = {};

    FILE *file;
    file = fopen("oi.txt", "r");

    if(file != NULL) {
       while(!feof(file)) {
           letra = fgetc(file);
           if(letra != '\n') {
               if(letra == ';') {PeV = 1;}
               if(PeV != 1) {
                   linha[i] = letra;
                   i++;
                }
            } else {
                if(strlen(linha) > 0) {
                    trataInst(linha, inst, num, i);
                    operacoes(pilha, pTopo, pRegistrador, inst, num);
                }
                
                memset(linha, 0, 25);
                i = 0;
                PeV = 0;
            }
        }
    }

    imprimePilha(pilha, pTopo);
    fclose(file);

    return 0;
}

void trataInst (char linha[], char inst[], char num[], int i) {
    int j;

    for(i = 0; i < strlen(linha); i++) {
        if(linha[i] != ' ') {
            inst[i] = linha[i];
        } else {
            inst[i] = '\0';
            for(j = 0; i < strlen(linha); i++) {
                if(linha[i] != ' '){
                    num[j] = linha[i];
                    j++;
                }
            }
            num[j] = '\0';
            break;
        }
    } 
}



int operacoes(int pilha[], int *pTopo, int *pRegistrador, char inst[], char num[]){

    int valor;

    if (strcmp("ADD", inst) == 0){
        *pRegistrador = ADD(pilha, pTopo);

    } else if(strcmp("SUB", inst) == 0){
        //printf("Fazer subtracao\n");

    } else if(strcmp("CLEAR", inst) == 0){
        CLEAR(pilha, pTopo);

    } else if(strcmp("EXIT", inst) == 0){
        //printf("Programa Encerrado\n");
        return 1;

    } else if(strcmp("PUSH", inst) == 0){
        if (strcmp("$R", num) == 0){
            push(pilha, pTopo, *pRegistrador);
        } else{
            valor = atoi(num);
            push(pilha, pTopo, valor);
        }
        
    } else if(strcmp("POP", inst) == 0){
        pop(pTopo);
    }


    return 0;
    
}



