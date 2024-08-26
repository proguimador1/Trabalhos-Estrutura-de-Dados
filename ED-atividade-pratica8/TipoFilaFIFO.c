#include "TipoFilaFIFO.h"
#include <stdio.h>

void criaFilaFIFO(TipoFilaFIFO *f){

    f -> primeiro = NULL;
    f -> ultimo = NULL;

}

int vaziaFilaFIFO(TipoFilaFIFO *f){

    if(f->primeiro==NULL && f->ultimo == NULL)
        return 1;

    return 0;

}

void imprimeFilaFIFO(TipoFilaFIFO *f){

    ApontadorFila pont = f -> primeiro;

    while (pont != NULL) {

        printf("%i ", pont->item.chave);

        pont = pont->prox;

    }

}


void apagaFilaFIFO(TipoFilaFIFO *f){

    ApontadorFila pont1 = f -> primeiro;

    ApontadorFila pont2 = NULL;

    while(pont1 != NULL){

        pont2 = pont1;

        pont1 = pont1 -> prox;

        free(pont2);

    }

}

void enfileiraFilaFIFO(TipoFilaFIFO *f, TipoRegistro item){

    ApontadorFila novo = (ApontadorFila)malloc(sizeof(RegistroFila));

    novo -> item = item;
    novo -> prox = NULL;

    if(f -> primeiro == NULL){

        f -> primeiro = novo;

        f -> ultimo = novo;

        return;

    }

    f -> ultimo -> prox = novo;

    f -> ultimo = f -> ultimo -> prox;

}

int desenfileiraFilaFIFO(TipoFilaFIFO *f, TipoRegistro *item){

    if(vaziaFilaFIFO(f))
        return 0;

    ApontadorFila pont = f -> primeiro;

    *item = pont -> item;

    f -> primeiro = f -> primeiro -> prox;

    free(pont);

    return 1;

}
