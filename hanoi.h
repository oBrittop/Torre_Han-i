#ifndef HANOI_H
#define HANOI_H

typedef struct Disco {
    int tamanho;
    struct Disco *prox;
} Disco;

void criarDisco(Disco* disco);
void destruir(Disco * disco);
int desempilhar(Disco **pilha);
void empilhar(Disco **pilha, int tamanho);
void showPilha(Disco *pilha);
int stackIsEmpty(Disco *pilha);

#endif