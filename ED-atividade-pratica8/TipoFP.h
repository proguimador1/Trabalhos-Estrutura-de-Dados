#ifndef FP_H
#define FP_H

#include "TipoFilaFIFO.h"
#include "TipoRegistro.h"

typedef struct TipoNo* TipoApontador;

typedef struct TipoNo {
    TipoChave chave;
    TipoApontador esq, dir;
    TipoFilaFIFO fila;
} TipoNo;

typedef TipoNo* TipoFP;

/*1.Função para criar e inicializar uma fila de prioridades vazia (árvore
binária de pesquisa):*/

void criaFP(TipoFP *fp);

/*2.Função para apagar toda a memória alocada para a fila de prioridades.
(você deve fazer um caminhamento pós-fixado na APB, apagando cada nó): */

void apagaFP(TipoFP *fp);

/*3.Função para imprimir os elementos da fila de prioridades em ordem
decrescente (fazer um caminhamento central “invertido” na APB): */

void imprimeFP(TipoFP *fp);

/*Nota do aluno: Alterei o parâmetro para tipo ponteiro,
para não quebrar a o padrão que estava sendo seguido no projeto*/


/*4.Função que insere um novo registro na fila de prioridades:*/

void insereFP(TipoRegistro x, TipoFP *fp);

/*5.Função que remove o registro com a maior chave da fila de prioridades*/

void retiramax(TipoRegistro *x, TipoFP *fp);

#endif
