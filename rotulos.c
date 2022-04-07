#include "rotulos.h"

#include <stdlib.h>
#include <string.h>

Rotulos criarRotulos() {
    Rotulos labels = (Rotulos) malloc(sizeof(TipoRotulos));
    labels->currentIndex = 0;
    labels->size = 10;
    labels->rotulos = (char **) malloc(sizeof(char *) * labels->size);
    labels->pc = (int *) malloc(sizeof(int) * labels->size);
    return labels;
}

void destruirRotulos(Rotulos *rotulos) {
    free((*rotulos)->rotulos);
    free((*rotulos)->pc);
    free(*rotulos);
    rotulos = NULL;
}

int registrarRotulos(Rotulos rotulos, char *rotulo, int pc) {
    // Se o rotulo ja existir, finalizar a operacao
    if (pegarLinhaDoRotulo(rotulos, rotulo) >= 0)
        return 0;

    // Verificar se ha espaco para um novo rotulo
    if (rotulos->currentIndex + 1 < rotulos->size) {
        // Criar novos buffers
        int newSize = (rotulos->size * 9) / 8;
        char **newLabels = (char**) malloc(sizeof(char*) * newSize);
        int *newLines = (int*) malloc(sizeof(int) * newSize);

        // Copiar dados dos buffers antigos para os novos
        for (int i = 0; i < rotulos->currentIndex; ++i) {
            newLabels[i] = rotulos->rotulos[i];
            newLines[i] = rotulos->pc[i];
        }

        // Deletar os buffers antigosa
        free(rotulos->rotulos);
        free(rotulos->pc);

        // Ligar os ponteiros dos novos buffers
        rotulos->size = newSize;
        rotulos->rotulos = newLabels;
        rotulos->pc = newLines;
    }

    // Inserir o novo rotulo
    rotulos->rotulos[rotulos->currentIndex] = rotulo;
    rotulos->pc[rotulos->currentIndex] = pc;
    rotulos->currentIndex++;

    return 1;
}

int pegarLinhaDoRotulo(Rotulos rotulos, char *rotulo) {
    for (int i = 0; i < rotulos->currentIndex; ++i) {
        if (strcmp(rotulo, rotulos->rotulos[i]) == 0)
            return rotulos->pc[i];
    }
    return -1;
}