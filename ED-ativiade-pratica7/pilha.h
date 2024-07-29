typedef int tipoElemento;

typedef struct celula{

    tipoElemento chave;

    struct celula* prox;

}Celula;

typedef struct TipoPilha{

    int tamanho;

    Celula* topo;

};

void faz_pilha_vazia(TipoPilha* pilha);
int empilha(TipoPilha* pilha, tipoElemento elemen);
int desempilha(TipoPilha* pilha, tipoElemento* elemen);
void imprime_pilha(TipoPilha* pilha);
int tamanhopilha(TipoPilha* pilha);
