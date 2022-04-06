//Main com leitura de arquivo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aritmeticas.c"
#include "logicas.c"
#include "controle.c"
#include "saidas.c"

int operacoes(int pilha[], int *pTopo, int *pRegistrador, char inst[], char num[]);
void trataInst (char linha[], char inst[], char num[], int i);

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

    if(file != NULL) {      //Se acha o arquivo
       while(!feof(file)) {     //Enquanto nao chegou no fim do arquivo
           letra = fgetc(file);     //Pega letra por letra
           if(letra != '\n') {      //Até o fim da linha
               if(letra == ';') {PeV = 1;}      //Se chegou em um ; para de salvar
               if(PeV != 1) {           //Se ainda não chegou em um ;
                   linha[i] = letra;
                   i++;
                }
            } else {    //Qnd chega no fim da linha
                if(strlen(linha) > 0) {     //Se leu mais de alguma letra
                    trataInst(linha, inst, num, i);
                    operacoes(pilha, pTopo, pRegistrador, inst, num);
                }
                
                memset(linha, 0, 25);       //Limpa a string para salvar a proxima linha
                i = 0;                      //Reseta marcadores
                PeV = 0;
            }
        }
    }

    imprimePilha(pilha, pTopo);
    fclose(file);

    return 0;
}

//Função para separar as palavras lidas do arquivo
void trataInst (char linha[], char inst[], char num[], int i) {
    int j;

    for(i = 0; i < strlen(linha); i++) {
        if(linha[i] != ' ') {       //Enquanto nao ler espaço, salva as letras na string de instrução
            inst[i] = linha[i];
        } else {
            inst[i] = '\0';     //Qnd chega no espaço, coloca um fim de linha na instrução
            for(j = 0; i < strlen(linha); i++) {    //Salva o numero ou registrador
                if(linha[i] != ' '){        //Enquanto nao ler espaço, salva valores na string de numeros
                    num[j] = linha[i];
                    j++;
                }
            }
            num[j] = '\0';  //Coloca um fim de linha para remover o espaço em branco.
            break;
        }
    } 
}



int operacoes(int pilha[], int *pTopo, int *pRegistrador, char inst[], char num[]){

    int valor;

    if (strcmp("ADD", inst) == 0){
        *pRegistrador = ADD(pilha, pTopo, 0);  //Faz a soma e salva no registrador

    } else if(strcmp("SUB", inst) == 0){
        //printf("Fazer subtracao\n");

    } else if(strcmp("CLEAR", inst) == 0){
        CLEAR(pilha, pTopo);            //Limpa a pilha

    } else if(strcmp("EXIT", inst) == 0){
        //printf("Programa Encerrado\n");
        return 1;

    } else if(strcmp("PUSH", inst) == 0){
        if (strcmp("$R", num) == 0){        //Se é para salvar o registrador
            push(pilha, pTopo, *pRegistrador);
        } else{     //Ou um numero
            valor = atoi(num);      //Transforma string para numero
            push(pilha, pTopo, valor);
        }
        
    } else if(strcmp("POP", inst) == 0){
        pop(pTopo);
    }


    return 0;
    
}



