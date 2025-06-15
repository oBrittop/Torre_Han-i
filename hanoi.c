#include <stdio.h>
#include <stdlib.h>

#define ALTURA_MAX 5
#define LARGURA_TOTAL 30
#define QTD_ESTACAS 3

typedef struct Disco {
    int tamanho;
    struct Disco *prox;
} Disco;

Disco *top = NULL;

typedef struct Estaca {
    Disco *topo;
    char nome;
} Estaca;



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

void desenharJogo(Estaca estacas[]) {
    char matriz[ALTURA_MAX + 2][LARGURA_TOTAL]; // +2 para a base e nomes
    int posicao[] = {2, 12, 22}; 

    // 1. Limpa a matriz com espaços
    memset(matriz, ' ', sizeof(matriz));

    // 2. Prepara cada linha para ser uma string
    for (int i = 0; i < ALTURA_MAX + 2; i++) {
        matriz[i][LARGURA_TOTAL - 1] = '\0';
    }

    // 3. Desenha os discos de cada estaca
    for (int i = 0; i < QTD_ESTACAS; i++) {
        // Desenha a base da estaca e o nome
        matriz[ALTURA_MAX][posicao[i] - 1] = '=';
        matriz[ALTURA_MAX][posicao[i]] = '|';
        matriz[ALTURA_MAX][posicao[i] + 1] = '=';
        matriz[ALTURA_MAX + 1][posicao[i]] = estacas[i].nome;

        Disco *atual = estacas[i].topo;
        int nivel = ALTURA_MAX - 1;

        // Percorre a pilha de discos e desenha na matriz
        while (atual != NULL && nivel >= 0) {
            int tamanhoDisco = atual->tamanho;
            int inicio = posicao[i] - (tamanhoDisco / 2);

            for(int j = 0; j < tamanhoDisco; j++){
                matriz[nivel][inicio + j] = '=';
            }

            // Vai para o próximo disco e sobe um nível na matriz
            atual = atual->prox;
            nivel--;
        }
    }


    system("clear || cls"); 
    printf("--- TORRE DE HANOI ---\n");
    for (int i = 0; i < ALTURA_MAX + 2; i++) {
        printf("%s\n", matriz[i]);
    }
    printf("----------------------\n");
}


int main() {
    Estaca estacas[QTD_ESTACAS];
    estacas[0] = (Estaca){.topo = NULL, .nome = 'A'};
    estacas[1] = (Estaca){.topo = NULL, .nome = 'B'};
    estacas[2] = (Estaca){.topo = NULL, .nome = 'C'};

    int numDiscos = 3;

    // Empilha os discos na primeira torre (maior para o menor)
    for (int i = numDiscos; i > 0; i--) {
        empilhar(&estacas[0].topo, i * 2 + 1); // Tamanhos ímpares para centralizar bem
    }

    // Exibe o estado inicial do jogo
    desenharJogo(estacas);

    // Exemplo de movimento: Mover de A para B
    printf("Movendo disco do topo de A para B...\n");
    int discoMovido = desempilhar(&estacas[0].topo);
    if(discoMovido != -1) {
        empilhar(&estacas[1].topo, discoMovido);
    }
    getchar(); // Pausa para ver o movimento

    // Exibe o jogo após o movimento
    desenharJogo(estacas);

    return 0;
}





























































































































































