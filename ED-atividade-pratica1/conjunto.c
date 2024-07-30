#include "conjunto.h"
#include <stdio.h>


static int tamanho = 0;

void fazConjuntoVazio(conjuntoDeInteiros conjunto){

    tamanho = 0;

}

int pertenceAoConjunto(int inteiro, conjuntoDeInteiros conjunto){

    for(int i=0; i<tamanho; i++)
        if(inteiro == conjunto[i])
            return 1;

    return 0;

}

int insereInteiro(int inteiro, conjuntoDeInteiros conjunto){

    if(!pertenceAoConjunto(inteiro,conjunto) || tamanho == MAX_SIZE)
        return 0;

    conjunto[tamanho] = inteiro;

    tamanho++;

    return 1;

}

int maxDoConjunto(int *elem, conjuntoDeInteiros conjunto){

    if(tamanho==0)
        return 0;

    int max = conjunto[0];

    for(int i=0; i<tamanho; i++)
        if(conjunto[i]>max)
            max = conjunto[i];

    *elem = max;

    return 1;

}

int retornIndexDoElemento(int inteiro, conjuntoDeInteiros conjunto){

    if(!pertenceAoConjunto(inteiro, conjunto))
        return -1;

    for(int i=0; i<tamanho; i++)
        if(conjunto[i] == inteiro)
            return i;

    return;

}

int removeDoConjunto(int inteiro, conjuntoDeInteiros conjunto){

    int index = retornIndexDoElemento(inteiro, conjunto);

    if(index == -1)
        return 0;

    for(int i=index; i<tamanho-1; i++)
        conjunto[i] = conjunto[i+1];

    tamanho--;

    return 1;

}

void imprimeConjunto(conjuntoDeInteiros conjunto){

    for(int i=0; i<tamanho; i++)
        printf("%i", conjunto[i]);

}

int maxMinDoConjunto(int *elemMax, int *elemMin, conjuntoDeInteiros conjunto){

    if (tamanho == 0)
        return 0;

    *elemMax = conjunto[0];
    *elemMin = conjunto[0];

    for(int i = 1; i < tamanho; i++) {

        if (conjunto[i] > *elemMax)
            *elemMax = conjunto[i];

        else if (conjunto[i] < *elemMin)
            *elemMin = conjunto[i];
    }

    return 1;

}

int maxMinDoConjunto2(int *elemMax, int *elemMin, conjuntoDeInteiros conjunto){

    if (tamanho == 0)
        return 0;

    int i, FimDoAnel;

    if ((tamanho & 1) > 0){

        conjunto[tamanho] = conjunto[tamanho - 1];

        FimDoAnel = tamanho;

    }
    else
        FimDoAnel = tamanho - 1;

    if (conjunto[0] > conjunto[1]) {

        *elemMax = conjunto[0];

        *elemMin = conjunto[1];

    }
    else {

        *elemMax = conjunto[1];

        *elemMin = conjunto[0];

    }

    i = 2;

    while(i <= FimDoAnel) {
        if(conjunto[i - 1] > conjunto[i]){

            if(conjunto[i - 1] > *elemMax)
                *elemMax = conjunto[i - 1];

            if (conjunto[i] < *elemMin)
                *elemMin = conjunto[i];

        }

        else{
            if (conjunto[i] > *elemMax)
                *elemMax = conjunto[i];

            if (conjunto[i - 1] < *elemMin)
                *elemMin = conjunto[i - 1];

        }

        i += 2;

    }

    return 1;

}
