//Main lendo do console e do arquivo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aritmeticas.h"
#include "logicas.h"
#include "controle.h"
#include "saidas.h"
#include "linhas.h"
#include "erro.h"
#include "rotulos.h"
#include "salto.h"


int operacoes(int pilha[], int *pTopo, int registradores[], char inst[], char num[], int *pc, Rotulos rotulos);

void trataInst(char linha[], char inst[], char num[]);

void toUpperCaseStr(char *str);

int main() {
    int pilha[128] = {};
    int topo = -1, *pTopo = &topo;
    char entrada[16];

    int menu = 0;

    int numLinha;
    char num[10], inst[10];
    char nomeArquivo[20];
    int registradores[5];


    while (1) {
        // Resetar o processador
        topo = -1;
        for (int k = 0; k < 5; k++)
            registradores[k] = 0;

        // Resetar variaveis de leitura
        numLinha = 1;

        // Mostrar o menu
        printf("MENU\n");
        printf("1 - Escrever no console\n");
        printf("2 - Ler arquivo\n");
        printf("3 - Sair\n");
        fflush(stdout);
        scanf("%d", &menu);
        fflush(stdin);

        if (menu == 1) {
            while (1) {
                printf("> ");
                fflush(stdout);

                //Pega a entrada
                gets(entrada);
                toUpperCaseStr(entrada);

                //Trata a instrucao
                trataInst(entrada, inst, num);
                if (operacoes(pilha, pTopo, registradores, inst, num, &numLinha, NULL)) {
                    printf("\n\nFinalizado com erro.\n\n");
                    break;
                }

                // Limpa a entrada
                fflush(stdin);
            }
        } else if (menu == 2) {
            FILE *file;

            // Lê o arquivo
            printf("Digite o nome do arquivo: ");
            scanf("%s", nomeArquivo);
            file = fopen(nomeArquivo, "r");

            // Se nao achar o arquivo, volta para o menu
            if (file == NULL) {
                printf("Arquivo nao encontrado.\n");
                continue;
            }

            int quantidadeDeLinhas;
            char **linhas = readLines(file, &quantidadeDeLinhas);
            int pc = 0;

            Rotulos rotulos = criarRotulos();
            int abortarOperacao = 0;

            for (int i = 0; i < quantidadeDeLinhas; ++i) {
                if (linhas[i][0] == ':') {
                    if (!registrarRotulos(rotulos, linhas[i] + 1, i)) {
                        ERROR(ERROR_LABEL_ALREADY_DEFINED);
                        printf(" (%s)", linhas[i] + 1);
                        abortarOperacao = 1;
                        break;
                    }
                }
            }

            while (!abortarOperacao && pc < quantidadeDeLinhas) {
                if (strlen(linhas[pc]) == 0) {
                    pc++;
                    continue;
                }

                trataInst(linhas[pc], inst, num);
                if (operacoes(pilha, pTopo, registradores, inst, num, &pc, rotulos)) {
                    printf("\n\nFinalizado com erro.\n\n");
                    menu = -1;
                    break;
                }
            }

            // Livrar a memória das linhas
            for (int j = 0; j < quantidadeDeLinhas; ++j)
                free(linhas[j]);
            free(linhas);

            // Livrar a memória dos rótulos
            destruirRotulos(&rotulos);

            // Fechar o arquivo
            fclose(file);

            printf("\nFIM DO ARQUIVO\n\n");
        } else if (menu == 3) {
            printf("\nPrograma Encerrado\n");
            return 0;
        } else {
            printf("Escolha uma das opcoes acima.\n\n");
        }
    }
}

//Função para separar as palavras lidas do arquivo
void trataInst(char linha[], char inst[], char num[]) {
    const unsigned int stringLength = strlen(linha);
    int i = 0;
    int instIndex = 0;
    int numIndex = 0;

    // Remover espaços no começo da linha
    while (i < stringLength && linha[i] == ' ')
        i++;

    // Pegar a instrucao
    for (; i < stringLength; i++) {
        if (linha[i] == ' ' || linha[i] == '\n')
            break;
        inst[instIndex++] = linha[i];
    }
    inst[instIndex] = '\0';  //Coloca um fim de linha no ultimo caractere da instrucao

    // Pegar os argumentos da instrucao
    if (strcmp("MOV", inst) == 0) {
        for (; i < stringLength; i++) {
            if (linha[i] == ' ' || linha[i] == ',')
                continue;
            num[numIndex++] = linha[i];
        }
    } else {
        for (; i < stringLength; i++) {
            if (linha[i] == ' ')
                continue;
            num[numIndex++] = linha[i];
        }
    }
    num[numIndex] = '\0';  //Coloca um fim de linha no ultimo caractere do numero ou registrador
}

int operacoes(int pilha[], int *pTopo, int registradores[], char inst[], char num[], int *pc, Rotulos rotulos) {
    int numLinha = (*pc) + 1;
    int valor;

    if (inst[0] == ':') { // Ignorar rotulos

    } else if (strcmp("ADD", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            registradores[0] = ADD(pilha, pTopo, numLinha);  //Faz a soma e salva no registrador
        }
    } else if (strcmp("SUB", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            registradores[0] = SUB(pilha, pTopo, numLinha);
        }
    } else if (strcmp("MUL", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            registradores[0] = MUL(pilha, pTopo, numLinha);
        }
    } else if (strcmp("DIV", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            registradores[0] = DIV(pilha, pTopo, numLinha);
        }
    } else if (strcmp("MOD", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            registradores[0] = MOD(pilha, pTopo, numLinha);
        }
    } else if (strcmp("NOT", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            registradores[0] = NOT(pilha, pTopo);
        }
    } else if (strcmp("OR", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            registradores[0] = OR(pilha, pTopo);
        }
    } else if (strcmp("AND", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            registradores[0] = AND(pilha, pTopo);
        }
    } else if (strcmp("MIR", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            registradores[0] = MIR(pilha, pTopo);
        }
    } else if (strcmp("PUSH", inst) == 0) {

        if (num[0] != '\0') {
            if (*pTopo < 127) {
                if (strcmp("$R", num) == 0 || strcmp("$R0", num) == 0) {        //Se é para salvar o registrador
                    push(pilha, pTopo, registradores[0]);
                } else if (strcmp("$R1", num) == 0) {
                    push(pilha, pTopo, registradores[1]);
                } else if (strcmp("$R2", num) == 0) {
                    push(pilha, pTopo, registradores[2]);
                } else if (strcmp("$R3", num) == 0) {
                    push(pilha, pTopo, registradores[3]);
                } else if (strcmp("$R4", num) == 0) {
                    push(pilha, pTopo, registradores[4]);
                } else {     //Ou um numero
                    int i = 0;
                    valor = 0;

                    int sign = 1;
                    if (num[0] == '-') {
                        sign = -1;
                        i++;
                    } else if (num[0] == '+') {
                        sign = 1;
                        i++;
                    } else if (!('0' <= num[0] && num[0] <= '9')) {
                        ERROR(ERROR_INVALID_ARGUMENT);
                        return 1;
                    }

                    while ('0' <= num[i] && num[i] <= '9') {
                        valor = 10 * valor + (num[i] - '0');
                        i++;
                    }
                    valor *= sign;

                    push(pilha, pTopo, valor);
                }
            } else {
                ERROR(ERROR_STACK_OVERFLOW);
                return 1;
            }
        } else {
            ERROR(ERROR_EXPECTED_1_ARGUMENT);
            return 1;
        }
    } else if (strcmp("POP", inst) == 0) {
        if (num[0] != '\0') {
            ERROR(ERROR_UNEXPECTED_ARGUMENT);
            return 1;
        } else {
            if (*pTopo == -1) {
                ERROR(ERROR_STACK_UNDERFLOW);
                return 1;
            }
            pop(pTopo);
        }
    } else if (strcmp("MOV", inst) == 0) {
        int reg1, reg2;
        if (strlen(num) < 5) {
            return 0;
        }

        // Isso poderia ser verificado...
        // if (strlen(num) > 6) {
        //    printf("Linha %d 00- - Registrador nao identificado", numLinha);
        //    return 1;
        // }

        if (strlen(num) == 5) {
            if (num[2] == '$') {
                reg1 = 0;
                reg2 = num[4] - '0';
            } else {
                reg2 = 0;
                reg1 = num[2] - '0';
            }
        } else {
            reg1 = num[2] - '0';
            reg2 = num[5] - '0';
        }
        mov(registradores, reg1, reg2);
    } else if (strcmp("OUT", inst) == 0) {
        if (*pTopo == -1) {
            ERROR(ERROR_STACK_OVERFLOW);
            return 1;
        }
        printf("%d\n", OUT(pilha, pTopo));
    } else if (strcmp("REGS", inst) == 0 || strcmp("REG", inst) == 0) {
        regs(registradores);
    } else if (strcmp("STACK", inst) == 0) {
        stack(pilha, pTopo);
    } else if (strcmp("CLEAR", inst) == 0) {
        CLEAR(pilha, pTopo);
    } else if (strcmp("EXIT", inst) == 0) {
        printf("Programa Encerrado");
        return 1;
    } else if (strcmp("JMP", inst) == 0) {
        return JUMP(num, pc, rotulos, numLinha);
    } else if (strcmp("JEQ", inst) == 0) {
        return JUMP_IF_EQUALS(pilha, pTopo, num, pc, rotulos, numLinha);
    } else if (strcmp("JNE", inst) == 0) {
        return JUMP_IF_NOT_EQUALS(pilha, pTopo, num, pc, rotulos, numLinha);
    } else if (strcmp("JGT", inst) == 0) {
        return JUMP_IF_GREATER_THAN(pilha, pTopo, num, pc, rotulos, numLinha);
    } else if (strcmp("JLT", inst) == 0) {
        return JUMP_IF_LOWER_THAN(pilha, pTopo, num, pc, rotulos, numLinha);
    } else {
        ERROR(ERROR_INVALID_INSTRUCTION);
        printf(" (\"%s\")", inst);
//        printf("Linha %d ERRO 001 - Instrucao Invalida ", numLinha);
//        puts(inst);
        return 1;
    }

    (*pc)++;
    return 0;
}

void toUpperCaseStr(char *str) {
    while (*str != '\0')
        toUpperCase(str++);
}