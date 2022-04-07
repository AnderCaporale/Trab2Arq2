#pragma once

struct s_rotulos {
    char **rotulos;
    int *pc;
    int currentIndex;
    int size;
};

typedef struct s_rotulos TipoRotulos;
typedef struct s_rotulos *Rotulos;

Rotulos criarRotulos();

void destruirRotulos(Rotulos *rotulos);

// Retorna se um rotulo foi registrado.
// Um rotulo apenas nao sera registrado, quando ja existir um rotulo com o mesmo conteudo.
int registrarRotulos(Rotulos rotulos, char *rotulo, int pc);

int pegarLinhaDoRotulo(Rotulos rotulos, char *rotulo);