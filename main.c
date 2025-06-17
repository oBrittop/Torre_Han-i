#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"
#include <unistd.h> 

// --- Variáveis Globais para o Histórico ---
// O seu arquivo hanoi.c depende destas variáveis para funcionar corretamente.
// O ideal é declará-las aqui no main.c, que é o ponto de entrada do programa.

HistoricoPartida *historicoGlobal = NULL;
const char *NOME_ARQUIVO_HISTORICO = "historico_hanoi.txt";

// --- Funções Auxiliares do Menu ---

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mostrarInstrucoes() {
    system("cls || clear");
    printf("\n=== INSTRUCOES DA TORRE DE HANOI ===\n\n");
    printf("1. O objetivo do jogo e mover todos os discos da estaca 'A' para a estaca 'C'.\n");
    printf("2. Voce so pode mover um disco de cada vez.\n");
    printf("3. Um disco maior NUNCA pode ser colocado sobre um disco menor.\n");
    printf("4. Use a estaca 'B' como auxiliar para os movimentos.\n\n");
    printf("Comandos:\n");
    printf(" - Para mover, digite a letra da estaca de origem e a de destino (ex: 'AB' para mover de A para B).\n");
    printf(" - Para desistir do jogo a qualquer momento, digite 'sair'.\n\n");
    printf("Pressione ENTER para voltar ao menu...");
    limparBuffer();
}

void exibirMenu() {
    system("cls || clear");
    printf("\n##--- JOGO TORRE DE HANOI ---##\n");
    printf(" | 1. Iniciar Novo Jogo      |\n");
    printf(" | 2. Ver Historico          |\n");
    printf(" | 3. Ver Instrucoes         |\n");
    printf(" | 4. Sair                   |\n");
    printf("##---------------------------##\n");
    printf("Escolha uma opcao: ");
}


// --- Função Principal ---

int main() {
    // Tenta carregar o histórico de partidas do arquivo ao iniciar
    carregarHistoricoDoArquivo(&historicoGlobal, NOME_ARQUIVO_HISTORICO);

    int opcao;

    while (1) {
        exibirMenu();

        // Validação da entrada do usuário
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Por favor, digite um numero.\n");
            limparBuffer();
            sleep(1);
            continue;
        }
        limparBuffer(); // Limpa o buffer de entrada para evitar problemas com scanf

        switch (opcao) {
            case 1:
                // A função jogarHanoi() contém todo o loop do jogo
                jogarHanoi();
                break;

            case 2:
                // Exibe a lista de partidas salvas na memória
                exibirHistorico(historicoGlobal);
                break;
            
            case 3:
                // Mostra as regras do jogo
                mostrarInstrucoes();
                break;

            case 4:
                // Salva o histórico em arquivo, libera a memória e encerra
                printf("\nSalvando historico e saindo do jogo. Ate mais!\n");
                salvarHistoricoEmArquivo(historicoGlobal, NOME_ARQUIVO_HISTORICO);
                liberarHistorico(&historicoGlobal);
                return 0; // Encerra o programa com sucesso

            default:
                printf("\nOpcao invalida! Pressione ENTER para tentar novamente.\n");
                limparBuffer();
                break;
        }
    }

    return 0;
}