//Main lendo do console

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aritmeticas.c"
#include "logicas.c"
#include "controle.c"
#include "saidas.c"

int main()
{
    int pilha[128] = {}, i, j;
    int topo = -1, *pTopo = &topo;
    int registrador = 0;
    int valor, espaco=0, *pEspaco = &espaco;
    char entrada[16];
    char aux1[16]={}, aux2[16]={};
   
    while(1){

        gets(entrada);      //Pega a entrada

        for (i=0; i < strlen(entrada); i++){    //Pega a primeira palavra
            if (entrada[i] == ' '){
                break;
            }
            aux1[i] = entrada[i];
        }

        for (i=0, j=0; i < strlen(entrada); i++){   //Pega a segunda palavra
            if (entrada[i] == ' '){
                espaco = 1;
                continue;
            }
            if (espaco == 1){
                aux2[j] = entrada[i];
                j++;
            }
        }
        espaco = 0;
        
        //Faz as comparaçoes para ver qual função chamar
        if (strcmp("ADD", aux1) == 0){
            registrador = ADD(pilha, pTopo);
            printf("%d", registrador);
            
        } else if(strcmp("SUB", entrada) == 0){
            printf("Fazer subtracao\n");

        } else if(strcmp("CLEAR", entrada) == 0){
            CLEAR(pilha, pTopo);

        } else if(strcmp("EXIT", entrada) == 0){
            printf("Programa Encerrado\n");
            break;

        } else if(strcmp("PUSH", aux1) == 0){
            if (strcmp("$R", aux2) == 0){
                push(pilha, pTopo, registrador);
            } else{
                valor = atoi(aux2);
                push(pilha, pTopo, valor);
            }
            
        } else if(strcmp("POP", aux1) == 0){
            pop(pTopo);
        }
        
        limpaEntrada(aux1, aux2, pEspaco);
    }


    imprimePilha(pilha,pTopo);      

    return 0;
}



void limpaEntrada(char aux1[], char aux2[], int *pEspaco){
    int i;

    *pEspaco = 0;
    for(i=0; i<16; i++){
        aux1[i] = NULL;
        aux2[i] = NULL;
    }
}

