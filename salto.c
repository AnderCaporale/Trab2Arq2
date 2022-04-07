#include "salto.h"
#include <stdio.h>
#include "erro.h"

int getNextPC(char *num, int *nextPC, Rotulos rotulos, int numLinha) {
    if (rotulos == NULL) {
        ERROR(ERROR_CONSOLE_DOES_NOT_SUPPORT_JUMPS);
        return 1;
    }

    if ('0' <= num[0] && num[0] <= '9') {
        *nextPC = 0;
        while ('0' <= *num && *num <= '9') {
            *nextPC = (*nextPC) * 10 + ((*num) - '0');
            num++;
        }
        *nextPC -= 1;
    } else {
        *nextPC = pegarLinhaDoRotulo(rotulos, num);
        if (*nextPC < 0) {
            ERROR(ERROR_LABEL_NOT_DEFINED);
            printf(" (%s)", num);
            return 1;
        }
    }

    return 0;
}

int JUMP(char *num, int *pc, Rotulos rotulos, int numLinha) {
    if (num[0] == '\0') {
        ERROR(ERROR_EXPECTED_1_ARGUMENT);
        return 1;
    }

    int valor;
    if (getNextPC(num, &valor, rotulos, numLinha))
        return 1;

    *pc = valor;
    return 0;
}

int JUMP_IF_EQUALS(int *pilha, int *pTopo, char *num, int *pc, Rotulos rotulos, int numLinha) {
    if (num[0] == '\0') {
        ERROR(ERROR_EXPECTED_1_ARGUMENT);
        return 1;
    }

    int valor;
    if (getNextPC(num, &valor, rotulos, numLinha))
        return 1;

    if ((*pTopo) + 1 < 2) {
        ERROR(ERROR_STACK_UNDERFLOW);
        return 1;
    }

    if (pilha[*pTopo] == pilha[(*pTopo)-1])
        *pc = valor;
    else
        (*pc)++;

    return 0;
}

int JUMP_IF_NOT_EQUALS(int *pilha, int *pTopo, char *num, int *pc, Rotulos rotulos, int numLinha) {
    if (num[0] == '\0') {
        ERROR(ERROR_EXPECTED_1_ARGUMENT);
        return 1;
    }

    int valor;
    if (getNextPC(num, &valor, rotulos, numLinha))
        return 1;

    if ((*pTopo) + 1 < 2) {
        ERROR(ERROR_STACK_UNDERFLOW);
        return 1;
    }

    if (pilha[*pTopo] != pilha[(*pTopo)-1])
        *pc = valor;
    else
        (*pc)++;

    return 0;
}

int JUMP_IF_GREATER_THAN(int *pilha, int *pTopo, char *num, int *pc, Rotulos rotulos, int numLinha) {
    if (num[0] == '\0') {
        ERROR(ERROR_EXPECTED_1_ARGUMENT);
        return 1;
    }

    int valor;
    if (getNextPC(num, &valor, rotulos, numLinha))
        return 1;

    if ((*pTopo) + 1 < 2) {
        ERROR(ERROR_STACK_UNDERFLOW);
        return 1;
    }

    if (pilha[*pTopo] > pilha[(*pTopo)-1])
        *pc = valor;
    else
        (*pc)++;

    return 0;
}

int JUMP_IF_LOWER_THAN(const int *pilha, const int *pTopo, char *num, int *pc, Rotulos rotulos, int numLinha) {
    if (num[0] == '\0') {
        ERROR(ERROR_EXPECTED_1_ARGUMENT);
        return 1;
    }

    int valor;
    if (getNextPC(num, &valor, rotulos, numLinha))
        return 1;

    if ((*pTopo) + 1 < 2) {
        ERROR(ERROR_STACK_UNDERFLOW);
        return 1;
    }

    if (pilha[*pTopo] < pilha[(*pTopo)-1])
        *pc = valor;
    else
        (*pc)++;

    return 0;
}