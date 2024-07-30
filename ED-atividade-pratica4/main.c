#include "lista.h"
#include <stdio.h>
#define MAX_TAREFAS 100

int main(){
    int n, j, k;

    printf("Digite o número de tarefas: ");
    scanf("%d", &n);

    tipolista entraem[MAX_TAREFAS], saide[MAX_TAREFAS];

    int ordemdesaida[MAX_TAREFAS] = {0};
    int foiprasaida[MAX_TAREFAS] = {0};

    for(int i = 1; i <= n; i++){

        fazlistavazia(&entraem[i]);
        fazlistavazia(&saide[i]);

    }

    printf("Digite os pares (j, k) de pré-requisitos (0 0 para parar):\n");

    while(1){

        scanf("%d %d", &j, &k);

        if (j == 0 && k == 0)
            break;

        insere_lista(&entraem[k], j);

        insere_lista(&saide[j], k);

    }

    for(int i = 1; i <= n; i++){
        //inserir aqui código já refinado
        int w = 0;

        for(int z = 1; z <= n; z++){

            if(entraem[z] == NULL && !foiprasaida[z]){

                w = z;
                break;

            }

        }

        // a tarefa w já foi escolhida. Nada entra nela.

        // Remove as setas de w para outras tarefas, ou seja,
        // para cada seta que sai de w para uma outra tarefa t,
        // remove t da lista de saída de w e
        // remove w da lista de entrada em t:

        while(tamanho_lista(&saide[w]) > 0){

            int t;

            remove_primeiro_da_lista(&saide[w], &t);

            busca_e_remove_da_lista(&entraem[t], w);

            if(!tamanho_lista(&entraem[t]))
                fazlistavazia(&entraem[t]);

        }

        // inserir aqui código já refinado

        ordemdesaida[i] = w;
        foiprasaida[w] = 1;


    }

    printf("Ordem de saída das tarefas:\n");

    for (int i = 1; i <= n; i++)
        printf("%d ", ordemdesaida[i]);


    printf("\n");

    return 0;

}
