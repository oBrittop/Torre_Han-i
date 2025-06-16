#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "hanoi.h"

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
        return;
    }
    novoDisco->tamanho = tamanho;
    novoDisco->prox = *pilha;
    *pilha = novoDisco;
}
int topo(Estaca *estaca) {
    return estaca->topo ? estaca->topo->tamanho : 999;
}

int estacaEstaVazia(Estaca *estaca) {
    return estaca->topo == NULL;
}

void liberarDiscosEstaca(Estaca *estaca) {
    Disco *atual = estaca->topo;
    Disco *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    estaca->topo = NULL; // topo e NULL apos a liberação
}

void preencherMatriz(Estaca *estaca, char matriz[ALTURA_MAX][20]) {
    for (int i = 0; i < ALTURA_MAX; i++) {
        for (int j = 0; j < 9; j++) matriz[i][j] = ' ';
        matriz[i][9] = '\0';
    }
    Disco *atual = estaca->topo;
    int linha = ALTURA_MAX - 1; // Comeca de baixo para cima
    int count = 0;
    Disco *temp = estaca->topo;

    while(temp != NULL) { // Topo valido chama o prox
        count++;
        temp = temp->prox;
    }
    linha = ALTURA_MAX - count;// atualiza posição do topo
    atual = estaca->topo;// reseta ponteiro 

    while (atual != NULL && linha < ALTURA_MAX) {
    int tam = atual->tamanho;
    int espacos = 5 - tam; // 5 é a metade da largura máxima do disco (9) -1
    int i = 0;

    for (; i < espacos; i++) matriz[linha][i] = ' ';
    for (int j = 0; j < tam * 2 - 1; j++, i++) matriz[linha][i] = '#';
    for (; i < 9; i++) matriz[linha][i] = ' ';
    matriz[linha][i] = '\0';

    atual = atual->prox;
    linha++;
    }
}

























// int main() {
//     Estaca estacas[QTD_ESTACAS];
//     estacas[0] = (Estaca){.topo = NULL, .nome = 'A'};
//     estacas[1] = (Estaca){.topo = NULL, .nome = 'B'};
//     estacas[2] = (Estaca){.topo = NULL, .nome = 'C'};

//     int numDiscos = 3;

//     // Empilha os discos na primeira torre (maior para o menor)
//     for (int i = numDiscos; i > 0; i--) {
//         empilhar(&estacas[0].topo, i * 2 + 1); // Tamanhos ímpares para centralizar bem
//     }

//     // Exibe o estado inicial do jogo
//     desenharJogo(estacas);

//     // Exemplo de movimento: Mover de A para B
//     printf("Movendo disco do topo de A para B...\n");
//     int discoMovido = desempilhar(&estacas[0].topo);
//     if(discoMovido != -1) {
//         empilhar(&estacas[1].topo, discoMovido);
//     }
//     getchar(); // Pausa para ver o movimento

//     // Exibe o jogo após o movimento
//     desenharJogo(estacas);

//     return 0;
// }





























































































































































