#include "lista.h"

void fazlistavazia(tipolista* lista){

    *lista = NULL;

}

int insere_lista(tipolista* lista, tipochave chave){

    Celula* p;

    p = malloc(sizeof(Celula));

    p -> chave = chave;
    p -> prox = *lista;

    *lista = p;

    return 1;

}

int busca_e_remove_da_lista(tipolista* lista, tipochave chave){
    if (*lista == NULL)
        return 0;

    Celula* q = *lista;
    Celula* anterior = NULL;

    while (q != NULL && q->chave != chave) {
        anterior = q;
        q = q->prox;
    }

    if (q == NULL)
        return 0;

    if (anterior == NULL) {
        *lista = q -> prox;
    } else {
        anterior -> prox = q -> prox;
    }

    free(q);
    return 1;
}

int tamanho_lista(tipolista* lista){

    Celula* p = *lista;

    int tamanho = 0;

    while(p != NULL){

        tamanho++;

        p = p -> prox;

    }

    return tamanho;

}

int remove_primeiro_da_lista(tipolista* lista, tipochave *chave){

    if(*lista == NULL)
        return 0;

    Celula* primeira = *lista;
    *chave = primeira -> chave;

    *lista = primeira -> prox;

    free(primeira);

    return 1;

}
