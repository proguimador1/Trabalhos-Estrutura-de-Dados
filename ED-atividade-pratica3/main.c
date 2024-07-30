#include <stdio.h>
#include "lista.h"


int main(){

    tipolista lista;

    fazlistavazia(&lista);

    for(int i = 1; i <= 32; i*=2)
        insere_lista(&lista, i);


    printf("%i\n", lista.primeiro -> chave); //imprime 32

    busca_e_remove_da_lista(&lista,32);

    printf("%i\n", lista.primeiro -> chave); //imprime 16

    return 0;

}
