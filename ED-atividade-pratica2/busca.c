#include "busca.h"

int busca_binaria(int array[], int tamanho, int elemento, int *comparacoes){

    int elemMin = 0, elemMax = tamanho - 1;

    while(elemMin <= elemMax){

        *comparacoes += 1;

        int elemCentral = (elemMax + elemMin)/2;

        if(array[elemCentral] == elemento)
            return 1;

        if(array[elemCentral] < elemento)
            elemMin = elemCentral + 1;

        else
            elemMax = elemCentral - 1;

    }

    return 0;

}
