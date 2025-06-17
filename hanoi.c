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

    void mostrarTorres(Estaca *A, Estaca *B, Estaca *C) {
    char matrizA[ALTURA_MAXIMA][20];
    char matrizB[ALTURA_MAXIMA][20];
    char matrizC[ALTURA_MAXIMA][20];

    preencherMatriz(A, matrizA);
    preencherMatriz(B, matrizB);
    preencherMatriz(C, matrizC);

    system("cls");
    printf("\n");

    for (int i = 0; i < ALTURA_MAXIMA; i++) {
        printf("%s\t%s\t%s\n", matrizA[i], matrizB[i], matrizC[i]);
    }

    printf("---------\t---------\t---------\n");
    printf("     A   \t     B   \t     C   \n\n");
}

int venceu(Estaca *C, int total_discos) {
    int count = 0;
    Disco *atual = C->topo;
    while (atual) {
        count++;
        atual = atual->prox;
    }
    return count == total_discos;
}

Estaca* getEstaca(char c, Estaca *A, Estaca *B, Estaca *C) {
    if (c == 'A' || c == 'a') return A;
    if (c == 'B' || c == 'b') return B;
    if (c == 'C' || c == 'c') return C;
    return NULL;
}

void jogarHanoi() {
    Estaca A = {NULL, 'A'};
    Estaca B = {NULL, 'B'};
    Estaca C = {NULL, 'C'};
    int movimentos = 0;
    char nomeJogador[50];

    system("cls");
    printf("--- NOVO JOGO DE TORRE DE HANOI ---\n");
    printf("Digite seu nome de jogador: ");
    scanf("%49s", nomeJogador);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int n;
    do {
        printf("Quantos discos (1 a %d)? ", MAX_DISCOS);
        scanf("%d", &n);
        while ((c = getchar()) != '\n' && c != EOF);
    } while (n < 1 || n > MAX_DISCOS);

    for (int i = n; i >= 1; i--) {
        if (empilhar(&A.topo, i) != 0) {
            printf("Falha critica: nao foi possivel alocar discos. Encerrando o jogo.\n");
            liberarDiscosEstaca(&A); liberarDiscosEstaca(&B); liberarDiscosEstaca(&C);
            return;
        }
    }

    char jogada[5];
    while (1) {
        mostrarTorres(&A, &B, &C);
        printf("Movimentos: %d\n", movimentos);
        printf("Digite a jogada (ex: AB para mover de A para B, ou 'sair' para desistir): ");
        scanf("%4s", jogada);
        while ((c = getchar()) != '\n' && c != EOF);

        if (strcmp(jogada, "sair") == 0) {
            printf("Voce desistiu do jogo.\n");
            liberarDiscosEstaca(&A); liberarDiscosEstaca(&B); liberarDiscosEstaca(&C);
            sleep(2);
            return;
        }

        if (strlen(jogada) != 2) {
            printf("Entrada invalida! Formato esperado: 'XY' para movimentos.\n");
            sleep(1);
            continue;
        }

        Estaca *origem = getEstaca(jogada[0], &A, &B, &C);
        Estaca *destino = getEstaca(jogada[1], &A, &B, &C);

        if (!origem || !destino || origem == destino) {
            printf("Estacas de origem/destino invalidas ou iguais!\n");
            sleep(1);
            continue;
        }

        if (estacaEstaVazia(origem)) {
            printf("A estaca de origem esta vazia!\n");
            sleep(1);
            continue;
        }

        int discoOrigemTam = topo(origem);
        int discoDestinoTam = topo(destino);

        if (discoDestinoTam == ESTACA_VAZIA || discoOrigemTam < discoDestinoTam) {
            int movido = desempilhar(&origem->topo);
            if (movido == -1) {
                printf("Erro interno ao desempilhar.\n");
                sleep(1);
                continue;
            }
            if (empilhar(&destino->topo, movido) != 0) {
                printf("Falha critica: nao foi possivel empilhar o disco. Jogo interrompido.\n");
                liberarDiscosEstaca(&A); liberarDiscosEstaca(&B); liberarDiscosEstaca(&C);
                return;
            }
            movimentos++;
        } else {
            printf("Movimento invalido: nao pode colocar disco maior sobre menor!\n");
            sleep(1);
        }

        if (venceu(&C, n)) {
            mostrarTorres(&A, &B, &C);
            printf("Parabens %s! Voce venceu em %d movimentos!\n", nomeJogador, movimentos);
            adicionarHistorico(&historicoGlobal, movimentos, nomeJogador, n);
            salvarHistoricoEmArquivo(historicoGlobal, NOME_ARQUIVO_HISTORICO);
            printf("Historico salvo.\n");
            liberarDiscosEstaca(&A); liberarDiscosEstaca(&B); liberarDiscosEstaca(&C);
            sleep(3);
            break;
        }
    }
}

void gerarDataHora(char *buffer, int bufferSize) {
    time_t rawtime;
    struct tm *infoTempo;
    time(&rawtime);
    infoTempo = localtime(&rawtime);
    strftime(buffer, bufferSize, "%Y-%m-%d %H:%M:%S", infoTempo);
}

void adicionarHistorico(HistoricoPartida **lista, int movimentos, const char *nome, int discos) {
    HistoricoPartida *novoRegistro = malloc(sizeof(HistoricoPartida));
    if (novoRegistro == NULL) {
        printf("Ocorreu um erro ao alocar a memoria para o historico!!\n");
        return;
    }

     novoRegistro->movimentos = movimentos;
    strncpy(novoRegistro->nomeJogador, nome, sizeof(novoRegistro->nomeJogador) - 1);
    novoRegistro->nomeJogador[sizeof(novoRegistro->nomeJogador) - 1] = '\0';
    novoRegistro->numDiscos = discos;
    gerarDataHora(novoRegistro->dataHora, sizeof(novoRegistro->dataHora));

    novoRegistro->prox = *lista;
    *lista = novoRegistro;
}

void exibirHistorico(HistoricoPartida *lista) {
    system("cls || clear");
    printf("--- HISTORICO DE PARTIDAS ---\n");
    if (lista == NULL) {
        printf("Nenhum historico esta disponivel.\n");
        printf("Pressione ENTER para voltar ao menu...");
        getchar(); getchar();
        return;
    }

    HistoricoPartida *atual = lista;
    while (atual != NULL) {
        printf("-----------------------------\n");
        printf("Jogador: %s\n", atual->nomeJogador);
        printf("Movimentos: %d\n", atual->movimentos);
        printf("Discos: %d\n", atual->numDiscos);  
        printf("Data/Hora: %s\n", atual->dataHora);
        atual = atual->prox;
    }
    printf("-----------------------------\n");
    printf("Pressione ENTER para voltar ao menu...");
    getchar(); getchar();
}

void buscarHistoricoPorNome(HistoricoPartida *lista, const char *nome) {
    system("cls || clear");
    printf("--- BUSCAR PARTIDA POR NOME ---\n");
    if (lista == NULL) {
        printf("Nenhum historico disponivel para busca.\n");
        printf("Pressione ENTER para voltar ao menu...");
        getchar(); getchar();
        return;
    }

    int encontrado = 0;
    HistoricoPartida *atual = lista;
    while (atual != NULL) {
        if (strstr(atual->nomeJogador, nome) != NULL) {
            printf("-----------------------------\n");
            printf("Jogador: %s\n", atual->nomeJogador);
            printf("Discos: %d\n", atual->numDiscos);
            printf("Movimentos: %d\n", atual->movimentos);
            printf("Data/Hora: %s\n", atual->dataHora);
            encontrado = 1;
        }
        atual = atual->prox;
    }

    if (!encontrado) {
        printf("Nenhuma partida encontrada para o jogador '%s'.\n", nome);
    }

    printf("-----------------------------\n");
    printf("Pressione ENTER para voltar ao menu...");
    getchar(); getchar();
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





























































































































































