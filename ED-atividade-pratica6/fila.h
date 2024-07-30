#include <stdlib.h>

#define MAX_SIZE 100

typedef int TipoElemento;

typedef struct celula{

    TipoElemento chave;

    struct celula* prox;

}Celula;

typedef struct{

    int tamanho;

    Celula* cabeca;

}TipoFila;

void fazfilavazia(TipoFila* fila);
int tamanhofila(TipoFila* fila);
int desenfileira(TipoFila* fila, TipoElemento* elemen);
int enfileira(TipoFila* fila, TipoElemento elemen);
void imprimefila(TipoFila* f);
