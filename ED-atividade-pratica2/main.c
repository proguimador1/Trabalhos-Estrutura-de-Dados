#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"
#define TAMANHO_ARRAY 10000
#define NUM_TESTES 50

int main() {
    int array[TAMANHO_ARRAY];
    int comparacoes_total = 0;
    int i, elemento, comparacoes;
    double media_comparacoes;

    for (i = 0; i < TAMANHO_ARRAY; i++) {
        array[i] = i + 1;
    }

    srand(time(NULL));

    for (i = 0; i < NUM_TESTES; i++) {

        elemento = rand() % TAMANHO_ARRAY + 1;

        comparacoes = 0;

        busca_binaria(array, TAMANHO_ARRAY, elemento, &comparacoes);

        comparacoes_total += comparacoes;

    }

    media_comparacoes = (double)comparacoes_total / NUM_TESTES;

    printf("Média de comparações: %.2f\n", media_comparacoes);

    return 0;

}
