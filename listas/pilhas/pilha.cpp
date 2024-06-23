/* fazendo as operações basicas em uma pilha: empilhando (colocando elementos na pilha)
e desempilhando (removendo os elementos de uma pilha)*/

// as operações na pilha são sempre no topo

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *prox;
}celula;

void empilhar(int numero, celula **topo);

int desempilhar(celula **topo);

void imprimir(celula *topo);


int main(){
    celula *topo;
    topo = NULL;
    int n, aux;

    printf("Entre com os valores na pilha: (-1) para sair\n");
    scanf("%d", &n);
    while(n != -1){
        empilhar(n, &topo);

        scanf("%d", &n);
    }

    printf("PILHA:\n");
    imprimir(topo);


    aux = desempilhar(&topo);

    printf("PILHA apos a remocao da chave %d:\n", aux);
    imprimir(topo);

    return 0;

}

void empilhar(int numero, celula **topo){
    // criando um ponteiro para a nova celula
    celula *nova;

    //alocando na memoria essa nova celula
    nova = (celula *) malloc(sizeof(celula));

    if(nova == NULL){
        printf("Erro na alocacao!\n");
        return;
    }

    nova->chave = numero;

    // fazendo o proximo dessa nova celula ser o topo
    nova->prox = *topo;

    // atualizando o topo da pilha
    *topo = nova;

}

int desempilhar(celula **topo){
    // criando uma celula auxiliar
    celula *aux;
    int num;

    // verificando se a pilha esta vazia
    if(*topo == NULL){
        printf("Pilha ja esta vazia!\n");
        return -1;
    }

    // pegando a chave da celula que vai ser removida
    num = (*topo)->chave;

    // guardando o topo atual da lista na celula auxiliar (lembrando que é essa celula que vai ser removida)
    aux = *topo;

    // atualiza o nosso topo
    *topo = (*topo)->prox;

    // desalocando o antigo topo (que foi a celula que foi removida)
    free(aux);

    return num;
}

void imprimir(celula *topo){
    celula *p;

    for(p = topo; p != NULL; p = p->prox){
        printf("%d\n", p->chave);
    }
}