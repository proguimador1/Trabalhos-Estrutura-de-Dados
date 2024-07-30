#include "lista.h"
#include <stdlib.h>


void fazlistavazia(tipolista* lista){

    lista -> tamanho = 0;

    lista -> primeiro = NULL;

}

int insere_lista(tipolista* lista, tipochave chave){

    Celula* p;

    p = malloc(sizeof(Celula));
    p -> chave = chave;
    p -> prox = lista -> primeiro;

    lista -> primeiro = p;
    lista -> tamanho++;

    return 1;

}

int busca_e_remove_da_lista(tipolista* lista, tipochave chave){

    Celula* p;

    p = lista -> primeiro;

    if(p == NULL)
        return 0;

    //removi a operação p=p->prox dessa linha para que fosse possível
    //retirar a última célula adicionada na lista
    if(p -> chave == chave){

        Celula* q = lista -> primeiro;

        lista -> primeiro = p -> prox;

        free(q);

        lista -> tamanho--;

        return 1;

    }

    while(p -> prox != NULL){

        if(p -> prox -> chave == chave){

            Celula* q = p -> prox;

            p -> prox = p -> prox -> prox;

            free(q);

            lista -> tamanho--;

            return 1;

        }

        p = p -> prox;

    }

    return 0;

}
