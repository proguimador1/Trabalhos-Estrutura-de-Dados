#include <stdio.h>
#include "conjunto.h"

int main(){

    conjuntoDeInteiros conjunto;

    int elemento1, elemento2;

    fazConjuntoVazio(conjunto);

    insereInteiro(5, conjunto);

    insereInteiro(10, conjunto);

    insereInteiro(20, conjunto);

    printf("imprimindo o conjunto após inserir elementos: \n", pertenceAoConjunto(10, conjunto));

    imprimeConjunto(conjunto);

    removeDoConjunto(10, conjunto);

    printf("Pertence 10 (depois de retirar): %d\n", pertenceAoConjunto(10, conjunto));

    maxDoConjunto(conjunto, &elemento1);

    printf("Max do conjunto: %d\n", elemento1);

    maxMinDoConjunto(&elemento1, &elemento2, conjunto);

    printf("Max do conjunto: %d; Min do conjunto: %d\n", elemento1, elemento2);

    maxMinDoConjunto2(&elemento1, &elemento2, conjunto);

    printf("Par ordenado (Max,Min): (%d,%d)\n", elemento1, elemento2);

    imprimeConjunto(conjunto);

    return 0;

}
