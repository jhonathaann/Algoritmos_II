/* Para imprimir na ordem inversa, basta usar a estrutura "pilha"
porque o último a ser inserido será o primeiro na pilha*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int valor;
    struct cel *proximo;
}celula;

void empilhar(celula **topo, int numero);

void imprime(celula *topo);

int main(){
    celula *pilha = NULL;
    int opc;

    scanf("%d", &opc);

    while(opc >= 0){
        empilhar(&pilha, opc);

        scanf("%d", &opc);
    }

    imprime(pilha);

    return 0;
}

void empilhar(celula **topo, int numero){
    celula *nova = (celula *) malloc(sizeof(celula));

    if(nova == NULL){
        printf("Erro na alocacao!\n");
        return;
    }

    nova->valor = numero;
    nova->proximo = *topo; //proximo dessa nova celula ser o topo
    *topo = nova;     // atualizando o topo da pilha
}

void imprime(celula *topo){
    celula *p;

    for(p = topo; p!= NULL; p = p->proximo){
        printf("%d\n", p->valor);
    }
}

