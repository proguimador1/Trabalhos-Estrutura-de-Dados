#include "lista.h"
#include <stdio.h>


int main(){

    tipolista um, dois;

    fazlistavazia(&um);
    fazlistavazia(&dois);

    for(int i = 1; i <= 4; i++)
        insere_lista(&um,i);

    for(int j = 1; j <= 5; j++)
        insere_lista(&dois,j);

    printf("%i", tamanho_lista(&um));

    printf("%i", tamanho_lista(&dois));

    return 0;

}
