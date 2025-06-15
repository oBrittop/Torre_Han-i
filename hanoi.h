#include HANOI_H
#define PILHA_H

typedef strutc Disco;

void criarDsico(Disco* disco);
void destruir(Disco * disco);
int desempilhar(Disco **pilha)
void empilhar(Disco **pilha, int tamanho)
void showDisco();
void push(Disco *disco);
void pop();
int stackIsEmpty();

#endif