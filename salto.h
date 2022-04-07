#pragma once

#include "rotulos.h"

int JUMP(char *num, int *pc, Rotulos rotulos, int numLinha);

int JUMP_IF_EQUALS(int *pilha, int *pTopo, char *num, int *pc, Rotulos rotulos, int numLinha);

int JUMP_IF_NOT_EQUALS(int *pilha, int *pTopo, char *num, int *pc, Rotulos rotulos, int numLinha);

int JUMP_IF_GREATER_THAN(int *pilha, int *pTopo, char *num, int *pc, Rotulos rotulos, int numLinha);

int JUMP_IF_LOWER_THAN(const int *pilha, const int *pTopo, char *num, int *pc, Rotulos rotulos, int numLinha);