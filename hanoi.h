#ifndef HANOI_GAME_H
#define HANOI_GAME_H

#define ALTURA_MAX 5
#define LARGURA_TOTAL 30
#define QTD_ESTACAS 3
#define ESTACA_VAZIA 999 // Valor sentinela para estaca vazia


typedef struct Disco {
    int tamanho;
    struct Disco *prox;
} Disco;


typedef struct Estaca {
    Disco *topo;
    char nome;
} Estaca;



// --- Funções de Manipulação da Pilha (Hanói) ---
int empilhar(Disco **pilha, int tamanho);
int desempilhar(Disco **pilha);
int topo(Estaca *estaca);
int estacaEstaVazia(Estaca *estaca);
void liberarDiscosEstaca(Estaca *estaca); // Para liberar a memória dos discos de uma estaca


// --- Funções de Exibição e Lógica do Jogo de Hanói ---
void preencherMatriz(Estaca *estaca, char matriz[ALTURA_MAX][20]);




// --- Estrutura de Dados do Histórico de Partidas ---





// --- Funções de Manipulação do Histórico ---





#endif