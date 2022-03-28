//Main lendo do console e do arquivo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "aritmeticas.c"
#include "logicas.c"
#include "controle.c"
#include "saidas.c"

int main()
{
    int pilha[128] = {};
    int topo = 125, *pTopo = &topo;
    int registrador = 0, *pRegistrador = &registrador;
    int valor, espaco=0, *pEspaco = &espaco;
    char entrada[16];

    int menu;

    char letra;
    int i = 0, j = 0;
    int PeV = 0;
    char linha[25] = {}, num[10] = {}, inst[10] = {};
    char nomeArquivo[20];

    while(1){

        printf("MENU\n");
        printf("1 - Escrever no console\n");
        printf("2 - Ler arquivo\n");
        printf("3 - Sair\n");
        scanf("%d", &menu);
        fflush(stdin);

        while (menu == 1){
    
            gets(entrada);      //Pega a entrada

            for (i=0; i < strlen(entrada); i++){    //Pega a primeira palavra
                if (entrada[i] == ' '){
                    break;
                }
                inst[i] = entrada[i];
            }

            for (i=0, j=0; i < strlen(entrada); i++){   //Pega a segunda palavra
                if (entrada[i] == ' '){
                    espaco = 1;
                    continue;
                }
                if (espaco == 1){
                    num[j] = entrada[i];
                    j++;
                }
            }
            espaco = 0;

            if (operacoes(pilha, pTopo, pRegistrador, inst, num)){
                menu = -1;
            }

            limpaEntrada(inst, num, pEspaco);

    } while(menu == 2) {

        FILE *file;
        printf("Digite o nome do arquivo: ");
        scanf("%s", nomeArquivo);
        file = fopen(nomeArquivo, "r");

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

        fclose(file);
        }

        if(menu == 3){
            return 0;
        } else if(menu == -1) {
            printf("Finalizado com erro.\n\n");
        }else {
            printf("Escolha uma das opcoes acima.\n\n");
        }
    }

    return 0;
}


void limpaEntrada(char inst[], char num[], int *pEspaco){
    int i;

    *pEspaco = 0;
    for(i=0; i<16; i++){
        inst[i] = NULL;
        num[i] = NULL;
    }
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
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            *pRegistrador = ADD(pilha, pTopo);  //Faz a soma e salva no registrador
        }

    } else if(strcmp("SUB", inst) == 0){
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            *pRegistrador = SUB(pilha, pTopo); 
        }
        
    } else if(strcmp("MUL", inst) == 0){
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            *pRegistrador = MUL(pilha, pTopo);   
        }
        
    } else if(strcmp("DIV", inst) == 0){
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            *pRegistrador = DIV(pilha, pTopo); 
        }
             
    } else if(strcmp("MOD", inst) == 0){
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            *pRegistrador = MOD(pilha, pTopo);   
        }
           
    } else if(strcmp("NOT", inst) == 0){
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            *pRegistrador = NOT(pilha, pTopo);     
        }
             
    } else if(strcmp("OR", inst) == 0){
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            *pRegistrador = OR(pilha, pTopo);     
        }        
        
    } else if(strcmp("AND", inst) == 0){
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            *pRegistrador = AND(pilha, pTopo);    
        }
                  
    } else if(strcmp("MIR", inst) == 0){
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            *pRegistrador = MIR(pilha, pTopo);   
        }
                 
    } else if(strcmp("PUSH", inst) == 0){
        if (num[0] != NULL){
            if (*pTopo < 127){        
                if (strcmp("$R", num) == 0){        //Se é para salvar o registrador
                    push(pilha, pTopo, *pRegistrador);
                } else{     //Ou um numero
                    valor = atoi(num);      //Transforma string para numero
                    push(pilha, pTopo, valor);
                }
            } else{
                printf("ERRO 004 - Fila Cheia!\n");
                return 1;
            }
        } else {
            printf("000 - Erro de sintaxe. E esperado 1 operando\n");
            return 1;
        }
        
    } else if(strcmp("POP", inst) == 0){
        if (num[0] != NULL){
            printf("000 - Erro de sintaxe. É esperado zero operando\n");
            return 1;
        } else{
            if (*pTopo == -1){
                printf("ERRO 003 - Fila Vazia!\n");
                return 1;
            }
            pop(pTopo);
        }

    } else if(strcmp("OUT", inst) == 0){
        if (*pTopo == -1){
            printf("ERRO 003 - Fila Vazia!\n");
            return 1;
        }
        printf("%d\n", OUT(pilha, pTopo));

    } else if(strcmp("CLEAR", inst) == 0){
        CLEAR(pilha, pTopo);            
        
    } else if(strcmp("EXIT", inst) == 0){
        printf("Programa Encerrado\n\n");
        CLEAR(pilha, pTopo); 
        return 1;

    } else {
        printf("ERRO 001 - Instrução Inválida\n\n");
        return 1;
    }

    return 0;
    
}