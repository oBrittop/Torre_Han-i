#include <stdio.h>
#include <stdlib.h>

typedef struct Disco {
    int tamanho;
    struct Disco *prox;
} Disco;

Disco *top = NULL;

void criarDisco(Disco* disco) {
    top = disco;
    disco->prox = NULL;
}

void destruir(Disco * disco) {
	if (disco != NULL) {
		free(disco);
	}
}

int desempilhar(Disco **pilha){
    if(*pilha == NULL){
        printf("Pilha Vazia");
        return -1;
    }
    Disco *NoTemporario = *pilha;//Gurada No do Topo
    int valorDesempilhado = NoTemporario->tamanho;
    *pilha = NoTemporario->prox ;// Atualiza com o Prox
    free(NoTemporario);
    return valorDesempilhado;

}

void empilhar(Disco **pilha, int tamanho){
    Disco *novoDisco = malloc(sizeof(Disco));
    if(novoDisco == NULL){
        printf("Erro ao Alocar Memoria!!\n");
        return -1;
    }
    novoDisco->tamanho = tamanho;
    novoDisco->prox = *pilha;
    *pilha = novoDisco;

}



int main() {
    // Exemplo de uso para uma torre (pilha)
    Disco *torre1 = NULL; // Inicia a torre como vazia

    // Empilhando alguns discos
    empilhar(&torre1, 3); // Topo
    empilhar(&torre1, 5);
    empilhar(&torre1, 10); // Base

    // Desempilhando
    printf("Desempilhando um disco...\n");
    int discoRemovido = desempilhar(&torre1);

    if (discoRemovido != -1) {
        printf("O disco de tamanho %d foi removido.\n", discoRemovido);
    }

    // O topo da torre1 agora é o disco de tamanho 5.
    if (torre1 != NULL) {
      printf("O novo disco no topo da torre tem tamanho: %d\n", torre1->tamanho);
    }

    return 0;
}






























































































































































