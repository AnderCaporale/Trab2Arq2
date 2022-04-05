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
    int topo = -1, *pTopo = &topo;
    int valor, espaco=0, *pEspaco = &espaco;
    char entrada[16];

    int menu = 0;

    char letra;
    int numLinha = 1;
    int i = 0, j = 0;
    int PeV = 0;
    char linha[25] = {}, num[10] = {}, inst[10] = {};
    char nomeArquivo[20];
    int registradores[5] = {0,0,0,0,0};


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
                if (espaco == 1 && entrada[i] != ' ' && entrada[i] != '\n' && entrada[i] != ','){
                    num[j] = entrada[i];
                    j++;
                }
            }
            espaco = 0;

            if (operacoes(pilha, pTopo, registradores, inst, num, numLinha)){
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
                    if(letra != '\n' && letra != EOF) {      //Até o fim da linha
                        if(letra == ';') {PeV = 1;}      //Se chegou em um ; para de salvar
                        if(PeV != 1) {           //Se ainda não chegou em um ;
                            toUpperCase(&letra);
                            linha[i] = letra;
                            i++;
                        }
                    } else {    //Qnd chega no fim da linha
                        
                        if(strlen(linha) > 0) {     //Se leu mais de alguma letra
                            trataInst(linha, inst, num, i);
                            //puts(inst);
                            if (operacoes(pilha, pTopo, registradores, inst, num, numLinha)){
                                menu = -1;
                                break;
                            }
                        }
                        
                        memset(linha, 0, 25);       //Limpa a string para salvar a proxima linha
                        memset(inst, 0, 10);
                        memset(num, 0, 10);
                        i = 0;                      //Reseta marcadores
                        PeV = 0;
                        numLinha++;
                    }
                }
                printf("\nFIM DO ARQUIVO\n");
                
            } else {
                printf("Arquivo nao encontrado.");
            }

            menu = 0;
            fclose(file);

            }

            if(menu == 3){
                printf("\nPrograma Encerrado\n");
                return 0;
            } else if(menu == -1) {
                printf("Finalizado com erro.\n\n");
            } else if(menu == 0) {
                printf("Programa finalizado.\n\n");
            } else {
                printf("Escolha uma das opcoes acima.\n\n");
            }
    }

    printf("\nfinal do programa\n");
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
        if(linha[i] != ' ' && linha[i] != '\n'){       //Enquanto nao ler espaço, salva as letras na string de instrução
            inst[i] = linha[i];
        } else {
            inst[i] = '\0';     //Qnd chega no espaço, coloca um fim de linha na instrução

            if (strcmp("MOV", inst) == 0){
                for(j = 0; i < strlen(linha); i++) {    //Salva o numero ou registrador
                    if(linha[i] != ',' && linha[i] != ' '){       
                        num[j] = linha[i];
                        j++;
                    }
                }
            } else {
                for(j = 0; i < strlen(linha); i++) {    //Salva o numero ou registrador
                    if(linha[i] != ' ' && linha[i] != '\t'){        //Enquanto nao ler espaço, salva valores na string de numeros
                        num[j] = linha[i];
                        j++;
                    }
                }
            }
            num[j] = '\0';  //Coloca um fim de linha para remover o espaço em branco.
            break;
        }
    } 
}


int operacoes(int pilha[], int *pTopo, int registradores[], char inst[], char num[], int numLinha){

    int valor;

    if (strcmp("ADD", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            registradores[0] = ADD(pilha, pTopo, numLinha);  //Faz a soma e salva no registrador
        }

    } else if(strcmp("SUB", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            registradores[0] = SUB(pilha, pTopo, numLinha);
        }
        
    } else if(strcmp("MUL", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            registradores[0] = MUL(pilha, pTopo, numLinha);
        }
        
    } else if(strcmp("DIV", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            registradores[0] = DIV(pilha, pTopo, numLinha);
        }
             
    } else if(strcmp("MOD", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            registradores[0] = MOD(pilha, pTopo, numLinha);  
        }
           
    } else if(strcmp("NOT", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            registradores[0] = NOT(pilha, pTopo);     
        }
             
    } else if(strcmp("OR", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            registradores[0] = OR(pilha, pTopo);     
        }        
        
    } else if(strcmp("AND", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            registradores[0] = AND(pilha, pTopo);    
        }
                  
    } else if(strcmp("MIR", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            registradores[0] = MIR(pilha, pTopo);   
        }
                 
    } else if(strcmp("PUSH", inst) == 0){
        
        if (num[0] != NULL){
            if (*pTopo < 127){        
                if (strcmp("$R", num) == 0){        //Se é para salvar o registrador
                    push(pilha, pTopo, registradores[0]);
                } else if(strcmp("$R1", num) == 0) {
                    push(pilha, pTopo, registradores[1]);
                } else if(strcmp("$R2", num) == 0) {
                    push(pilha, pTopo, registradores[2]);
                } else if(strcmp("$R3", num) == 0) {
                    push(pilha, pTopo, registradores[3]);
                } else if(strcmp("$R4", num) == 0) {
                    push(pilha, pTopo, registradores[4]);
                } else{     //Ou um numero
                    valor = atoi(num);      //Transforma string para numero
                    push(pilha, pTopo, valor);
                }
            } else{
                printf("Linha %d ERRO 004 - Pilha Cheia!\n",numLinha);
                return 1;
            }
        } else {
            printf("Linha %d 000 - Erro de sintaxe. E esperado 1 operando\n",numLinha);
            return 1;
        }

        
    } else if(strcmp("POP", inst) == 0){
        if (num[0] != NULL){
            printf("Linha %d 000 - Erro de sintaxe. É esperado zero operando\n",numLinha);
            return 1;
        } else{
            if (*pTopo == -1){
                printf("Linha %d ERRO 003 - Pilha Vazia!\n",numLinha);
                return 1;
            }
            pop(pTopo);
        }

    } else if(strcmp("MOV", inst) == 0){
        int reg1=0, reg2=0;
        if (strlen(num) < 5){
            return 0;
        }
        if (strlen(num) == 5){
            if (num[2] == '$'){
                reg1 = 0;
                reg2 = num[4] - '0';
            } else{
                reg2 = 0;
                reg1 = num[2] - '0';
            }
        } else {
            reg1 = num[2] - '0';
            reg2 = num[5] - '0';
        }
        mov(registradores, reg1, reg2);

    } else if(strcmp("OUT", inst) == 0){
        if (*pTopo == -1){
            printf("Linha %d ERRO 003 - Pilha Vazia!\n",numLinha);
            return 1;
        }
        printf("%d\n", OUT(pilha, pTopo));

    } else if(strcmp("REGS", inst) == 0){
        regs(registradores);

    } else if(strcmp("CLEAR", inst) == 0){
        CLEAR(pilha, pTopo);            
        
    } else if(strcmp("EXIT", inst) == 0){
        printf("Linha %d Programa Encerrado\n\n",numLinha);
        CLEAR(pilha, pTopo); 
        return 1;

    } else {
        printf("Linha %d ERRO 001 - Instrucao Invalida ",numLinha);
        puts(inst);
        return 1;
    }

    return 0;
    
}


void toUpperCase(char* c) {
    if ('a' <= *c && *c <= 'z')
        *c += 'A' - 'a';
}



