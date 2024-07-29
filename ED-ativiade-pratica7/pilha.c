#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

void faz_pilha_vazia(TipoPilha* pilha){

    pilha -> topo = NULL;
    pilha -> tamanho = 0;

}

int empilha(TipoPilha* pilha, tipoElemento elemen){

    Celula* p;

    p = (Celula*)malloc(sizeof(Celula));

    if(p==NULL)
        return 0;

    p -> chave = elemen;
    p -> prox = pilha -> topo;

    pilha -> topo = p;
    pilha -> tamanho++;

    return 1;

}

int desempilha(TipoPilha* pilha, tipoElemento* elemen){

    if(pilha -> tamanho == 0)
        return 0;

    Celula* q = pilha -> topo;

    *elemen = q -> chave;

    pilha -> topo = q -> prox;

    free(q);

    pilha -> tamanho--;

    return 1;

}

int tamanhopilha(TipoPilha* pilha){

    return pilha -> tamanho;

}

void imprime_pilha(TipoPilha* pilha){

    Celula* prox = pilha -> topo;

    for(int i = 1; i <= pilha -> tamanho; i++){

        printf("%i ", prox -> chave);

        prox = prox -> prox;

    }

}
