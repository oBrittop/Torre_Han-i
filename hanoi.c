#include <stdio.h>
#include <stdlib.h>

typedef struct Disco {
    int item;
    struct Disco *prox;
} Disco;

Disco *top = NULL;

void criarDisco(Disco* disco) {
    top = disco;
    disco->prox = NULL;
}