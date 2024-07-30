#include "fila.h"
#include <stdio.h>

void fazfilavazia(TipoFila* fila){

    fila -> tamanho = 0;
    fila -> cabeca = NULL;

}

int tamanhofila(TipoFila* fila){

    return fila -> tamanho;

}

int enfileira(TipoFila* fila, TipoElemento elemen){

    Celula* p = malloc(sizeof(Celula));

    if(p == NULL)
        return 0;

    p -> chave = elemen;
    p -> prox = NULL;

    if(fila -> cabeca == NULL){

        fila -> cabeca = p;

        fila -> tamanho++;

        return 1;

    }

    Celula* q = fila -> cabeca;

    while(q -> prox != NULL)
        q = q -> prox;

    q -> prox = p;

    fila -> tamanho++;

    return 1;

}


int desenfileira(TipoFila* fila, TipoElemento* elemen) {

    if(fila -> cabeca == NULL)
        return 0;

    Celula* p = fila -> cabeca;
    *elemen = p -> chave;

    fila -> cabeca = p -> prox;

    free(p);

    fila -> tamanho--;

    return 1;

}


void imprimefila(TipoFila* f) {
    if (f -> tamanho == 0) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila: ");
    Celula* temp = f -> cabeca;
    for (int i = 0; i < f -> tamanho; i++) {
        printf("%d ", temp -> chave);
        temp = temp -> prox;
    }
    printf("\n");
}
