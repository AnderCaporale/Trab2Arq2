#include "linhas.h"
#include <stdlib.h>

struct s_expandable_char_buffer {
    char *buffer;
    int length;
    int currentIndex;
};

typedef struct s_expandable_char_buffer CharBuffer;

CharBuffer *createCharBuffer();

void ensureCapacity(CharBuffer *charBuffer, int capacity);

void putChar(CharBuffer *charBuffer, char c);

char *getBuffer(CharBuffer **charBuffer);

char *readLine(FILE *file) {
    int inComment = 0;
    CharBuffer *charBuffer = createCharBuffer();
    char *line;
    int inSpace = 0;

    while (!feof(file)) {
        char c = (char) getc(file);
        toUpperCase(&c);

        if (c == ' ' || c == '\t') {
            inSpace = 1;
        } else if (c == '\n' || c == '\0' || c == EOF) {
            break;
        } else if (inComment) {
            continue;
        } else if (c == ';') {
            inComment = 1;
        } else {
            if (inSpace && charBuffer->currentIndex > 0)
                putChar(charBuffer, ' ');
            inSpace = 0;
            putChar(charBuffer, c);
        }
    }

    line = getBuffer(&charBuffer);
    return line;
}

char **readLines(FILE *file, int *quantidadeDeLinhas) {
    int lineBufferSize = 10;
    char **linhas = (char **) malloc(sizeof(char *) * lineBufferSize);
    char *line;

    *quantidadeDeLinhas = 0;

    while (!feof(file)) {
        line = readLine(file);
        if ((*quantidadeDeLinhas) + 1 > lineBufferSize) {
            int newLineBufferSize = (lineBufferSize * 9) / 8;
            char **newLines = (char **) malloc(sizeof(char *) * newLineBufferSize);
            for (int i = 0; i < lineBufferSize; i++)
                newLines[i] = linhas[i];
            free(linhas);

            linhas = newLines;
            lineBufferSize = newLineBufferSize;
        }
        linhas[(*quantidadeDeLinhas)++] = line;
    }

    return linhas;
}

CharBuffer *createCharBuffer() {
    CharBuffer *charBuffer = (CharBuffer *) malloc(sizeof(CharBuffer));
    charBuffer->length = 32;
    charBuffer->currentIndex = 0;

    char *buffer = (char *) malloc(sizeof(char) * (charBuffer->length));
    charBuffer->buffer = buffer;

    return charBuffer;
}

void ensureCapacity(CharBuffer *charBuffer, int capacity) {
    if (capacity > charBuffer->length) {
        // Compute new length
        int newLength = charBuffer->length;
        while (newLength < capacity)
            newLength = (newLength * 12) / 9;

        // Create new buffer
        char *buffer = (char *) malloc(sizeof(char) * newLength);

        // Copy old buffer to new buffer
        for (int i = 0; i < charBuffer->length; ++i)
            buffer[i] = charBuffer->buffer[i];

        // Free the memory of the new buffer
        free(charBuffer->buffer);

        // Change the pointers to match the new buffer
        charBuffer->buffer = buffer;
        charBuffer->length = newLength;
    }
}

void putChar(CharBuffer *charBuffer, char c) {
    ensureCapacity(charBuffer, charBuffer->currentIndex + 1);
    charBuffer->buffer[charBuffer->currentIndex++] = c;
}

char *getBuffer(CharBuffer **charBuffer) {
    if (charBuffer == NULL)
        return NULL;

    // Adicionar '\0' no fim da linha
    ensureCapacity(*charBuffer, (*charBuffer)->currentIndex + 1);
    (*charBuffer)->buffer[(*charBuffer)->currentIndex++] = '\0';

    // Guardar o ponteiro para o buffer
    char *buffer = (*charBuffer)->buffer;

    // Liberar a memória do struct
    free(*charBuffer);
    charBuffer = NULL;

    // Retornar o ponteiro para o buffer
    return buffer;
}

void toUpperCase(char *c) {
    if ('a' <= *c && *c <= 'z')
        *c += 'A' - 'a';
}