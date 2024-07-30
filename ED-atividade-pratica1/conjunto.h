#ifndef CONJUNTO_H
#define CONJUNTO_H

#define MAX_SIZE 100

typedef int conjuntoDeInteiros[MAX_SIZE];

void fazConjuntoVazio(conjuntoDeInteiros conjunto);
void imprimeConjunto(conjuntoDeInteiros conjunto);
int insereInteiro(int inteiro, conjuntoDeInteiros conjunto);
int pertenceAoConjunto(int inteiro, conjuntoDeInteiros conjunto);
int removeDoConjunto(int inteiro, conjuntoDeInteiros conjunto);
int maxDoConjunto(int *elem, conjuntoDeInteiros conjunto);
int maxMinDoConjunto(int *elemMax, int *elemMin, conjuntoDeInteiros conjunto);
int maxMinDoConjunto2(int *elemMax, int *elemMin, conjuntoDeInteiros conjunto);
#endif
