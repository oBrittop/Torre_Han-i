#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

void mostrarInstrucoes() {
    printf("\n===== INSTRUÇÕES =====\n");
    printf("1. O objetivo do jogo é mover todos os discos da estaca A para a estaca C.\n");
    printf("2. Você pode mover apenas um disco por vez.\n");
    printf("3. Um disco maior nunca pode ser colocado sobre um menor.\n");
    printf("4. Exemplo de jogada: AB (move disco do topo de A para B)\n");
    printf("5. Para desistir, digite 'sair' durante o jogo.\n\n");
    system("pause");
}

void mostrarCreditos() {
    printf("\n===== CRÉDITOS =====\n");
    printf("Projeto de Estrutura de Dados - Torre de Hanoi\n");
    printf("Participantes:\n");
    printf("- Gustavo Barbosa (implementação do menu e integração)\n");
    printf("- [Outros nomes aqui se desejar incluir sua equipe]\n");
    printf("Professor: [Nome do Professor]\n");
    printf("Universidade Católica de Brasília - 2025\n\n");
    system("pause");
}

int main() {
    int opcao;

    do {
        system("cls || clear");
        printf("=== TORRE DE HANOI ===\n");
        printf("1. Iniciar jogo\n");
        printf("2. Instruções\n");
        printf("3. Créditos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogarHanoi();
                break;
            case 2:
                mostrarInstrucoes();
                break;
            case 3:
                mostrarCreditos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                system("pause");
        }
    } while (opcao != 0);

    return 0;
}
