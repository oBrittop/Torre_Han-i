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
void mostrarTorres(Estaca *A, Estaca *B, Estaca *C);
int venceu(Estaca *C, int total_discos);
Estaca* getEstaca(char c, Estaca *A, Estaca *B, Estaca *C);
void jogarHanoi();



// --- Estrutura de Dados do Histórico de Partidas ---

typedef struct HistoricoPartida {
    int movimentos;
    char nomeJogador[50];
    int numDiscos;
    char dataHora[20];
    struct HistoricoPartida *prox;
} HistoricoPartida;





// --- Funções de Manipulação do Histórico ---

void gerarDataHora(char *buffer, int bufferSize);
void adicionarHistorico(HistoricoPartida **lista, int movimentos, const char *nome, int discos);
void exibirHistorico(HistoricoPartida *lista);
void buscarHistoricoPorNome(HistoricoPartida *lista, const char *nome);



#endif
