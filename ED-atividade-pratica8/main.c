#include <stdio.h>
#include "TipoFP.h"

void main() {
    TipoFP fp;
    TipoRegistro reg;

    criaFP(&fp);

    reg.chave = 20;
    insereFP(reg, &fp);

    reg.chave = 10;
    insereFP(reg, &fp);

    reg.chave = 30;
    insereFP(reg, &fp);

    reg.chave = 15;
    insereFP(reg, &fp);

    reg.chave = 25;
    insereFP(reg, &fp);

    printf("Fila de prioridades (ordem decrescente): ");
    imprimeFP(&fp);
    printf("\n");

    retiramax(&reg,&fp);

    printf("Elemento removido com a maior chave: %i\n", reg.chave);

    apagaFP(&fp);

    if(fp==NULL)
        printf("Fila de prioridades pagada.");

}
