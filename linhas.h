#pragma once

#include <stdio.h>

// Lê uma linha de um arquivo.
// Ignora comentátios, espaços no começo e no fim da linha e espaços repetidos.
// O retorno é terminado por '\0'.
// É necessário livrar a memória da linha retornada com "free(linha)".
char *readLine(FILE *file);

// Lê todas as linhas do arquivo.
// É importante livrar a memória de cada linha e da vetor de linhas com "free(linha)" para cada linha e "free(linhas)" para o vetor.
char **readLines(FILE *file, int *quantidadeDeLinhas);

// Transforma as letras minusculas em letras maiusculas
void toUpperCase(char *c);