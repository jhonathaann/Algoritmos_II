#include <stdio.h>
#include  <stdlib.h>

typedef struct cel{
    int numero;
    struct cel *prox;
}celula;

void insere_inicio(celula **lista, int numero);

void imprime(celula *lista);

void busca_par(celula **lista);

celula* remove_par(celula **lista, int par);

int main(){
    celula *lista = NULL;
    
    int numero;

    scanf("%d", &numero);

    while(numero != -1){

        insere_inicio(&lista, numero);

        scanf("%d", &numero);
    }
    printf("LISTA ORIGINAL:\n");
    imprime(lista);

    printf("\nLISTA CONTENDO APENAS OS PARES:\n");
    busca_par(&lista);
    imprime(lista);

    return 0;
}

void insere_inicio(celula **lista, int numero){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao insere_inicio!\n");
        return;
    }
    
   nova->numero = numero;
   nova->prox = *lista;
   *lista = nova;
}

celula* remove_par(celula **lista, int par){
    celula *aux, *no_removido = NULL;

    if(*lista == NULL){
        printf("Lista esta vazia!\n");
        return no_removido;
    }

    // verificando se o numero a ser removido esta na primeira celula
    if((*lista)->numero == par){
        no_removido = *lista;
        *lista = no_removido->prox;
    }else{
        aux = *lista;

        while(aux->prox != NULL && aux->prox->numero != par){
            aux = aux->prox;
        }

        if(aux->prox != NULL){
            no_removido = aux->prox;
            aux->prox = aux->prox->prox;  // aux->prox =  no_removido->prox
        }
    }

    return no_removido;
}

void busca_par(celula **lista){
    celula *p;

    for(p = *lista; p != NULL; p = p->prox){
        if((p->numero) % 2 == 0){
            remove_par(lista, p->numero);
        }
    }
}

void imprime(celula *lista){
    celula *p;

    for(p = lista; p != NULL; p = p->prox){
        printf("%d ", p->numero);
    }
}