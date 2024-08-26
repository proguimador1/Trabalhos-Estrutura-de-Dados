#include <stdio.h>
#include <stdlib.h>
#include "TipoFP.h"

void criaFP(TipoFP *fp) {
    *fp = NULL;
}

void apagaFP(TipoFP *fp) {
    if (*fp == NULL) return;

    apagaFP(&(*fp)->esq);
    apagaFP(&(*fp)->dir);

    apagaFilaFIFO(&(*fp)->fila);

    free(*fp);
    *fp = NULL;
}

void imprimeFP(TipoFP *fp) {
    if (*fp == NULL)
        return;

    imprimeFP(&(*fp) -> dir);

    ApontadorFila pont = (*fp) -> fila.primeiro;
    while (pont != NULL) {
        printf("%i ", pont->item.chave);
        pont = pont -> prox;
    }

    imprimeFP(&(*fp)-> esq);
}

void insereFP(TipoRegistro x, TipoFP *fp) {
    if (*fp == NULL) {
        *fp = (TipoNo*) malloc(sizeof(TipoNo));
        if (*fp == NULL) {
            printf("Erro: Falha ao alocar memória.\n");
            return;
        }

        (*fp)->chave = x.chave;
        criaFilaFIFO(&(*fp)->fila);
        enfileiraFilaFIFO(&(*fp)->fila, x);

        (*fp)->esq = NULL;
        (*fp)->dir = NULL;

        return;
    }

    if (x.chave < (*fp)->chave) {
        insereFP(x, &(*fp)->esq);
    } else if (x.chave > (*fp)->chave) {
        insereFP(x, &(*fp)->dir);
    } else {
        enfileiraFilaFIFO(&(*fp)->fila, x);
    }
}

void retiramax(TipoRegistro *x, TipoFP *fp) {
    if (*fp == NULL)
        return;

    if ((*fp)->dir != NULL) {
        retiramax(x, &(*fp)->dir);
        return;
    }

    // Encontrou o maior (mais à direita)
    desenfileiraFilaFIFO(&(*fp)->fila, x);

    // Se a fila FIFO associada ao nó ficou vazia, remove o nó
    if (vaziaFilaFIFO(&(*fp)->fila)) {
        TipoFP temp = *fp;

        if ((*fp)->esq == NULL) {
            *fp = NULL;
        } else {
            *fp = (*fp)->esq;
        }

        free(temp);
    }
}
