#pragma once

#define ERROR(ERROR_TYPE) printf("Linha %d: Erro %s", numLinha, ERROR_TYPE)

// Operacões
#define ERROR_EXPECTED_1_ARGUMENT "000 - Erro de sintaxe (instrucao sem operandos)"
#define ERROR_UNEXPECTED_ARGUMENT "000 - Erro de sintaxe (operando inesperado)"
#define ERROR_INVALID_INSTRUCTION "001 - Instrucao invalida"
#define ERROR_INVALID_ARGUMENT "002 - Argumento invalido"
#define ERROR_STACK_UNDERFLOW "003 - Pilha vazia"
#define ERROR_STACK_OVERFLOW "004 - Pilha cheia"

// Aritmética
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_ADDITION "005 - Operando insuficientes na pilha para realizar a soma"
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_SUBTRACTION "005 - Operando insuficientes na pilha para realizar a subtracao"
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_MULTIPLICATION "005 - Operando insuficientes na pilha para realizar a multiplicacao"
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_DIVISION "005 - Operando insuficientes na pilha para realizar a divisao"
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_MODULO "005 - Operando insuficientes na pilha para realizar o modulo"

// Lógica
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_LOGIC_AND "006 - Operando insuficientes na pilha para realizar o AND"
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_LOGIC_OR "006 - Operando insuficientes na pilha para realizar o OR"
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_LOGIC_NOT "006 - Operando insuficientes na pilha para realizar o NOT"
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_LOGIC_MIRROR "006 - Operando insuficientes na pilha para realizar o MIRROR"

// Comparações
#define ERROR_NOT_ENOUGH_OPERANDS_FOR_COMPARISON "007 - Operando insuficientes na pilha para serem comparados"

// Rotulos
#define ERROR_LABEL_ALREADY_DEFINED "008 - Rotulo definido previamente"
#define ERROR_LABEL_NOT_DEFINED "009 - Salto para um rotulo nao definido"

// Console
#define ERROR_CONSOLE_DOES_NOT_SUPPORT_JUMPS "010 - O modo console nao suporta saltos"