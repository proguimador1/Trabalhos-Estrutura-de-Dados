#ifndef FILAFIFO_H
#define FILAFIFO_H

#include "TipoRegistro.h"

typedef struct RegistroFila* ApontadorFila;

typedef struct RegistroFila {
    TipoRegistro item;
    ApontadorFila prox;
} RegistroFila;

typedef struct {
    ApontadorFila primeiro;
    ApontadorFila ultimo;
} TipoFilaFIFO;

void criaFilaFIFO(TipoFilaFIFO *f); /*cria *f vazia*/
int vaziaFilaFIFO(TipoFilaFIFO *f); /*retorna true se a fila *f estiver vazia; false caso contrário*/
void imprimeFilaFIFO(TipoFilaFIFO *f); /*imprime os itens da fila *f */
void apagaFilaFIFO(TipoFilaFIFO *f); /*libera a memória alocada pela fila *f, retirando todos os
elementos que houver */
void enfileiraFilaFIFO(TipoFilaFIFO *f, TipoRegistro item); /* enfileira o retistro item na filaFIFO *f.
*/
int desenfileiraFilaFIFO(TipoFilaFIFO *f, TipoRegistro *item); /* retorna 0 se *f estava vazia; 1 se
desenfileirou o registro *item da filaFIFO *f. */

#endif
