#ifndef HANOI_GAME_H
#define HANOI_GAME_H

#define MAX_DISCOS 5
#define ALTURA_MAXIMA MAX_DISCOS
#define ESTACA_VAZIA 999


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
void mostrarTorres(Estaca *A, Estaca *B, Estaca *C);
int venceu(Estaca *C, int total_discos);
Estaca* getEstaca(char c, Estaca *A, Estaca *B, Estaca *C);
void jogarHanoi();



// --- Estrutura de Dados do Histórico de Partidas ---





// --- Funções de Manipulação do Histórico ---





#endif
