#define LISTA_H
#include <stdlib.h>

typedef int tipochave;

typedef struct celula {
tipochave chave;
struct celula* prox;
} Celula;

typedef Celula* tipolista;

void fazlistavazia(tipolista* lista);
int insere_lista(tipolista* lista, tipochave chave);
int busca_e_remove_da_lista(tipolista* lista, tipochave chave);
int tamanho_lista(tipolista* lista);
int remove_primeiro_da_lista(tipolista* lista, tipochave *chave);
