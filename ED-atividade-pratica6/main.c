#include <stdio.h>
#include "fila.h"

int main() {
    TipoFila fila;
    fazfilavazia(&fila);

    int opcao, elem;

    do {
        printf("\nMenu de Opções da Fila:\n");
        printf("0: Parar o programa\n");
        printf("1: Inserir na fila\n");
        printf("2: Retirar da fila\n");
        printf("3: Imprimir a fila\n");
        printf("4: Tamanho da fila\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Programa encerrado.\n");
                break;
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elem);
                if (enfileira(&fila, elem)) {
                    printf("Elemento %d inserido na fila.\n", elem);
                } else {
                    printf("Erro: Falha ao inserir elemento.\n");
                }
                break;
            case 2:
                if (desenfileira(&fila, &elem)) {
                    printf("Elemento %d retirado da fila.\n", elem);
                } else {
                    printf("Erro: Fila vazia.\n");
                }
                break;
            case 3:
                imprimefila(&fila);
                break;
            case 4:
                printf("Tamanho da fila: %d\n", tamanhofila(&fila));
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}
